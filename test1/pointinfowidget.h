#ifndef POINTINFOWIDGET_H
#define POINTINFOWIDGET_H

#include <QWidget>

namespace Ui {
class PointInfowidget;
}

/*!
 * \brief The Point struct
 * 点的结构体(包含点的名字，在label上的坐标，和实际测量的三维坐标）
 */
struct Point
{
    QString x;
    QString y;
    QString name;

    double real_x;
    double real_y;
    double real_z;
};

/*!
 * \brief The LineEditGradation enum
 * 三维坐标的输入顺序枚举类型
 */
enum LineEditGradation
{
    XLINEEDIT,
    YLINEEDIT,
    ZLINEEDIT
};


class PointInfowidget : public QWidget
{
    Q_OBJECT

public:
    explicit PointInfowidget(QWidget *parent = 0);
    ~PointInfowidget();

    /*!
     * \brief getPointInfo 获取点的所有信息
     * \return  返回结构体Point
     */
    Point getPointInfo() const;

    /*!
     * \brief setPointInfo 设置点的二位坐标信息和点名字
     * \param points  点的信息
     */
    void setPointInfo(const Point &point);

signals:
    /*!
     * \brief currentRow 当前行信号
     */
    void currentRow(int);

private slots:
    /*!
     * \brief deletePointItem 响应删除按钮的槽函数
     */
    void deletePointItem();

private:
    Ui::PointInfowidget *ui;
};

#endif // POINTINFOWIDGET_H
