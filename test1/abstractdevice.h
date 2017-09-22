#ifndef ABSTRACTDEVICE_H
#define ABSTRACTDEVICE_H

#include <QObject>


enum DEVICE_TYPE{
    DEVICE_ALL = 0,
    DEVICE_CAMERA,
    DEVICE_CARDREADER,
    DEVICE_INFRAREDS,
    DEVICE_ATTENDSERVER,
    DEVICE_FACESERVER,
    DEVICE_HGEM,
    DEVICE_LEDSCREEN
};

enum DEVICE_STATUS{
    DEVICE_STATUS_INIT = 0,
    DEVICE_STATUS_OK
};

enum TRIGGER_STATE{
    TRIGGER_STATE_IDLE = 0,
    TRIGGER_STATE_PEND, //等待处理
    TRIGGER_STATE_PROC, //正在处理
    TRIGGER_STATE_QUITENTER,
    TRIGGER_STATE_QUITEXIT
};

///
/// \brief 抽象设备接口，init,release,checkStatus等
///
class AbstractDevice : public QObject
{
	Q_OBJECT

public:
	AbstractDevice(DEVICE_TYPE type, QObject *parent = 0);

	DEVICE_TYPE type() const;
	QString typeString() const;

	QString errorString() const;

	bool isDeviceOk() const;
	void setIsDeviceOk(bool isDeviceOk);

	void init();
	void release();

protected:
	virtual bool vInit() = 0;
	virtual void vRelease() = 0;

	virtual void hookBeforeInit();
	virtual void hookAfterInit();
	virtual void hookBeforeRelease();
	virtual void hookAfterRelease();

protected:
	DEVICE_TYPE _type;
	QString _errorString;

private:
	bool _isDeviceOk = false;
};

#endif // ABSTRACTDEVICE_H
