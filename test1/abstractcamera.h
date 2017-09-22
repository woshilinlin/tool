#ifndef ABSTRACTCAMERA_H
#define ABSTRACTCAMERA_H

#include "abstractdevice.h"
#include <QRect>

class QRect;
///
/// \brief 摄像头接口
///
class AbstractCamera : public AbstractDevice
{
	Q_OBJECT

public:
	AbstractCamera();

	QImage capture();

	virtual QImage doCapture() = 0;
	///
	/// \brief setExposureTime 设置相机曝光时间
	///
	virtual void setExposure(qint32 exposureTimeUs);
	///
	/// \brief exposureTime
	/// \return 相机当前的曝光时间
	///

	virtual QSize frameSize();

	virtual qint32 exposureValue();

	bool isAutoExposureROIEnabled() const;
	void setIsAutoExposureROIEnabled(bool isAutoExposureROIEnabled);

	QRect autoExposureROIRect() const;
	void setAutoExposureROIRect(const QRect &autoExposureROIRect);

	qint32 maxExposure() const;
	void setMaxExposure(const qint32 &maxExposure);

	qint32 minExposure() const;
	void setMinExposure(const qint32 &minExposure);

	qint32 targetBrightness() const;
	void setTargetBrightness(const qint32 &targetBrightness);

	double exposureError() const;
	void setExposureError(double exposureError);

	double exposureStep() const;
	void setExposureStep(double exposureStep);

	void rotate(QImage &image);

private:
	void doAutoExposureROI(qint32 targetBrightness, qint32 curBrightness, double exposureStep,
						   qint32 maxExposure, qint32 minExposure, double exposureError);

	qint32 calculateBrightness(const QImage &image, const QRect &rectOfInterest, qint32 pixelPerLine);

private:
	bool _isAutoExposureROIEnabled = false;
	QRect _autoExposureROIRect;
	qint32 _maxExposure, _minExposure;
	double _exposureStep = 0;
	double _exposureError;
	qint32 _targetBrightness;
};

#endif // ABSTRACTCAMERA_H
