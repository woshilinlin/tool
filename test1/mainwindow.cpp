#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylistwidget.h"
#include "Imagetools.h"
#include "Pointinfo.h"
#include "Label.h"

#include <QPen>
#include <QPoint>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QToolBar>
#include <QFileDialog>
#include <QHoverEvent>
#include <QScrollArea>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QJsonArray>

#define EXTRAX 2.0
#define EXTRAY 3.0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setScrollArea();
    addPointLabel();
    setDockWidget();

    connect(lab, SIGNAL(xSignal(double)), scr, SLOT(setHorValue(double)));
    connect(lab, SIGNAL(ySignal(double, int)), scr, SLOT(setVerValue(double, int)));
    connect(lab, SIGNAL(newPoint(QString)), this, SLOT(pointInfo(QString)));
    connect(lab, SIGNAL(pressPionts(QPoint)), this, SLOT(receivePress(QPoint)));
    connect(this, SIGNAL(sendPoint(QPoint)), scr, SLOT(setValue(QPoint)));
    connect(this, SIGNAL(sendImage(QImage)), lab, SLOT(receiveImage(QImage)));
    connect(listWidget, SIGNAL(deletePoint(int)), lab, SLOT(removePoint(int)));
    connect(listWidget, SIGNAL(deletePoint(int)), this, SLOT(removePointInfo(int)));
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startButton()));
}

void MainWindow::setScrollArea()
{
    lab = new Label;
    scr = new Scroll;
    lab->showPixmap("../../white.jpg");
    scr->setWidget(lab);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(scr);
    layout->addWidget(ui->widget);
    layout->setStretch(0, 7);
    layout->setStretch(1, 1);
    layout->setMargin(0);
    centralWidget()->setLayout(layout);
}

void MainWindow::addPointLabel()
{
    QLabel * x = new QLabel("x");
    QLabel * y = new QLabel("y");
    xLabel = new QLabel;
    yLabel = new QLabel;

    statusBar()->addWidget(x);
    statusBar()->addWidget(xLabel);
    statusBar()->addWidget(y);
    statusBar()->addWidget(yLabel);
}

void MainWindow::setDockWidget()
{
    listWidget = new MyListWidget;

    QMenu * menu = new QMenu;
    menu->setTitle("&File");
    menu->addAction("save", this, SLOT(saveFile()), QKeySequence::Save);
    menuBar()->addMenu(menu);

    ui->dock->setWidget(listWidget);
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::HoverMove)
    {
        QHoverEvent * hover = static_cast<QHoverEvent *> (event);
        QPoint point = hover->pos();
        QRect rect = lab->geometry();

        double x1 = point.x() - rect.x() - EXTRAX;
        double y1 = point.y() - rect.y() - centralWidget()->y() - EXTRAY;

        double multiple = double(lab->height()) / PIXHEIGHT;

        QString xValue = QString::number(x1 / multiple, 'f', 1);
        QString yValue = QString::number(y1 / multiple, 'f', 1);

        xLabel->setText(xValue);
        yLabel->setText(yValue);

        createJson();

    }
    return QMainWindow::event(event);
}

void MainWindow::receivePress(const QPoint &point)
{
    pressPoint.setX(point.x());
    pressPoint.setY(point.y());
    if (lab->cursor().shape() == Qt::ClosedHandCursor)
    {
        double x = xLabel->text().toDouble();
        double y = yLabel->text().toDouble();

        QPoint currentPoint(x, y);
        QPoint difference = pressPoint - currentPoint ;
        qDebug() << currentPoint << pressPoint << difference;
        emit sendPoint(difference);
    }
}

void MainWindow::pointInfo(const QString & text)
{
    PointInfo * info = new PointInfo;
    point p = info->getPointInfo();

    p.pointName = text;
    p.x = xLabel->text();
    p.y = yLabel->text();

    info->setPointInfo(p);
    pointInfoList.append(info);

    QListWidgetItem * str1 = new QListWidgetItem;
    str1->setSizeHint(QSize(0, info->height()));

    listWidget->addItem(str1);
    listWidget->setItemWidget(str1, info);

    connect(info, SIGNAL(currentRow(int)), listWidget, SLOT(removeCurrentRow(int)));
}

void MainWindow::removePointInfo(int row)
{
    json.remove(pointInfoList.at(row)->getPointInfo().pointName);
    if (!pointInfoList.isEmpty())
    {
        pointInfoList.removeAt(row);
    }

    int length = pointInfoList.length();
    for (int i = row; i < length; i++)
    {
        point p = pointInfoList.at(i)->getPointInfo();
        json.remove(p.pointName);

        int n = p.pointName.mid(1).toInt();
        QString name = QString("P%1").arg(--n);
        p.pointName = name;
        pointInfoList.at(i)->setPointInfo(p);
    }
}

void MainWindow::createJson()
{
    int n = pointInfoList.length();
    for (int i = 0; i < n; i++)
    {
        point p = pointInfoList.at(i)->getPointInfo();

        QJsonArray twoDimensional;
        twoDimensional.insert(xAxis, p.x);
        twoDimensional.insert(yAxis, p.y);

        QJsonArray threeDimensional;
        threeDimensional.insert(xLineEdit, p.realX);
        threeDimensional.insert(yLineEdit, p.realY);
        threeDimensional.insert(zLineEdit, p.realZ);

        QJsonObject object;
        object.insert("two", twoDimensional);
        object.insert("three", threeDimensional);

        QJsonArray array;
        array.append(object);

        json.insert(p.pointName, array);
    }
}

bool MainWindow::saveFile()
{
    createJson();
    QFile file(QFileDialog::getOpenFileName(this, tr("Save File"), "/home/lin", tr(" (*.txt)")));
    if (file.exists())
    {
        file.remove();
    }
    document.setObject(json);
    if (!file.open(QFile::ReadWrite))
    {
        QMessageBox::warning(this, "Message", "open file failed");
        return false;
    }
    else
    {
        file.write(document.toJson());
        file.close();
        QMessageBox::information(this, "Information", "Saved successfully");
        return true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lab;
    delete scr;
    delete xLabel;
    delete yLabel;
    delete listWidget;
}

//---------------Camera---------------

CameraConfig MainWindow::getCameraConfig()
{
    CameraConfig config;
    config.ip = ui->ipLineEdit->text();
    config.port = ui->portSpinBox->value();
    config.username = ui->userLineEdit->text();
    config.password = ui->passwordLineEdit->text();
    config.delay = ui->delaySpinBox->value();
    config.xmlFile = ui->xmlLineEdit->text();
    config.threshold = ui->thresholdDoubleSpinBox->value();

    return config;
}

void MainWindow::receiveMat(const cv::Mat & mat)
{
    QImage image = Imagetools::cvMat2QImage(mat);
    showCapturedImage(image);
}

void MainWindow::showCapturedImage(QImage &image)
{
    if (!image.isNull())
    {
        PIXHEIGHT = image.height();
        if(!image.isNull())
        {
            QPixmap scaledPixmap = QPixmap::fromImage(image.scaled(lab->size(),
                                                                   Qt::KeepAspectRatio, Qt::SmoothTransformation));
            lab->showPixmap(scaledPixmap);
        }
        emit sendImage(image);
    }
}

void MainWindow::startButton()
{
    setState(START);
    ui->widget->setHidden(true);
}

int MainWindow::state()
{
    return sta;
}

void MainWindow::setState(STATE state)
{
    sta = state;
}
