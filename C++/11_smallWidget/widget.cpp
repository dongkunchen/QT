#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //點擊獲取
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->getNum();
    });

    //設置數字
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
    });

}

Widget::~Widget()
{
    delete ui;
}

