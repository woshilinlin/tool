#include "Label.h"

#include <QPen>
#include <QMenu>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QHoverEvent>

Label::Label() : increase(1.25), reduced(0.8), pointNum(1), num(1.0)
{
    setLineWidth(0);
    connect(this, SIGNAL(pixSignal()), this, SLOT(setCameraPixmap()));
    connect(this, SIGNAL(wheelSignal()), this, SLOT(setCameraPixmap()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(longPress()));
    connect(&pointTimer, SIGNAL(timeout()), this, SLOT(timeOut()));
    timer.setSingleShot(true);

}

void Label::showPixmap(const QString & filePath)
{
    pix.load(filePath);
    setPixmap(pix);
}


void Label::showPixmap(const QPixmap & pixMap)
{
    pix = pixMap;
    draw();
    emit pixSignal();
    setPixmap(pix);
}

void Label::addPointNum()
{
    pointNum++;
}

void Label::setCameraPixmap()
{
    if (1 !=num)
    {
        scaleImage();
    }
}


void Label::receiveImage(const QImage &images)
{
    image = images;
}

void Label::wheelEvent(QWheelEvent *event)
{
    QPoint points = event->pos();
    int xValue = points.x();
    int yValue = points.y();
    int pixWidth = pix.width();
    int pixHeight = pix.height();

    if (!pix.isNull())
    {
        int delta = event->delta();
        delta > 0 ? zoomIn() : zoomOut();
        emit wheelSignal();

        qDebug() << num;
        if (delta > 0)
        {
            double horMul = double(xValue) / pixWidth;
            double verMul = double(yValue) / pixHeight;

            emit xSignal(horMul);
            emit ySignal(verMul, delta);
        }
        else
        {
            double horMul = double(xValue) / pixWidth;
            double verMul = double(yValue) / pixHeight;

            emit xSignal(horMul);
            emit ySignal(verMul, delta);
        }
    }
}

void Label::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        pressPoint = event->pos();
        timer.start(200);

//        qDebug() << event->pos();
    }

    if (event->button() == Qt::RightButton)
    {
//        qDebug() << event->pos();
    }

    QLabel::mousePressEvent(event);
}

void Label::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        setCursor(Qt::ArrowCursor);

        if (timer.remainingTime() > 0)
        {
            pressDraw(pressPoint);
        }

        timer.stop();
        pointTimer.stop();
    }
    QLabel::mouseReleaseEvent(event);
}

void Label::pressDraw(QPoint point)
{
    pointList.append(point / num);

    QString text = QString("P%1").arg(pointNum);
    pointNameList.append(text);
    addPointNum();
    emit newPoint(text);
}

void Label::longPress()
{
    setCursor(Qt::ClosedHandCursor);
    pointTimer.start();
}

void Label::timeOut()
{
    QPoint p(pressPoint.x() - 1, pressPoint.y() -2);
    emit pressPionts(p / num);
}

void Label::draw()
{
    if (!pointList.isEmpty() && !pointNameList.isEmpty())
    {
        int length = pointList.length();
        for (int i = 0; i < length; i++)
        {
            drawPixmap(pointList.at(i), pointNameList.at(i));
        }
    }
}

void Label::drawPixmap(const QPoint &point, const QString & text)
{
    QPainter paint(&pix);

    QPen pointPen;
    pointPen.setBrush(Qt::red);
    pointPen.setWidth(2);

    QPen trianglePen;
    trianglePen.setBrush(Qt::blue);
    trianglePen.setWidth(1);

    QPen textPen;
    textPen.setBrush(Qt::black);
    textPen.setWidth(1);

    int xPoint = point.x() * num;
    int yPoint = point.y() * num;
    QPointF pointF[3] = {QPointF(xPoint, yPoint + 1),
                         QPointF(xPoint - 6, yPoint + 7),
                         QPointF(xPoint + 6, yPoint + 7)};

    paint.setPen(pointPen);
    paint.drawPoint(xPoint, yPoint);

    paint.setPen(trianglePen);
    paint.drawPolygon(pointF, 3);

    paint.setPen(textPen);
    paint.drawText(xPoint, yPoint - 2, text);
}

void Label::removePoint(int row)
{
    if (!pointList.isEmpty())
    {
        pointList.removeAt(row);
    }
    pointNameList.removeAt(row);
    pointNum --;

    int length = pointNameList.length();
    int n;
    for (int i = 0; i < length; i++)
    {
        n = pointNameList.at(i).mid(1).toInt();
        if (n > row + 1)
        {
            QString name = QString("P%1").arg(n--);
            pointNameList.replace(i, name);
        }
    }
}


void Label::test()
{
    qDebug() << 111;
}


void Label::zoomIn()
{
    num *= increase;
}

void Label::zoomOut()
{
    num *= reduced;
}



void Label::scaleImage()
{
    Q_ASSERT(pixmap());
    int width = image.width();
    int height = image.height();
    resize(image.size() * num);
    setPixmap(pix.scaled(num * width, num * height, Qt::KeepAspectRatio));
}

