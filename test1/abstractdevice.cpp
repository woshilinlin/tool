#include "abstractdevice.h"
//#include "logger.h"
#include <QDebug>

AbstractDevice::AbstractDevice(DEVICE_TYPE type, QObject *parent) :
	QObject(parent), _type(type)
{
}

void AbstractDevice::hookBeforeInit()
{
	qDebug() << QString("初始化: ") + typeString();
}

void AbstractDevice::hookAfterInit()
{
	if(_isDeviceOk){
		qDebug() << QString("初始化: ") + typeString() + QString(" 成功");
	}
	else{
		qWarning() << QString("初始化: ") + typeString() + QString(" 失败");
	}
}

void AbstractDevice::hookBeforeRelease()
{
	qDebug() << QString("释放资源: ") + typeString();
}

void AbstractDevice::hookAfterRelease()
{
//	qDebug(QString("释放资源: ") + typeString() + QString(" 完成"));
}

bool AbstractDevice::isDeviceOk() const
{
    return _isDeviceOk;
}

void AbstractDevice::setIsDeviceOk(bool isDeviceOk)
{
	_isDeviceOk = isDeviceOk;
}

QString AbstractDevice::errorString() const
{
	return _errorString;
}

void AbstractDevice::init()
{
	hookBeforeInit();

	_isDeviceOk = vInit();

	hookAfterInit();
}

void AbstractDevice::release()
{
	hookBeforeRelease();

	vRelease();

	_isDeviceOk = false;

	hookAfterRelease();
}

DEVICE_TYPE AbstractDevice::type() const
{
	return _type;
}

QString AbstractDevice::typeString() const
{
	QString typeStr = QString::null;

	switch (_type) {
		case DEVICE_CAMERA:
			typeStr = "摄像头";
			break;
		case DEVICE_CARDREADER:
			typeStr = "读卡器";
			break;
		case DEVICE_ATTENDSERVER:
			typeStr = "考勤服务";
			break;
		case DEVICE_FACESERVER:
			typeStr = "人脸识别服务";
			break;
		case DEVICE_LEDSCREEN:
			typeStr = "LED显示屏";
			break;
		case DEVICE_INFRAREDS:
			typeStr = "红外";
			break;
		default:
			typeStr = "未知设备";
			break;
	}

	return typeStr;
}

