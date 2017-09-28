#ifndef RTSPCAMERA_H
#define RTSPCAMERA_H

#include <opencv2/opencv.hpp>

#include <QImage>

class RTSPCamera : public QObject
{
    Q_OBJECT

public:

    /*!
     * \brief RTSPCamera rtsp协议摄像头
     * \param rtspUrl url路径
     */
    RTSPCamera(const QString & rtsp_url);

    /*!
     * \brief doCapture 拍照
     */
    void doCapture();

    /*!
     * \brief frameSize 图片大小
     * \return 返回图片大小
     */
	QSize frameSize();

public slots:

    /*!
     * \brief vInit 初始化摄像头
     * \return 初始化成功返回true
     */
	bool vInit();

    /*!
     * \brief vRelease 释放资源
     */
	void vRelease();

    /*!
     * \brief doCaptures 获取图片的槽函数
     * \return cv::Mat格式的图片
     */
    cv::Mat doCaptures();

signals:

    /*!
     * \brief sendIamage 发送图片信号
     */
    void sendIamage(const cv::Mat &);

    /*!
     * \brief capture 拍照信号
     */
    void capture();

private:
	cv::VideoCapture _camera;
    QString _rtsp_url = QString::null;
    QImage _lastCapturedImage;
	QSize _frameSize;
};

#endif // RTSPCAMERA_H
