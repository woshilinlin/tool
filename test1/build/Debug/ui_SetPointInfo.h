/********************************************************************************
** Form generated from reading UI file 'SetPointInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPOINTINFO_H
#define UI_SETPOINTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointInfo
{
public:
    QWidget *widget;
    QGridLayout *allGridLayout;
    QGridLayout *pointGridLayout;
    QLabel *yPoint;
    QLabel *xPoint;
    QLabel *point;
    QGridLayout *valueGridLayout;
    QLineEdit *xLineEdit;
    QLineEdit *zLineEdit;
    QLabel *y;
    QLineEdit *yLineEdit;
    QLabel *x;
    QLabel *z;

    void setupUi(QWidget *SetPointInfo)
    {
        if (SetPointInfo->objectName().isEmpty())
            SetPointInfo->setObjectName(QStringLiteral("SetPointInfo"));
        SetPointInfo->resize(243, 158);
        widget = new QWidget(SetPointInfo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 221, 131));
        allGridLayout = new QGridLayout(widget);
        allGridLayout->setObjectName(QStringLiteral("allGridLayout"));
        allGridLayout->setContentsMargins(0, 0, 0, 0);
        pointGridLayout = new QGridLayout();
        pointGridLayout->setObjectName(QStringLiteral("pointGridLayout"));
        yPoint = new QLabel(widget);
        yPoint->setObjectName(QStringLiteral("yPoint"));
        yPoint->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(yPoint, 0, 2, 1, 1);

        xPoint = new QLabel(widget);
        xPoint->setObjectName(QStringLiteral("xPoint"));
        xPoint->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(xPoint, 0, 1, 1, 1);

        point = new QLabel(widget);
        point->setObjectName(QStringLiteral("point"));
        point->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(point, 0, 0, 1, 1);

        pointGridLayout->setColumnStretch(0, 1);
        pointGridLayout->setColumnStretch(1, 1);
        pointGridLayout->setColumnStretch(2, 1);

        allGridLayout->addLayout(pointGridLayout, 0, 0, 1, 1);

        valueGridLayout = new QGridLayout();
        valueGridLayout->setObjectName(QStringLiteral("valueGridLayout"));
        xLineEdit = new QLineEdit(widget);
        xLineEdit->setObjectName(QStringLiteral("xLineEdit"));

        valueGridLayout->addWidget(xLineEdit, 0, 1, 1, 1);

        zLineEdit = new QLineEdit(widget);
        zLineEdit->setObjectName(QStringLiteral("zLineEdit"));

        valueGridLayout->addWidget(zLineEdit, 2, 1, 1, 1);

        y = new QLabel(widget);
        y->setObjectName(QStringLiteral("y"));
        y->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(y, 1, 0, 1, 1);

        yLineEdit = new QLineEdit(widget);
        yLineEdit->setObjectName(QStringLiteral("yLineEdit"));

        valueGridLayout->addWidget(yLineEdit, 1, 1, 1, 1);

        x = new QLabel(widget);
        x->setObjectName(QStringLiteral("x"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(x->sizePolicy().hasHeightForWidth());
        x->setSizePolicy(sizePolicy);
        x->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(x, 0, 0, 1, 1);

        z = new QLabel(widget);
        z->setObjectName(QStringLiteral("z"));
        z->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(z, 2, 0, 1, 1);

        valueGridLayout->setColumnStretch(0, 1);
        valueGridLayout->setColumnStretch(1, 2);

        allGridLayout->addLayout(valueGridLayout, 1, 0, 1, 1);


        retranslateUi(SetPointInfo);

        QMetaObject::connectSlotsByName(SetPointInfo);
    } // setupUi

    void retranslateUi(QWidget *SetPointInfo)
    {
        SetPointInfo->setWindowTitle(QApplication::translate("SetPointInfo", "Form", 0));
        yPoint->setText(QApplication::translate("SetPointInfo", "y", 0));
        xPoint->setText(QApplication::translate("SetPointInfo", "x", 0));
        point->setText(QApplication::translate("SetPointInfo", "p", 0));
        y->setText(QApplication::translate("SetPointInfo", "Y:", 0));
        x->setText(QApplication::translate("SetPointInfo", "X:", 0));
        z->setText(QApplication::translate("SetPointInfo", "Z:", 0));
    } // retranslateUi

};

namespace Ui {
    class pointInfo: public Ui_PointInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPOINTINFO_H
