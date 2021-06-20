#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠標進入事件
    void enterEvent(QEnterEvent *event);

    //鼠標離開事件
    void leaveEvent(QEvent *);

    //鼠標按下事件重寫
    virtual void mousePressEvent(QMouseEvent *ev);

    //鼠標彈起事件重寫
    virtual void mouseReleaseEvent(QMouseEvent *ev);

    //鼠標移動事件重寫
    virtual void mouseMoveEvent(QMouseEvent *ev);

    //通過event事件分發器 攔截 鼠標按下事件
    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
