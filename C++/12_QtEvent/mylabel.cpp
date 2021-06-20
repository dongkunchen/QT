#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //鼠標追蹤
    setMouseTracking(true);
}


void myLabel::enterEvent(QEnterEvent *event)
{
    //qDebug() << "鼠標進入了";
}

void myLabel::leaveEvent(QEvent *)
{
    //qDebug() << "鼠標離開了";
}

//鼠標按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //*ev能拿到信息包含QMouseEvent global相對螢幕位置
//    QString str = QString("鼠標按下了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//    qDebug() << "str";
    //增加鼠標左鍵才動作
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠標按下了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

//鼠標彈起
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠標彈起了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

//鼠標移動(點下移動才有效果)
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //1.button改bottns
    //要改使用位址 因為值會變 位址指向固定
    //要按下才會動 如果要實現進入就顯示要設定鼠標追蹤
//    if(ev->buttons() & Qt::LeftButton)
//    {
//        QString str = QString("鼠標按下了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//        qDebug() << str;
//    }
    //配合鼠標追蹤把左鍵功能去除
    QString str = QString("鼠標移動了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

bool myLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event函數中,鼠標按下了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
        return true;
    }
    return QLabel::event(e);
}
