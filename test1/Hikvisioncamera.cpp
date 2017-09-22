#include "Hikvisioncamera.h"
#include "Imagetools.h"

#include <QMutexLocker>
#include <QDebug>

LONG port = -1;
HWND hWnd = 0;

Hikvisioncamera::Hikvisioncamera(const QString &ip, qint32 ports, const QString &username, const QString &password):
                                _ip(ip), _port(ports), _username(username), _password(password)
{

}

cv::Mat YV12_to_RGB24_CVMAT(void *pYV12, int width, int height)
{
    if (width < 1 || height < 1 || pYV12 == NULL)
        return cv::Mat();
    cv::Mat dst(height, width, CV_8UC3);
    cv::Mat src(height + height / 2, width, CV_8UC1, pYV12);

    cv::cvtColor(src, dst, CV_YUV2RGB_YV12);

    return dst;
}

void CALLBACK hkDecode(int nPort,char * pBuf,int nSize,FRAME_INFO * pFrameInfo, void *pUser,int nReserved2)
{
    int frameType = pFrameInfo->nType;
    qint32 width = pFrameInfo->nWidth;
    qint32 height = pFrameInfo->nHeight;

    if(frameType == T_YV12){
        cv::Mat mat = YV12_to_RGB24_CVMAT(pBuf, width, height);
        ((Hikvisioncamera*)pUser)->setNewMat(mat);
    }
}

void CALLBACK hkExceptionCallBack(DWORD dwType, LONG userId, LONG handle, void *pUser)
{
    switch(dwType)
    {
        case EXCEPTION_RECONNECT:    //预览时重连
            qWarning("Hikvision Camera: Lost signal and try reconnecting ...");
            break;
        case EXCEPTION_RELOGIN:
            qDebug("Hikvision Camera: Try to relogin ...");
            break;
        case RELOGIN_SUCCESS:
            qDebug("Hikvision Camera: Relogin success ...");
            break;
        case PREVIEW_RECONNECTSUCCESS:
            qDebug("Hikvision Camera: Reconnect success ...");
            break;
        default:
            qWarning("Hikvision Camera Exception: type %d", dwType);
            break;
    }
}

void CALLBACK hkRealPlayCallBack(LONG realHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser)
{
    DWORD ret;

    switch (dwDataType) {
        case NET_DVR_SYSHEAD:
            if(!PlayM4_GetPort(&port)){
                break;
            }
            if(dwBufSize > 0){
                if(!PlayM4_OpenStream(port, pBuffer, dwBufSize, 1024*1024)){
                    ret = PlayM4_GetLastError(port);
                    break;
                }
                if(!PlayM4_SetDecCallBackMend(port, hkDecode, pUser)){
                    ret = PlayM4_GetLastError(port);
                    break;
                }
                if(!PlayM4_Play(port, hWnd)){
                    ret = PlayM4_GetLastError(port);
                    break;
                }
            }
            break;
        case NET_DVR_STREAMDATA:
            if(dwBufSize > 0  &&  port != -1){
                if(!PlayM4_InputData(port, pBuffer, dwBufSize)){
                    qWarning("stream error");
                    break;
                }
            }
            break;
        default:
            break;
    }
}

bool Hikvisioncamera::init()
{
    _refreshed = false;

    NET_DVR_Init();
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);

    _userId = NET_DVR_Login_V30(_ip.toLocal8Bit().data(),
                                _port,
                                _username.toLocal8Bit().data(),
                                _password.toLocal8Bit().data(),
                                &_cameraInfo);
    if(_userId < 0){
        qWarning("Hikvision Camera login error: %d - %s",
                                  NET_DVR_GetLastError(), NET_DVR_GetErrorMsg());
        NET_DVR_Cleanup();
        return false;
    }

    NET_DVR_SetExceptionCallBack_V30(0, NULL, hkExceptionCallBack, this);

    NET_DVR_PREVIEWINFO playInfo;
    memset(&playInfo, 0, sizeof(playInfo));
    playInfo.lChannel = 1;
    playInfo.dwStreamType = 0;
    playInfo.dwLinkMode = 0;

    LONG realPlayHandle = NET_DVR_RealPlay_V40(_userId, &playInfo, hkRealPlayCallBack, this);
    if(realPlayHandle < 0){
        qWarning("Hikvision Camera NET_DVR_RealPlay_V40 error: %d - %s",
                                  NET_DVR_GetLastError(), NET_DVR_GetErrorMsg());
        NET_DVR_Cleanup();
        return false;
    }

    return true;
}

void Hikvisioncamera::release()
{
    NET_DVR_Cleanup();
}

cv::Mat Hikvisioncamera::doCapture(qint32 imageIndexOffset)
{
    QMutexLocker locker(&_mutexCapture);
    if(_matList.size() < imageIndexOffset + 1){
        return cv::Mat();
    }
    return _matList.at(_matList.size() - 1 - imageIndexOffset);
}

void Hikvisioncamera::setNewMat(const cv::Mat &newMat)
{
    QMutexLocker locker(&_mutexCapture);
    if(!newMat.empty()){
        _matList.push_back(newMat);
    }
    if(_matList.size() > IMAGE_BUFFER_SIZE){
        _matList.pop_front();
    }
}
