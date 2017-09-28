#ifndef SCROLL_H
#define SCROLL_H

#include <QScrollArea>

class LabelScroll : public QScrollArea
{
    Q_OBJECT
public:
    LabelScroll();
    ~LabelScroll();

private slots:

    /*!
     * \brief getHorValue 获取水平滚动条的值
     * \param x 水平值
     */
    void getHorValue(int x) const;

    /*!
     * \brief getVerValue 获取垂直滚动条的值
     * \param y 垂直值
     */
    void getVerValue(int y) const;

public slots:
    /*!
     * \brief setHorValue 设置水平滚动条
     * \param horMul 水平方向比例
     */
    void setHorValue(double hormultiple);

    /*!
     * \brief setVerValue 设置垂直滚动条
     * \param verMul 垂直方向比例
     * \param delta 滚轮的值(用于判断正负)
     */
    void setVerValue(double vermultipe, int delta);

    /*!
     * \brief setValue 设置水平和垂直滚动条
     * \param point 点坐标
     */
    void setValue(const QPoint & point);
};

#endif // SCROLL_H
