#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //設置單選按鈕 男默認選中
    ui->rBtnMan->setChecked("true");

    //選種女後打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
       qDebug() << "選中了女了! ";
    });

    //多選按鈕 2選中 0未選中 組件tristate打勾可以半選 1
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    //利用listWidget寫詩
//    QListWidgetItem * item = new QListWidgetItem("鋤禾日當午");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter);
    //QStringList QList<QString>
    QStringList list;
    list << "鋤禾日當午" << "汗滴禾下土";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

