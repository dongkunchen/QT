#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

//Teacher類
//Student類

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //創建一個老師對象
    this->zt = new Teacher(this);
    //創建學生對象
    this->st = new Student(this);
    //老師餓了 學生請客(無參)
//    connect(zt,&Teacher::hungry,st,&Student::treat);
//    //調用下課函數
//    classIsOver();
    //有參
    //指針 -> 地址
    //函數指針 -> 函數地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
//    connect(zt,&Teacher::hungry,st,&Student::treat);
    connect(zt,teacherSignal,st,studentSlot);
    //classIsOver();

    QPushButton * btn = new QPushButton("下課",this);

    this->resize(600,400);

    //點擊觸發下課
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //無參信號和"槽"連接
    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(zt,teacherSignal2,st,studentSlot2);

    //信號連接"信號"
    connect(btn,&QPushButton::clicked,zt,teacherSignal2);

    //斷開信號
    //disconnect(zt,teacherSignal2,st,studentSlot2);

    //擴展
    //1.信號可以連接信號
    //2.一個信號可以連接多個槽函數
    //3.多個信號可以連接同一個槽函數
    //4.信號和槽函數的參數 必須類型一一對應
    //5.信號和槽的參數個數 信號可以多於槽函數(類型也必須一一對應) 但反之不行
    //Qt4以前信號連接方式
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //Qt4版本優點參數直觀 缺點 類型不做檢測 參數不同也能編譯成功但是點擊沒效果

    //Lambda[&]引用[=]值傳遞都可以但用值傳遞佳
    //可以只傳單個[btn]
//    [=](){
//        btn->setText("aaaaa");
//    }();

    QPushButton * btn2 = new QPushButton;
    btn2->setText("關閉");
    btn2->move(100,0);
    btn2->setParent(this);
    //connect(btn2,&QPushButton::clicked,this,[=](){
    connect(btn2,&QPushButton::clicked,[=](){
//        this->close();
//        emit zt->hungry("宮保雞丁");
        btn2->setText("aaaaa");
    });

}

void Widget::classIsOver()
{
    //emit zt->hungry();
    emit zt->hungry("宮保雞丁");
}

Widget::~Widget()
{
    delete ui;
}

