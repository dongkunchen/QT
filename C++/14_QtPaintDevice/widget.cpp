#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Pixamp繪圖設備
//    QPixmap pix(300,300);

//    //填充背景顏色默認黑色
//    pix.fill(Qt::white);

//    //聲明畫家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    pix.save("E:\\pix.png");

    //QImage 繪圖設備 可以對像素訪問 其他跟上面pix差不多
//    QImage img(300,300,QImage::Format_RGB32);
//    //填充背景顏色默認黑色
//    img.fill(Qt::white);

//    //聲明畫家
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    img.save("E:\\img.png");


    //QPicture繪圖設備不是用來畫畫 可以紀錄和重現繪圖指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150),100,100);
    painter.end();//結束畫畫

    //保存
    pic.save("E:\\pic.zt");

}

void Widget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    //利用Qimage 對像素修改;
//    QImage img;
//    img.load(":/Image/Luffy.png");

//    //修改像素點
//    for(int i = 50;i < 100; i++)
//    {
//        for(int j = 50 ; j < 100 ; j++)
//        {
//            QRgb value = qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }

//    painter.drawImage(0,0,img);

    QPainter painter(this);
    //重現QPicture的繪圖指令
    QPicture pic;
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);

}

Widget::~Widget()
{
    delete ui;
}

