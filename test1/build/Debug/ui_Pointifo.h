/********************************************************************************
** Form generated from reading UI file 'Pointifo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTIFO_H
#define UI_POINTIFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointIfo
{
public:
    QWidget *layoutWidget;
    QGridLayout *allGridLayout;
    QGridLayout *valueGridLayout;
    QLineEdit *xLineEdit;
    QLineEdit *zLineEdit;
    QLabel *y;
    QLineEdit *yLineEdit;
    QLabel *x;
    QLabel *z;
    QGridLayout *pointGridLayout;
    QLabel *label;
    QLabel *yPoint;
    QLabel *xPoint;
    QLabel *point;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *PointIfo)
    {
        if (PointIfo->objectName().isEmpty())
            PointIfo->setObjectName(QStringLiteral("PointIfo"));
        PointIfo->resize(224, 205);
        layoutWidget = new QWidget(PointIfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 221, 153));
        allGridLayout = new QGridLayout(layoutWidget);
        allGridLayout->setObjectName(QStringLiteral("allGridLayout"));
        allGridLayout->setContentsMargins(0, 0, 0, 0);
        valueGridLayout = new QGridLayout();
        valueGridLayout->setObjectName(QStringLiteral("valueGridLayout"));
        xLineEdit = new QLineEdit(layoutWidget);
        xLineEdit->setObjectName(QStringLiteral("xLineEdit"));

        valueGridLayout->addWidget(xLineEdit, 0, 1, 1, 1);

        zLineEdit = new QLineEdit(layoutWidget);
        zLineEdit->setObjectName(QStringLiteral("zLineEdit"));

        valueGridLayout->addWidget(zLineEdit, 2, 1, 1, 1);

        y = new QLabel(layoutWidget);
        y->setObjectName(QStringLiteral("y"));
        y->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(y, 1, 0, 1, 1);

        yLineEdit = new QLineEdit(layoutWidget);
        yLineEdit->setObjectName(QStringLiteral("yLineEdit"));

        valueGridLayout->addWidget(yLineEdit, 1, 1, 1, 1);

        x = new QLabel(layoutWidget);
        x->setObjectName(QStringLiteral("x"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(x->sizePolicy().hasHeightForWidth());
        x->setSizePolicy(sizePolicy);
        x->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(x, 0, 0, 1, 1);

        z = new QLabel(layoutWidget);
        z->setObjectName(QStringLiteral("z"));
        z->setAlignment(Qt::AlignCenter);

        valueGridLayout->addWidget(z, 2, 0, 1, 1);

        valueGridLayout->setColumnStretch(0, 1);
        valueGridLayout->setColumnStretch(1, 2);

        allGridLayout->addLayout(valueGridLayout, 1, 0, 1, 1);

        pointGridLayout = new QGridLayout();
        pointGridLayout->setObjectName(QStringLiteral("pointGridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        pointGridLayout->addWidget(label, 0, 1, 1, 1);

        yPoint = new QLabel(layoutWidget);
        yPoint->setObjectName(QStringLiteral("yPoint"));
        yPoint->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(yPoint, 0, 4, 1, 1);

        xPoint = new QLabel(layoutWidget);
        xPoint->setObjectName(QStringLiteral("xPoint"));
        xPoint->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(xPoint, 0, 2, 1, 1);

        point = new QLabel(layoutWidget);
        point->setObjectName(QStringLiteral("point"));
        point->setAlignment(Qt::AlignCenter);

        pointGridLayout->addWidget(point, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        pointGridLayout->addWidget(label_2, 0, 3, 1, 1);

        pointGridLayout->setColumnStretch(0, 2);
        pointGridLayout->setColumnStretch(1, 1);
        pointGridLayout->setColumnStretch(2, 1);
        pointGridLayout->setColumnStretch(3, 1);
        pointGridLayout->setColumnStretch(4, 1);

        allGridLayout->addLayout(pointGridLayout, 0, 0, 1, 1);

        layoutWidget1 = new QWidget(PointIfo);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 160, 221, 33));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        retranslateUi(PointIfo);

        QMetaObject::connectSlotsByName(PointIfo);
    } // setupUi

    void retranslateUi(QWidget *PointIfo)
    {
        PointIfo->setWindowTitle(QApplication::translate("PointIfo", "Form", 0));
        y->setText(QApplication::translate("PointIfo", "Y:", 0));
        x->setText(QApplication::translate("PointIfo", "X:", 0));
        z->setText(QApplication::translate("PointIfo", "Z:", 0));
        label->setText(QApplication::translate("PointIfo", "x :", 0));
        yPoint->setText(QString());
        xPoint->setText(QString());
        point->setText(QApplication::translate("PointIfo", "p", 0));
        label_2->setText(QApplication::translate("PointIfo", "y :", 0));
        pushButton->setText(QApplication::translate("PointIfo", "\345\210\240\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class PointIfo: public Ui_PointIfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTIFO_H
