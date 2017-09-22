#include "rtspcamera.h"
#include "Imagetools.h"

#include <QImage>
#include <QTest>

RTSPCamera::RTSPCamera(const QString &rtspUrl)
{
    _rtspUrl = rtspUrl;
    connect(this, SIGNAL(capture()), this, SLOT(doCaptures()), Qt::QueuedConnection);
}

void RTSPCamera::doCapture()
{
    emit capture();
}

cv::Mat RTSPCamera::doCaptures()
{
	cv::Mat originalFrame;

	_camera.read(originalFrame);

	if(originalFrame.cols == 0 || originalFrame.rows == 0){
		qCritical("Null Image");
        return cv::Mat();
	}

	cv::Mat frame;

    try
    {
		cv::cvtColor(originalFrame, frame, CV_BGR2RGB);
	}
	catch(cv::Exception e){
		qCritical("OpenCV exception.");
	}
    emit emitIamage(frame);
    return frame;
}

QSize RTSPCamera::frameSize()
{
	return _frameSize;
}

bool RTSPCamera::vInit()
{
	bool isOpened = _camera.open(_rtspUrl.toStdString());

	if(isOpened){
		qint32 width = _camera.get(CV_CAP_PROP_FRAME_WIDTH);
		qint32 height = _camera.get(CV_CAP_PROP_FRAME_HEIGHT);
		qDebug("RTSP Camera opened: %d x %d", width, height);
		_frameSize = QSize(width, height);
	}

	return isOpened;
}

void RTSPCamera::vRelease()
{
	_camera.release();
}
