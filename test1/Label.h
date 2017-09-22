#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QTimer>

class QTimer;
class QPixmap;

class Label : public QLabel
{
    Q_OBJECT

public:
    Label();

public slots:
    void showPixmap(const QPixmap & pixMap);
    void showPixmap(const QString & filePath);

    void removePoint(int row);

private slots:
    void test();
    void longPress();
    void setCameraPixmap();    
    void receiveImage(const QImage & images);

    void timeOut();
signals:
    void xSignal(double);
    void ySignal(double, int);

    void horMove(int);
    void verMove(int);

    void pixSignal();
    void wheelSignal();

    void pressPionts(QPoint);

    void newPoint(const QString &);

private:
    void wheelEvent(QWheelEvent *event);    
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void draw();
    void zoomIn();
    void zoomOut();
    void scaleImage();
    void addPointNum();
    void pressDraw(QPoint point);
    void drawPixmap(const QPoint & point, const QString &text);

private:
    double increase;
    double reduced;
    int pointNum;
    double num;

    QPixmap pix;
    QImage image;
    QTimer timer;
    QTimer pointTimer;
    QList<QPoint> pointList;
    QList<QString> pointNameList;

    QPoint pressPoint;
    QPoint releasePoint;
};

#endif // LABEL_H
