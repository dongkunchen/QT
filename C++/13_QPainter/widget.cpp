#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //點擊移動圖片
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //如果要手動調用繪圖事件 用update更新
        posX+=20;
        update();
        //自動可以用timer達成
    });
}

//步驟二重寫(要包含QPainter)
void Widget::paintEvent(QPaintEvent *)
{
//    //實力化畫家對象 this指向繪圖設備
//    QPainter painter(this);
//    //設置畫筆(顏色)
//    QPen pen(QColor(255,0,0));
//    //設置筆寬
//    pen.setWidth(10);
//    //設置筆寬風格(虛線)
//    pen.setStyle(Qt::DotLine);
//    //讓畫家使用這個筆
//    painter.setPen(pen);

//    //設置畫刷(填充顏色)
//    QBrush brush(Qt::cyan);
//    //設置畫刷風格(填滿變點點查文檔很多不同風格)
//    brush.setStyle(Qt::Dense7Pattern);
//    //讓畫家使用畫刷
//    painter.setBrush(brush);

//    //畫線
//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    //畫圓
//    painter.drawEllipse(QPoint(100,100), 100,50);
//    painter.drawEllipse(QPoint(300,100), 100,100);
//    //畫矩形(20,20)位置畫長50寬50
//    painter.drawRect(QRect(20,20,50,50));
//    //畫文字
//    painter.drawText(QRect(10,200,100,50),"好好學習,天天向上");


    //高級設置///////
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //設置抗鋸齒能力(毛邊) 但效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

    //畫矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //移動畫家到(100,0)開始畫
//    painter.translate(100,0);

//    //保存狀態
//    painter.save();

//    painter.drawRect(QRect(20,20,50,50));

//    painter.translate(100,0);

//    //還原狀態(會回到原點)第三個會跟第一個重疊
//    painter.restore();

//    painter.drawRect(QRect(20,20,50,50));

    //利用畫家畫資源圖片
    QPainter painter(this);
    //從20,0畫
//    painter.drawPixmap(20,0,QPixmap(":/Image/Luffy.png"));
    if(posX > this->width())
    {
        posX = 0;
    }
    painter.drawPixmap(posX,0,QPixmap(":/Image/Luffy.png"));


}

Widget::~Widget()
{
    delete ui;
}

