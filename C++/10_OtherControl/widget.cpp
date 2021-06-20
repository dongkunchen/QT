#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Stacked Widget控建操作


    //設置默認值
    ui->stackedWidget->setCurrentIndex(0);

    //ScrollArea按鈕
    connect(ui->btn_ScrollArea,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    //ToolBox按鈕
    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    //TabWidget按鈕
    connect(ui->btn_TabWidget,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //Frame加邊框 Widget布局 Dock Widget浮動框
    //combo box下拉框
    ui->comboBox->addItem("特斯拉");
    ui->comboBox->addItem("福斯");
    ui->comboBox->addItem("豐田");

    //點擊按鈕 選中福斯
    connect(ui->btn_Select,&QPushButton::clicked,[=](){
        //方法1
//        ui->comboBox->setCurrentIndex(1);
        //方法2
        ui->comboBox->setCurrentText("福斯");
    });

    //利用QLabel顯示圖片
    ui->lbl_Image->setPixmap(QPixmap(":/Image/butterfly.png"));

    //利用QLabel顯示gif小動畫
    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->lbl_movie->setMovie(movie);
    //要啟動才會撥放
    movie->start();

}

Widget::~Widget()
{
    delete ui;
}

