#include "pointinfowidget.h"
#include "ui_pointinfowidget.h"

PointInfowidget::PointInfowidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointInfowidget)
{
    ui->setupUi(this);
}

PointInfowidget::~PointInfowidget()
{
    delete ui;
}
