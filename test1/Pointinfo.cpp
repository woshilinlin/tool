#include "Pointinfo.h"
#include "ui_Pointifo.h"
#include <QDebug>

PointInfo::PointInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointIfo)
{
    ui->setupUi(this);

    QWidget::setTabOrder(ui->xLineEdit, ui->yLineEdit);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(deleteButton()));
}

PointInfo::~PointInfo()
{
    delete ui;
}

point PointInfo::getPointInfo()
{
    p.pointName = ui->point->text();
    p.x = ui->xPoint->text();
    p.y = ui->yPoint->text();

    p.realX = ui->xLineEdit->text().toDouble();
    p.realY = ui->yLineEdit->text().toDouble();
    p.realZ = ui->zLineEdit->text().toDouble();

    return p;
}

void PointInfo::setPointInfo(const point &p)
{
    ui->point->setText(p.pointName);
    ui->xPoint->setText(p.x);
    ui->yPoint->setText(p.y);
}

void PointInfo::deleteButton()
{
    QString string = p.pointName;
    int row = string.mid(1).toInt() - 1;
    emit currentRow(row);
}
