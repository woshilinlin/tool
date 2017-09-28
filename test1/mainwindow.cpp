#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QFileDialog>
#include <QHoverEvent>
#include <QMessageBox>

#include "imagetools.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initScrollArea();
    initDockWidget();
    initStatusBar();

    connect(image_label_, SIGNAL(horScrollBarChange(double)),
            label_scrollarea_, SLOT(setHorValue(double)));

    connect(image_label_, SIGNAL(verScrollBarChange(double,int)),
            label_scrollarea_, SLOT(setVerValue(double, int)));

    connect(pointinfo_listwidget_, SIGNAL(deletePoint(int)),
            image_label_, SLOT(removePoint(int)));

    connect(pointinfo_listwidget_, SIGNAL(deletePoint(int)),
            this, SLOT(removePointInfo(int)));

    connect(image_label_, SIGNAL(sendNewPointName(QString)),
            this, SLOT(pointInfo(QString)));

    connect(image_label_, SIGNAL(leftPressPionts(QPoint)),
            this, SLOT(receivePress(QPoint)));

    connect(this, SIGNAL(sendImage(QImage)), image_label_, SLOT(receiveImage(QImage)));
    connect(this, SIGNAL(sendPoint(QPoint)), label_scrollarea_, SLOT(setValue(QPoint)));
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(cameraStartButton()));
}

void MainWindow::initScrollArea()
{
    image_label_ = new ImageLabel;
    label_scrollarea_ = new LabelScroll;
    image_label_->showPixmap(":/image/jpg/white.jpg");
    label_scrollarea_->setWidget(image_label_);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(label_scrollarea_);
    layout->addWidget(ui->widget);
    layout->setStretch(0, 7);
    layout->setStretch(1, 1);
    layout->setMargin(0);
    centralWidget()->setLayout(layout);
}

void MainWindow::initStatusBar()
{
    QLabel * x = new QLabel("x");
    QLabel * y = new QLabel("y");
    x_value_label_ = new QLabel;
    y_value_label_ = new QLabel;

    statusBar()->addWidget(x);
    statusBar()->addWidget(x_value_label_);
    statusBar()->addWidget(y);
    statusBar()->addWidget(y_value_label_);
}

void MainWindow::initDockWidget()
{
    pointinfo_listwidget_ = new PointInfoListWidget;

    QMenu * menu = new QMenu;
    menu->setTitle("&File");
    menu->addAction("save", this, SLOT(saveFile()), QKeySequence::Save);
    menuBar()->addMenu(menu);

    ui->dock->setWidget(pointinfo_listwidget_);
}

bool MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::HoverMove)
    {
        const double extra_x = 2.0;
        const double extra_y = 3.0;
        QHoverEvent * hover = static_cast<QHoverEvent *> (e);
        QPoint point = hover->pos();
        QRect rect = image_label_->geometry();

        double xcoordinate = point.x() - rect.x() - extra_x; //x相对坐标值
        double ycoordinate = point.y() - rect.y() - centralWidget()->y() - extra_y; //y相对坐标值

        double multiple = static_cast<double>(image_label_->height()) / image_height_;

        QString xValue = QString::number(xcoordinate / multiple, 'f', 1); //x绝对坐标值
        QString yValue = QString::number(ycoordinate / multiple, 'f', 1); //y绝对坐标值

        x_value_label_->setText(xValue);
        y_value_label_->setText(yValue);
    }
    return QMainWindow::event(e);
}

void MainWindow::receivePress(const QPoint &point)
{
    if (image_label_->cursor().shape() == Qt::ClosedHandCursor)
    {
        double x_value = x_value_label_->text().toDouble();
        double y_value = y_value_label_->text().toDouble();

        QPoint currentPoint(x_value, y_value);
        QPoint difference = point - currentPoint; //按压点与悬停点坐标之差
        emit sendPoint(difference);
    }
}

void MainWindow::pointInfo(const QString & text)
{
    PointInfowidget * info = new PointInfowidget;
    Point point = info->getPointInfo();

    point.name = text;
    point.x = x_value_label_->text();
    point.y = y_value_label_->text();

    info->setPointInfo(point);
    pointinfo_list_.append(info);

    QListWidgetItem * listitem = new QListWidgetItem;
    listitem->setSizeHint(QSize(0, info->height()));

    pointinfo_listwidget_->addItem(listitem);
    pointinfo_listwidget_->setItemWidget(listitem, info);

    connect(info, SIGNAL(currentRow(int)), pointinfo_listwidget_, SLOT(removeRow(int)));
}

void MainWindow::removePointInfo(int row)
{
    QJsonObject json = pointinfo_document_.object();
    json.remove(pointinfo_list_.at(row)->getPointInfo().name);

    if (!pointinfo_list_.isEmpty())
    {
        pointinfo_list_.removeAt(row);
    }

    Point point;
    int name_number; //点名字的编号
    int length = pointinfo_list_.length();
    for (int i = row; i < length; i++)
    {
        point = pointinfo_list_.at(i)->getPointInfo();
        json.remove(point.name);
        name_number = point.name.mid(1).toInt();
        point.name = QString("P%1").arg(--name_number);
        pointinfo_list_.at(i)->setPointInfo(point);
    }
}

void MainWindow::createJson()
{
    QJsonObject pointinfo_json_;
    int length = pointinfo_list_.length();
    for (int i = 0; i < length; i++)
    {
        Point point = pointinfo_list_.at(i)->getPointInfo();
        QJsonArray two_dimensional;//二位坐标数组
        two_dimensional.insert(XAXIS, point.x);
        two_dimensional.insert(YAXIS, point.y);

        QJsonArray three_dimensional;//三维坐标数组
        three_dimensional.insert(XLINEEDIT, point.real_x);
        three_dimensional.insert(YLINEEDIT, point.real_y);
        three_dimensional.insert(ZLINEEDIT, point.real_z);

        QJsonObject json_object;
        json_object.insert("two", two_dimensional);
        json_object.insert("three", three_dimensional);

        QJsonArray json_array;
        json_array.append(json_object);

        pointinfo_json_.insert(point.name, json_array);
    }
    pointinfo_document_.setObject(pointinfo_json_);
}

bool MainWindow::saveFile()
{
    createJson();
    QFile file(QFileDialog::getOpenFileName(this, tr("Save File"),
                                            "/home/lin", tr(" (*.txt)")));
    if (file.exists())
    {
        if (!file.remove())
        {
            return false;
        }
    }

    if (!file.open(QFile::ReadWrite))
    {
        QMessageBox::warning(this, "Message", "open file failed");
        return false;
    }
    else
    {
        file.write(pointinfo_document_.toJson());
        file.close();
        QMessageBox::information(this, "Information", "Saved successfully");
        return true;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete image_label_;
    delete x_value_label_;
    delete y_value_label_;
    delete label_scrollarea_;
    delete pointinfo_listwidget_;
}

//---------------Camera---------------

CameraConfig MainWindow::getCameraConfig() const
{
    CameraConfig config;
    config.ip = ui->ipLineEdit->text();
    config.port = ui->portSpinBox->value();
    config.username = ui->userLineEdit->text();
    config.password = ui->passwordLineEdit->text();
    config.delay = ui->delaySpinBox->value();
    config.xmlfile = ui->xmlLineEdit->text();
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
        image_height_ = image.height();
        if(!image.isNull())
        {
            QPixmap scaled_pixmap = QPixmap::fromImage(image.scaled(image_label_->size(),
                                                      Qt::KeepAspectRatio,
                                                      Qt::SmoothTransformation));
            image_label_->showPixmap(scaled_pixmap);
        }
        emit sendImage(image);
    }
}

void MainWindow::cameraStartButton()
{
    setCameraStatus(START);
    ui->widget->setHidden(true);
}

CameraStatus MainWindow::getCameraStatus() const
{
    return camera_status_;
}

void MainWindow::setCameraStatus(CameraStatus status)
{
    camera_status_ = status;
}
