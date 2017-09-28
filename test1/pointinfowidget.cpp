#include "pointinfowidget.h"
#include "ui_pointinfowidget.h"

PointInfowidget::PointInfowidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointInfowidget)
{
    ui->setupUi(this);

    QWidget::setTabOrder(ui->xLineEdit, ui->yLineEdit); //设置Tab键的顺序
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deletePointItem()));
}

Point PointInfowidget::getPointInfo() const
{
    Point point;
    point.name = ui->point->text();
    point.x = ui->xPoint->text();
    point.y = ui->yPoint->text();

    point.real_x = ui->xLineEdit->text().toDouble();
    point.real_y = ui->yLineEdit->text().toDouble();
    point.real_z = ui->zLineEdit->text().toDouble();

    return point;
}

void PointInfowidget::setPointInfo(const Point &point)
{
    ui->point->setText(point.name);
    ui->xPoint->setText(point.x);
    ui->yPoint->setText(point.y);
}

void PointInfowidget::deletePointItem()
{
    QString string = getPointInfo().name;
    int row = string.mid(1).toInt() - 1; //点所在的行数
    emit currentRow(row);
}

PointInfowidget::~PointInfowidget()
{
    delete ui;
}
