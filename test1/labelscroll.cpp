#include "Label.h"
#include "Scroll.h"

#include <QDebug>
#include <QEvent>
#include <QScrollBar>

#define HORFIXEDVALUE 180
#define VERFIXEDVALUE 60

Scroll::Scroll()
{
    setLineWidth(0);
    setAlignment(Qt::AlignCenter);

//    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(getHorValue(int)));
//    connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(getVerValue(int)));

}

Scroll::~Scroll()
{

}

void Scroll::getHorValue(int x)
{
    qDebug() << "hor" << x << double(x) / horizontalScrollBar()->maximum();
}

void Scroll::getVerValue(int y)
{
    double v = double(y) / verticalScrollBar()->maximum();
    qDebug() << "ver" << y << v;
}

void Scroll::setHorValue(double x)
{
    horizontalScrollBar()->setValue((double(horizontalScrollBar()->maximum()) + HORFIXEDVALUE) * x);
}

void Scroll::setVerValue(double y, int delta)
{
    if (delta > 0)
    {
        double value = verticalScrollBar()->maximum();
        verticalScrollBar()->setValue((value * y) + VERFIXEDVALUE);
    }
    else
    {
        double value = verticalScrollBar()->maximum();
        verticalScrollBar()->setValue((value * y) - VERFIXEDVALUE);
    }
}

void Scroll::setValue(const QPoint &point)
{
    horizontalScrollBar()->setValue(horizontalScrollBar()->value() + point.x());
    verticalScrollBar()->setValue(verticalScrollBar()->value() + point.y());
}


