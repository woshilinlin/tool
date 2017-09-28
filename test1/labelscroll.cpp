#include "labelscroll.h"

#include <QDebug>
#include <QScrollBar>

#include "imagelabel.h"

LabelScroll::LabelScroll()
{
    setLineWidth(0);
    setAlignment(Qt::AlignCenter);

//    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(getHorValue(int)));
//    connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(getVerValue(int)));

}

LabelScroll::~LabelScroll()
{

}

void LabelScroll::getHorValue(int x) const
{
    qDebug() << x << static_cast<double>(x) / horizontalScrollBar()->maximum();
}

void LabelScroll::getVerValue(int y) const
{
    qDebug() << y << static_cast<double>(y) / verticalScrollBar()->maximum();
}

void LabelScroll::setHorValue(double hormultiple)
{
    const int kHorFixedValue = 180;
    QScrollBar * hor = horizontalScrollBar();
    hor->setValue((static_cast<double>(hor->maximum()) + kHorFixedValue) * hormultiple);
}

void LabelScroll::setVerValue(double vermultipe, int delta)
{
    const int kVerFixedValue = 60;
    if (delta > 0)
    {
        double value = static_cast<double>(verticalScrollBar()->maximum());
        verticalScrollBar()->setValue((value * vermultipe) + kVerFixedValue);
    }
    else
    {
        double value = static_cast<double>(verticalScrollBar()->maximum());
        verticalScrollBar()->setValue((value * vermultipe) - kVerFixedValue);
    }
}

void LabelScroll::setValue(const QPoint &point)
{
    horizontalScrollBar()->setValue(horizontalScrollBar()->value() + point.x());
    verticalScrollBar()->setValue(verticalScrollBar()->value() + point.y());
}


