#ifndef SCROLL_H
#define SCROLL_H

#include <QScrollArea>

class Label;
class QLabel;

class Scroll : public QScrollArea
{
    Q_OBJECT
public:
    Scroll();
    ~Scroll();

private slots:
    void getHorValue(int x);
    void getVerValue(int y);

public slots:
    void setHorValue(double x);
    void setVerValue(double y, int delta);

    void setValue(const QPoint & point);
};

#endif // SCROLL_H
