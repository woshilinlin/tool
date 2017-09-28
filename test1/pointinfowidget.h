#ifndef POINTINFOWIDGET_H
#define POINTINFOWIDGET_H

#include <QWidget>

namespace Ui {
class PointInfowidget;
}

class PointInfowidget : public QWidget
{
    Q_OBJECT

public:
    explicit PointInfowidget(QWidget *parent = 0);
    ~PointInfowidget();

private:
    Ui::PointInfowidget *ui;
};

#endif // POINTINFOWIDGET_H
