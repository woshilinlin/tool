#include "imagelabel.h"

#include <QPen>
#include <QMenu>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>

ImageLabel::ImageLabel() : point_number_(1), zoom_multiple_(1.0)
{
    setLineWidth(0);
    connect(this, SIGNAL(pixMapUpdate()), this, SLOT(setScalePixmap()));
    connect(this, SIGNAL(wheelRolling()), this, SLOT(setScalePixmap()));
    connect(&point_timer_, SIGNAL(timeout()), this, SLOT(pointTimerOut()));
    connect(&left_longpress_timer_, SIGNAL(timeout()), this, SLOT(longPress()));

    left_longpress_timer_.setSingleShot(true); //单次计时器，仅触发一次
}

void ImageLabel::showPixmap(const QString & filepath)
{
    pixmap_.load(filepath);
    setPixmap(pixmap_);
}

void ImageLabel::showPixmap(const QPixmap & pixmap)
{
    pixmap_ = pixmap;
    drawAllPoint();
    emit pixMapUpdate();
    setPixmap(pixmap_);
}

void ImageLabel::addPointNumber()
{
    point_number_++;
}

void ImageLabel::setScalePixmap()
{
    if (1 != zoom_multiple_)
    {
        scaleImage();
    }
}

void ImageLabel::receiveImage(const QImage &images)
{
    image_ = images;
}

void ImageLabel::wheelEvent(QWheelEvent *event)
{
    QPoint points = event->pos(); //鼠标悬停位置点坐标
    int x_value = points.x();
    int y_value = points.y();
    int pixwidth = pixmap_.width();
    int pixheight = pixmap_.height();

    if (!pixmap_.isNull())
    {
        int delta = event->delta(); //滚轮滚动方向，向前为大于零
        delta > 0 ? zoomIn() : zoomOut();
        emit wheelRolling();

        qDebug() << zoom_multiple_;
        double hormultiple = static_cast<double>(x_value) / pixwidth;
        double vermultiple = static_cast<double>(y_value) / pixheight;

        emit horScrollBarChange(hormultiple);
        emit verScrollBarChange(vermultiple, delta);
    }
}

void ImageLabel::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        left_press_point_ = event->pos(); //鼠标左键长按的点坐标
        left_longpress_timer_.start(200); //200毫秒后启动计时器
    }

    if (event->button() == Qt::RightButton)
    {
        //TODO
    }

    QLabel::mousePressEvent(event);
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        setCursor(Qt::ArrowCursor); //恢复光标形状

        if (left_longpress_timer_.remainingTime() > 0)
        {
            savePoint(left_press_point_);
        }

        left_longpress_timer_.stop();
        point_timer_.stop();
    }
    QLabel::mouseReleaseEvent(event);
}

void ImageLabel::savePoint(const QPoint &point)
{
    point_list_.append(point / zoom_multiple_);

    QString text = QString("P%1").arg(point_number_);
    point_name_list_.append(text);
    addPointNumber();
    emit sendNewPointName(text);
}

void ImageLabel::longPress()
{
    setCursor(Qt::ClosedHandCursor); //改变光标形状
    point_timer_.start();
}

void ImageLabel::pointTimerOut()
{
    //pressEvent与相对坐标的差值
    QPoint point(left_press_point_.x() - 1, left_press_point_.y() - 2);
    emit leftPressPionts(point / zoom_multiple_);
}

void ImageLabel::drawAllPoint()
{
    if (!point_list_.isEmpty() && !point_name_list_.isEmpty())
    {
        int length = point_list_.length();
        for (int i = 0; i < length; i++)
        {
            drawPoint(point_list_.at(i), point_name_list_.at(i));
        }
    }
}

void ImageLabel::drawPoint(const QPoint &point, const QString &text)
{
    QPainter painter(&pixmap_);

    QPen point_pen; //点画笔
    point_pen.setBrush(Qt::red);
    point_pen.setWidth(2);

    QPen triangle_pen; //三角形画笔
    triangle_pen.setBrush(Qt::blue);
    triangle_pen.setWidth(1);

    QPen text_pen; //文字画笔
    text_pen.setBrush(Qt::black);
    text_pen.setWidth(1);

    int x_value = point.x() * zoom_multiple_;
    int y_value = point.y() * zoom_multiple_;

    //三角形三个顶点坐标数组
    QPointF pointF[3] = {QPointF(x_value, y_value + 1),
                         QPointF(x_value - 6, y_value + 7),
                         QPointF(x_value + 6, y_value + 7)};

    painter.setPen(point_pen);
    painter.drawPoint(x_value, y_value); //画点

    painter.setPen(triangle_pen);
    painter.drawPolygon(pointF, 3); //画多边形

    painter.setPen(text_pen);
    painter.drawText(x_value, y_value - 2, text); //画文本
}

void ImageLabel::removePoint(int position)
{
    if (!point_list_.isEmpty() && !point_name_list_.isEmpty())
    {
        point_list_.removeAt(position);
        point_name_list_.removeAt(position);

    }
    point_number_ --;

    int current_name_number; //当前坐标名字对应的数字编号
    int length = point_name_list_.length();
    for (int i = 0; i < length; i++)
    {
        current_name_number = point_name_list_.at(i).mid(1).toInt();
        if (current_name_number > position)
        {
            QString name = QString("P%1").arg(current_name_number-1);
            point_name_list_.replace(i, name);
        }
    }
}

void ImageLabel::zoomIn()
{
    const double increase_ = 1.25; //每次放大倍数
    zoom_multiple_ *= increase_;
}

void ImageLabel::zoomOut()
{
    const double reduced_ = 0.8; //每次缩小倍数
    zoom_multiple_ *= reduced_;
}

void ImageLabel::scaleImage()
{
    Q_ASSERT(pixmap());
    int width = image_.width();
    int height = image_.height();
    resize(image_.size() * zoom_multiple_);
    setPixmap(pixmap_.scaled(zoom_multiple_ * width,
                             zoom_multiple_ * height,
                             Qt::KeepAspectRatio));
}

