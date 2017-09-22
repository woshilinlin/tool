#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Scroll.h"

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonDocument>
#include <opencv2/core/core.hpp>

struct point;
class PointInfo;
class QVBoxLayout;
class QTableView;
class QListWidget;
class MyListWidget;
class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class QScrollBar;

enum STATE
{
    STOP = 0,
    START,
    RUNNING
};

enum labelPoint
{
    xAxis,
    yAxis
};


struct CameraConfig{
    QString ip;
    qint32 port;
    QString username;
    QString password;
    qint32 delay;
    QString xmlFile;
    double threshold;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CameraConfig getCameraConfig();

    int state();
    int changeState();
    void setState(STATE state);
    void showCapturedImage(QImage &image);

private:
    void setScrollArea();
    void addPointLabel();
    void setDockWidget();
    void createJson();

    bool event(QEvent *event);

signals:
    void sendImage(const QImage &);
    void sendPoint(const QPoint &);
    void sendMatToImage(QImage);

public slots:
    void receiveMat(const cv::Mat &mat);

private slots:
    void pointInfo(const QString &text);
    void startButton();
    void removePointInfo(int row);

    bool saveFile();
    void receivePress(const QPoint &point);

private:
    Ui::MainWindow *ui;

    int PIXHEIGHT;

    Label * lab;
    Scroll * scr;
    QLabel * xLabel;
    QLabel * yLabel;
    MyListWidget * listWidget;

    STATE sta = STOP;
    QJsonObject json;
    QJsonDocument document;
    QList<point> pList;
    QList<PointInfo *> pointInfoList;
    QList<QListWidgetItem *> itemList;

    QPoint pressPoint;
};

#endif // MAINWINDOW_H
