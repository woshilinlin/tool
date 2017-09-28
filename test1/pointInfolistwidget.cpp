#include "pointInfolistwidget.h"

PointInfoListWidget::PointInfoListWidget()
{

}

void PointInfoListWidget::removeRow(int row)
{
    takeItem(row); //删除指定行
    emit deletePoint(row);
}

