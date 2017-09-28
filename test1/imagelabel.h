#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QTimer>

/*!
 * \brief The ImageLabel class
 */
class ImageLabel : public QLabel
{
    Q_OBJECT

public:
    ImageLabel();

signals:
    /*!
     * \brief horScollBarChange 水平滚动条值改变
     */
    void horScrollBarChange(double);

    /*!
     * \brief verScrollBarChange 垂直滚动条值改变
     */
    void verScrollBarChange(double, int);

    /*!
     * \brief pixMapUpdate 像素图更新信号
     */
    void pixMapUpdate();

    /*!
     * \brief wheelRolling 滚轮滚动信号
     */
    void wheelRolling();

    /*!
     * \brief pressPionts 发送点击左键得到的点
     */
    void leftPressPionts(QPoint);

    /*!
     * \brief sendNewPointName 发送新得到点的名字
     */
    void sendNewPointName(const QString &);

public slots:
    /*!
     * \brief showPixmap 显示图片
     * \param pixMap 所要显示的像素图
     */
    void showPixmap(const QPixmap & pixmap);

    /*!
     * \brief showPixmap 显示图片
     * \param filePath 图片路径
     */
    void showPixmap(const QString & filepath);

    /*!
     * \brief removePoint 删除点(包括二维坐标和名字)
     * \param position 所要删除的位置
     */
    void removePoint(int position);

private slots:
    /*!
     * \brief longPress 长按鼠标左键，响应计时器超时的槽函数
     */
    void longPress();

    /*!
      * \brief setScalePixmap 更新缩放的像素图
      */
     void setScalePixmap();

    /*!
     * \brief receiveImage 接收摄像头获取的图片
     * \param images 接收到的图片
     */
    void receiveImage(const QImage & images);

    /*!
     * \brief pointTimeOut 左键长按得到点的超时槽函数
     */
    void pointTimerOut();

private:
    /*!
     * \brief wheelEvent 滚轮滚动事件
     * \param event
     */
    void wheelEvent(QWheelEvent *event);

    /*!
     * \brief mousePressEvent 鼠标按压事件
     * \param event
     */
    void mousePressEvent(QMouseEvent *event);

    /*!
     * \brief mouseReleaseEvent 鼠标释放事件
     * \param event
     */
    void mouseReleaseEvent(QMouseEvent *event);

    /*!
     * \brief zoomIn 放大图片的倍数
     */
    void zoomIn();

    /*!
     * \brief zoomOut 缩小图片的倍数
     */
    void zoomOut();

    /*!
     * \brief scaleImage 缩放图片
     */
    void scaleImage();

    /*!
     * \brief drawAllPoint 画所有标记的点
     */
    void drawAllPoint();

    /*!
     * \brief addPointNum 增加点的数量，增量为１；
     */
    void addPointNumber();

    /*!
     * \brief savePoint 保存点的信息
     * \param point 要保存的点
     */
    void savePoint(const QPoint &point);

    /*!
     * \brief drawPoint 在label上画点
     * \param point 点的坐标
     * \param text 点的名字
     */
    void drawPoint(const QPoint &point, const QString &text);

private:
    int point_number_; //点的数量
    double zoom_multiple_; //实际缩放倍数

    QImage image_; //摄像头生成的图片
    QTimer point_timer_; //点计时器
    QTimer left_longpress_timer_; //左键长按计时器
    QPoint left_press_point_; //长按鼠标左键起始点
    QPixmap pixmap_; //像素图
    QList<QPoint> point_list_; //存储点的坐标列表
    QList<QString> point_name_list_; //存储点的名字列表
};

#endif // LABEL_H
