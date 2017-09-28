#include "rtspcamera.h"

#include <QImage>

#include "imagetools.h"

RTSPCamera::RTSPCamera(const QString &rtsp_url)
{
    _rtsp_url = rtsp_url;
    connect(this, SIGNAL(capture()), this, SLOT(doCaptures()), Qt::QueuedConnection);
}

void RTSPCamera::doCapture()
{
    emit capture();
}

cv::Mat RTSPCamera::doCaptures()
{
    cv::Mat original_frame;

    _camera.read(original_frame);

    if(original_frame.cols == 0 || original_frame.rows == 0){
		qCritical("Null Image");
        return cv::Mat();
	}

	cv::Mat frame;

    try
    {
        cv::cvtColor(original_frame, frame, CV_BGR2RGB);
	}
	catch(cv::Exception e){
		qCritical("OpenCV exception.");
	}
    emit sendIamage(frame);
    return frame;
}

QSize RTSPCamera::frameSize()
{
	return _frameSize;
}

bool RTSPCamera::vInit()
{
    bool opened = _camera.open(_rtsp_url.toStdString());

    if(opened){
		qint32 width = _camera.get(CV_CAP_PROP_FRAME_WIDTH);
		qint32 height = _camera.get(CV_CAP_PROP_FRAME_HEIGHT);
		qDebug("RTSP Camera opened: %d x %d", width, height);
		_frameSize = QSize(width, height);
	}

    return opened;
}

void RTSPCamera::vRelease()
{
	_camera.release();
}
