#ifndef POINTIFO_H
#define POINTIFO_H

#include <QWidget>

namespace Ui {
class PointIfo;
}

struct point{
    QString pointName;
    QString x;
    QString y;

    double realX;
    double realY;
    double realZ;
};

enum lineEdit
{
    xLineEdit,
    yLineEdit,
    zLineEdit
};

class PointInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PointInfo(QWidget *parent = 0);
    ~PointInfo();

    point getPointInfo();
    void setPointInfo(const point &p);
signals:
    void currentRow(int);

private:
    void initList();

private slots:
    void deleteButton();

private:
    Ui::PointIfo *ui;

    point p;

};

#endif // POINTIFO_H
