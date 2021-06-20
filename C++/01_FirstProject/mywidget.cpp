#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //創建按鈕
    QPushButton * btn = new QPushButton;

    //另開一個新視窗出現按鈕
    //btn->show();

    //按鈕設置窗口內
    btn->setParent(this);

    //顯示按鈕文字
    btn->setText("第一個按鈕");
    //創建第二個按鈕
    QPushButton * btn2 = new QPushButton("第二個按鈕",this);

    //移動btn2按鈕
    btn2->move(100,100);
    //設置按鈕大小
    btn2->resize(50,50);

    //因第二種創建方法會縮成按鈕大小重置窗口大小;
    resize(600,400);

    //將窗口大小固定
    setFixedSize(600,400);

    //設置窗口標題
    setWindowTitle("第一個窗口");

    MyPushButton * myBtn = new MyPushButton;

    myBtn->setParent(this);

    myBtn->setText("我的按鈕");

    myBtn->move(200,0);

    //點擊關閉窗口
    //參數1 信號發送者 參數2 發送的信號(地址&) 圖標信號燈
    //參數3 信號接收者 參數4 信號的處理者(槽函數地址&) 圖標有凹槽
    //connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);
    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
}

myWidget::~myWidget()
{
    qDebug() << "myWidget析購調用";
}

