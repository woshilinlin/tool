#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>

class MyListWidget : public QListWidget
{
    Q_OBJECT

public:
    MyListWidget();

public slots:


private:
    void mousePressEvent(QMouseEvent *event);

signals:
    void deletePoint(int);

private slots:
    void removeRow();
    void removeCurrentRow(int row);

private:
    QString point;
};

#endif // MYLISTWIDGET_H
