/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_4;
    QGridLayout *grid2_2;
    QLabel *label_16;
    QSpinBox *serviceSpinBox;
    QPushButton *startButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget_3;
    QGridLayout *grid_2;
    QLabel *label_9;
    QLineEdit *xmlLineEdit;
    QLabel *label_10;
    QLineEdit *ipLineEdit;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *userLineEdit;
    QLabel *label_13;
    QLineEdit *passwordLineEdit;
    QLabel *label_14;
    QLabel *label_15;
    QSpinBox *delaySpinBox;
    QDoubleSpinBox *thresholdDoubleSpinBox;
    QSpinBox *portSpinBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QDockWidget *dock;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 500);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(420, 0, 220, 451));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 300, 210, 101));
        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(12, 42, 191, 28));
        grid2_2 = new QGridLayout(layoutWidget_4);
        grid2_2->setSpacing(6);
        grid2_2->setContentsMargins(11, 11, 11, 11);
        grid2_2->setObjectName(QStringLiteral("grid2_2"));
        grid2_2->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        grid2_2->addWidget(label_16, 0, 0, 1, 1);

        serviceSpinBox = new QSpinBox(layoutWidget_4);
        serviceSpinBox->setObjectName(QStringLiteral("serviceSpinBox"));
        serviceSpinBox->setMaximum(30000);
        serviceSpinBox->setValue(10001);

        grid2_2->addWidget(serviceSpinBox, 0, 1, 1, 1);

        grid2_2->setColumnStretch(0, 2);
        grid2_2->setColumnStretch(1, 3);
        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(90, 410, 89, 25));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 210, 291));
        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(11, 43, 191, 231));
        grid_2 = new QGridLayout(layoutWidget_3);
        grid_2->setSpacing(6);
        grid_2->setContentsMargins(11, 11, 11, 11);
        grid_2->setObjectName(QStringLiteral("grid_2"));
        grid_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        grid_2->addWidget(label_9, 0, 0, 1, 1);

        xmlLineEdit = new QLineEdit(layoutWidget_3);
        xmlLineEdit->setObjectName(QStringLiteral("xmlLineEdit"));

        grid_2->addWidget(xmlLineEdit, 0, 1, 1, 1);

        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setTextFormat(Qt::AutoText);

        grid_2->addWidget(label_10, 1, 0, 1, 1);

        ipLineEdit = new QLineEdit(layoutWidget_3);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        grid_2->addWidget(ipLineEdit, 1, 1, 1, 1);

        label_11 = new QLabel(layoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QStringLiteral(""));

        grid_2->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        grid_2->addWidget(label_12, 3, 0, 1, 1);

        userLineEdit = new QLineEdit(layoutWidget_3);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));

        grid_2->addWidget(userLineEdit, 3, 1, 1, 1);

        label_13 = new QLabel(layoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        grid_2->addWidget(label_13, 4, 0, 1, 1);

        passwordLineEdit = new QLineEdit(layoutWidget_3);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        grid_2->addWidget(passwordLineEdit, 4, 1, 1, 1);

        label_14 = new QLabel(layoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        grid_2->addWidget(label_14, 5, 0, 1, 1);

        label_15 = new QLabel(layoutWidget_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        grid_2->addWidget(label_15, 6, 0, 1, 1);

        delaySpinBox = new QSpinBox(layoutWidget_3);
        delaySpinBox->setObjectName(QStringLiteral("delaySpinBox"));
        delaySpinBox->setValue(0);

        grid_2->addWidget(delaySpinBox, 5, 1, 1, 1);

        thresholdDoubleSpinBox = new QDoubleSpinBox(layoutWidget_3);
        thresholdDoubleSpinBox->setObjectName(QStringLiteral("thresholdDoubleSpinBox"));
        thresholdDoubleSpinBox->setValue(0.9);

        grid_2->addWidget(thresholdDoubleSpinBox, 6, 1, 1, 1);

        portSpinBox = new QSpinBox(layoutWidget_3);
        portSpinBox->setObjectName(QStringLiteral("portSpinBox"));
        portSpinBox->setMaximum(65536);
        portSpinBox->setValue(8000);

        grid_2->addWidget(portSpinBox, 2, 1, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 230, 120, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 78));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 22));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setCursor(QCursor(Qt::CrossCursor));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);
        dock = new QDockWidget(MainWindow);
        dock->setObjectName(QStringLiteral("dock"));
        dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "server", 0));
        label_16->setText(QApplication::translate("MainWindow", "Port:", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "camera", 0));
        label_9->setText(QApplication::translate("MainWindow", "xml:", 0));
        xmlLineEdit->setText(QApplication::translate("MainWindow", "cameraParameters.xml", 0));
        label_10->setText(QApplication::translate("MainWindow", "IP:", 0));
        ipLineEdit->setText(QApplication::translate("MainWindow", "192.168.3.201", 0));
        label_11->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_12->setText(QApplication::translate("MainWindow", "user:", 0));
        userLineEdit->setText(QApplication::translate("MainWindow", "admin", 0));
        label_13->setText(QApplication::translate("MainWindow", "password:", 0));
        passwordLineEdit->setText(QApplication::translate("MainWindow", "Ehigh2014", 0));
        label_14->setText(QApplication::translate("MainWindow", "Delay:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Threshold:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
