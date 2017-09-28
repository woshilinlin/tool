#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <opencv2/core/core.hpp>

#include "imagelabel.h"
#include "labelscroll.h"
#include "pointinfowidget.h"
#include "pointInfolistwidget.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The CameraStatus enum 摄像头状态信息
 */
enum CameraStatus
{
    STOP = 0,
    START,
    RUNNING
};

/*!
 * \brief The CoordinateGradation enum 坐标存储顺序
 */
enum CoordinateGradation
{
    XAXIS,
    YAXIS
};

/*!
 * \brief The CameraConfig struct  摄像头配置结构体
 */
struct CameraConfig{
    qint32 port;
    qint32 delay;
    QString ip;
    QString username;
    QString password;
    QString xmlfile;
    double threshold;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /*!
     * \brief getCameraConfig 获取摄像头的配置信息
     * \return 摄像头配置信息
     */
    CameraConfig getCameraConfig() const;

    /*!
     * \brief getStatus 获取窗口状态信息
     * \return 窗口状态信息
     */
    CameraStatus getCameraStatus() const;

    /*!
     * \brief setStatus 设置窗口状态
     * \param status 要设置的窗口状态
     */
    void setCameraStatus(CameraStatus status);

    /*!
     * \brief showCapturedImage 显示摄像头拍照的图片
     * \param image 要显示的图片
     */
    void showCapturedImage(QImage &image);

private:
    /*!
     * \brief setScrollArea 设置滚动区域
     */
    void initScrollArea();

    /*!
     * \brief addPointLabel 添加点标签
     */
    void initStatusBar();

    /*!
     * \brief setDockWidget 设置锚窗口
     */
    void initDockWidget();

    /*!
     * \brief createJson 创建json数据
     */
    void createJson();

    /*!
     * \brief event 重写总事件函数
     * \param e 事件
     * \return 如果事件e被识别和处理，则返回true
     */
    bool event(QEvent *e);

signals:
    void sendImage(const QImage &);
    void sendPoint(const QPoint &);

public slots:
    /*!
     * \brief receiveMat 接收cv:Mat图片
     * \param mat 要接收的cv:Mat图片
     */
    void receiveMat(const cv::Mat &mat);

private slots:
    /*!
     * \brief saveFile 保存文件
     * \return 保存成功返回true
     */
    bool saveFile();

    /*!
     * \brief startButton 点击开始按钮槽函数
     */
    void cameraStartButton();

    /*!
     * \brief removePointInfo　删除点前所在的行
     * \param row 当前行
     */
    void removePointInfo(int row);

    /*!
     * \brief pointInfo 添加点信息
     * \param text 点的名字
     */
    void pointInfo(const QString &text);

    /*!
     * \brief receivePress 接收鼠标左键按压的点
     * \param Point 要接收的点
     */
    void receivePress(const QPoint &Point);

private:
    Ui::MainWindow *ui;

    int image_height_; //摄像头图片的高

    ImageLabel * image_label_; //图片标签
    LabelScroll * label_scrollarea_; //标签滚动区域
    PointInfoListWidget * pointinfo_listwidget_; //点信息列表
    CameraStatus camera_status_ = STOP;

    QLabel * x_value_label_; //显示鼠标悬停点x值的标签
    QLabel * y_value_label_; //显示鼠标悬停点y值的标签
    QJsonDocument pointinfo_document_; //点信息的json文件
    QList<PointInfowidget *> pointinfo_list_; //点所有信息列表
};

#endif // MAINWINDOW_H
