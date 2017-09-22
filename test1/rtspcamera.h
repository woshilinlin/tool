#ifndef RTSPCAMERA_H
#define RTSPCAMERA_H

#include "abstractcamera.h"
#include <opencv2/opencv.hpp>

#include <QImage>

class RTSPCamera : public QObject
{
    Q_OBJECT

public:
    RTSPCamera(const QString & rtspUrl);

    void doCapture();

	QSize frameSize();

public slots:

	bool vInit();
	void vRelease();

    cv::Mat doCaptures();
private slots:

signals:
    void emitIamage(const cv::Mat &);
    void capture();

private:
	cv::VideoCapture _camera;
	QString _rtspUrl = QString::null;
    QImage _lastCapturedImage;
	QSize _frameSize;
};

#endif // RTSPCAMERA_H
