#include <QDebug>
#include <QtTest>
#include <QMessageBox>
#include <QApplication>

#include "mainwindow.h"
#include "rtspcamera.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>("cv::Mat"); //注册cv::Mat数据类型

    QApplication a(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();

    RTSPCamera * rtspcamera = NULL;
    CameraConfig cameraconfig; //摄像头配置

    QThread camerathread; //摄像头线程
    camerathread.start();

    while (1)
    {
        qApp->processEvents();
        cameraconfig = mainwindow.getCameraConfig();
        if (mainwindow.getCameraStatus() == START)
        {
            if (rtspcamera == NULL)
            {
                QString url = QString("rtsp://%1:%2@%3/h264/ch1/%4/av_stream").
                        arg(cameraconfig.username).arg(cameraconfig.password).
                        arg(cameraconfig.ip).arg("main");

                rtspcamera = new RTSPCamera(url);
                rtspcamera->moveToThread(&camerathread);
                QObject::connect(rtspcamera, SIGNAL(sendIamage(cv::Mat)), &mainwindow, SLOT(receiveMat(cv::Mat)),
                                 Qt::QueuedConnection);
            }

            bool cameinit = rtspcamera->vInit();
            if (!cameinit)
            {
                QMessageBox::warning(NULL, "camera error", "connect failed");
                mainwindow.setCameraStatus(STOP);
                continue;
            }

            mainwindow.setCameraStatus(RUNNING);
            QTest::qWait(500);
        }

        if (mainwindow.getCameraStatus() == RUNNING)
        {
            rtspcamera->doCapture();
        }

        if (!mainwindow.isVisible())
        {
            exit(0);
        }

    }
    return a.exec();
}
