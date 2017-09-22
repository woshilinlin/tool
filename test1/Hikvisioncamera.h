#ifndef HIKVISIONCAMERA_H
#define HIKVISIONCAMERA_H

#include "hikvision/HCNetSDK.h"
#include "hikvision/LinuxPlayM4.h"
#include "hikvision/PlayM4.h"

#include <QMutex>
#include <opencv2/opencv.hpp>
#include <QImage>

#define IMAGE_BUFFER_SIZE 100


class Hikvisioncamera
{
public:
    Hikvisioncamera(const QString &ip, qint32 ports,
                    const QString &username, const QString &password);

    bool init();
    void release();

    cv::Mat doCapture(qint32 imageIndexOffset = 0);

    void setNewMat(const cv::Mat &lastMat);

private:
    QString _ip;
    quint16 _port;
    QString _username;
    QString _password;

    QList<cv::Mat> _matList;
    bool _refreshed = false;
    bool _isOk = false;

    LONG _userId;
    NET_DVR_DEVICEINFO_V30 _cameraInfo;
    QMutex _mutexCapture;
};

#endif // HIKVISIONCAMERA_H
