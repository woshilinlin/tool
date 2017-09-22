#include "abstractcamera.h"
#include <QImage>
#include <QDebug>
#include <QDateTime>

AbstractCamera::AbstractCamera() :
	AbstractDevice(DEVICE_CAMERA)
{

}

QImage AbstractCamera::capture()
{
	static QDateTime lastExposureTime = QDateTime::currentDateTime();
	QImage image = this->doCapture();
	rotate(image);
	if(!image.isNull()
		&& _isAutoExposureROIEnabled && !_autoExposureROIRect.isNull()
		&& lastExposureTime.msecsTo(QDateTime::currentDateTime()) > 400){
		qint32 curBrightness = calculateBrightness(image, _autoExposureROIRect, 60);
		doAutoExposureROI(_targetBrightness, curBrightness, _exposureStep, _maxExposure, _minExposure, _exposureError);
		lastExposureTime = QDateTime::currentDateTime();
	}

	return image;
}

void AbstractCamera::setExposure(qint32 exposureTimeUs)
{

}

QSize AbstractCamera::frameSize()
{
	return QSize(0, 0);
}

qint32 AbstractCamera::exposureValue()
{
	return -1;
}

bool AbstractCamera::isAutoExposureROIEnabled() const
{
	return _isAutoExposureROIEnabled;
}

void AbstractCamera::setIsAutoExposureROIEnabled(bool isAutoExposureROIEnabled)
{
	_isAutoExposureROIEnabled = isAutoExposureROIEnabled;
}

QRect AbstractCamera::autoExposureROIRect() const
{
	return _autoExposureROIRect;
}

void AbstractCamera::setAutoExposureROIRect(const QRect &autoExposureROIRect)
{
	if(autoExposureROIRect.isNull()){
		_autoExposureROIRect = QRect({0, 0}, this->frameSize());
	}
	else{
		_autoExposureROIRect = autoExposureROIRect;
	}
}

qint32 AbstractCamera::maxExposure() const
{
	return _maxExposure;
}

void AbstractCamera::setMaxExposure(const qint32 &maxExposure)
{
	_maxExposure = maxExposure;
}

qint32 AbstractCamera::minExposure() const
{
	return _minExposure;
}

void AbstractCamera::setMinExposure(const qint32 &minExposure)
{
	_minExposure = minExposure;
}

qint32 AbstractCamera::targetBrightness() const
{
	return _targetBrightness;
}

void AbstractCamera::setTargetBrightness(const qint32 &targetBrightness)
{
	_targetBrightness = targetBrightness;
}

void AbstractCamera::doAutoExposureROI(qint32 targetBrightness, qint32 currentBrightness, double exposureStep, qint32 maxExposure, qint32 minExposure, double exposureError)
{
	qint32 diff = currentBrightness - targetBrightness;

	qint32 oldExposure = this->exposureValue();

	if(oldExposure == -1){
		return;
	}

	qint32 newExposure = oldExposure;

//	if(diff > (targetBrightness * exposureError)){
//		int target = oldExposure * (1.0 - exposureStep);
//		if(target > minExposure){
//			newExposure = target - (newExposure == oldExposure);
//		}
//		else{
//			newExposure = minExposure;
//		}
//	}
//	else if(diff < (-targetBrightness * exposureError)){
//		int target = oldExposure * (1.0 + exposureStep);
//		if(target < maxExposure){
//			newExposure = target + (newExposure == oldExposure);
//		}
//		else{
//			newExposure = maxExposure;
//		}
//	}

	if(currentBrightness > 0
			&& (qAbs(diff) > targetBrightness * exposureError)){
		newExposure = oldExposure * targetBrightness / currentBrightness;
	}
	newExposure = newExposure > maxExposure ? maxExposure : newExposure;
	newExposure = newExposure < minExposure ? minExposure : newExposure;

	if(newExposure!= oldExposure){
		this->setExposure(newExposure);
//		emit signalExposureChanged(newExposure);
		qDebug() << "cbr = " << currentBrightness << "diff = " << diff << "old = " << oldExposure;
		qDebug("Camera exposure set to %d", newExposure);
	}
}

qint32 AbstractCamera::calculateBrightness(const QImage &image, const QRect &rectOfInterest, qint32 pixelPerLine)
{
	if(rectOfInterest.isNull()){
		return 0;
	}
	qint64 sum = 0;
	int brightness, count = 0;

	for(int i = rectOfInterest.top(); i < rectOfInterest.bottom(); i += rectOfInterest.height() / pixelPerLine){
		const uchar *pline = image.constScanLine(i);
		for(int j = rectOfInterest.left() * 3; j < rectOfInterest.right() * 3; j += rectOfInterest.width() / pixelPerLine){
			sum += (pline[j] + pline[j+1] + pline[j+2]) / 3;
			count++;
		}
	}

	brightness = sum / count;
	return brightness;
}

double AbstractCamera::exposureStep() const
{
	return _exposureStep;
}

void AbstractCamera::setExposureStep(double exposureStep)
{
	_exposureStep = exposureStep;
}

void AbstractCamera::rotate(QImage &image)
{
//	QMatrix rotateMatrix;
//	rotateMatrix.rotate(360 - Config::instance()->valueInt("摄像头", "旋转"));
//	image = image.transformed(rotateMatrix);
}

double AbstractCamera::exposureError() const
{
	return _exposureError;
}

void AbstractCamera::setExposureError(double exposureError)
{
	_exposureError = exposureError;
}
