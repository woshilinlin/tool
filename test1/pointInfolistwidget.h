#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>

class PointInfoListWidget : public QListWidget
{
    Q_OBJECT

public:
    PointInfoListWidget();

signals:
    void deletePoint(int); //删除列表中的点和点信息

public slots:
    /*!
     * \brief removeRow 删除当前行
     * \param row 点前点所在的行数
     */
    void removeRow(int row);
};

#endif // MYLISTWIDGET_H
