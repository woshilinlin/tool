#include "mainwindow.h"
#include "Imagetools.h"
#include "rtspcamera.h"

#include <QDebug>
#include <QtTest>
#include <QMessageBox>
#include <QApplication>


int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    RTSPCamera * rtspCamera = NULL;
    CameraConfig cameraConfig;

    QThread cameraThread;
    cameraThread.start();

    QApplication::processEvents();

    while (1)
    {
        qApp->processEvents();
        cameraConfig = w.getCameraConfig();
        if (w.state() == START)
        {
            if (rtspCamera == NULL)
            {
                QString url = QString("rtsp://%1:%2@%3/h264/ch1/%4/av_stream").arg(cameraConfig.username).arg(cameraConfig.password).arg(cameraConfig.ip).arg("main");
                rtspCamera = new RTSPCamera(url);
                rtspCamera->moveToThread(&cameraThread);
                QObject::connect(rtspCamera, SIGNAL(emitIamage(cv::Mat)), &w, SLOT(receiveMat(cv::Mat)), Qt::QueuedConnection);
            }

            bool cameInit = rtspCamera->vInit();
            if (!cameInit)
            {
                QMessageBox::warning(NULL, "camera error", "connect failed");
                w.setState(STOP);
                continue;
            }

            w.setState(RUNNING);
            QTest::qWait(500);
        }

        if (w.state() == RUNNING)
        {
            rtspCamera->doCapture();
//            cv::Mat matShow = rtspCamera->doCaptures();

//            if (matShow.empty())
//            {
//                continue;
//            }
//            QImage image = Imagetools::cvMat2QImage(matShow);
//            w.showCapturedImage(image);
        }

        if (!w.isVisible())
        {
            exit(0);
        }

    }
    return a.exec();
}
