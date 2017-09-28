#include "mylistwidget.h"
#include "Pointinfo.h"

#include <QMenu>
#include <QDebug>
#include <QMouseEvent>

MyListWidget::MyListWidget()
{

}

void MyListWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        QMenu menu;
        menu.addAction("删除", this, SLOT(removeRow()), QKeySequence::Backspace);
        menu.exec(QCursor::pos());
    }
    QListWidget::event(event);
}

void MyListWidget::removeRow()
{
    int row = currentRow();
    takeItem(row);
    emit deletePoint(row);
}

void MyListWidget::removeCurrentRow(int row)
{
    takeItem(row);
    emit deletePoint(row);
}

