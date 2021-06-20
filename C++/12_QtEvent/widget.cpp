#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //啟動定時器
    id1 = startTimer(1000);//參數1 間隔 單位 毫秒
    id2 = startTimer(2000);

    //定時器第二種方式
    QTimer * timer = new QTimer(this);
    //啟動定時器
    timer->start(500);

    connect(timer,&QTimer::timeout,[=](){
       static int num = 1;
       ui->label_4->setText(QString::number(num++));
    });

    connect(ui->btn,&QPushButton::clicked,[=](){
       timer->stop();
    });

    //給lebel1 安裝事件過濾器
    //步驟1
    ui->label->installEventFilter(this);


}

//步驟2 重寫eventFilter事件
bool Widget::eventFilter(QObject * obj, QEvent * e)
{
    if(obj == ui->label)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent * ev = static_cast<QMouseEvent *>(e);
            QString str = QString("Filter函數中,鼠標按下了 x = %1 y = %2 globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;
            return true;
        }
    }
    return QWidget::eventFilter(obj,e);
}

//定時器實現
void Widget::timerEvent(QTimerEvent * ev)
{
    if(ev->timerId() == id1)
    {
    static int num = 1;
    ui->label_2->setText(QString::number(num++));
    }
    if(ev->timerId() == id2)
    {
    static int num2 = 1;
    ui->label_3->setText(QString::number(num2++));
    }
}

Widget::~Widget()
{
    delete ui;
}


