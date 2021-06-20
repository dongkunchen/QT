#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我得按鈕類構造調用";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "我的按鈕析購調用";
}
