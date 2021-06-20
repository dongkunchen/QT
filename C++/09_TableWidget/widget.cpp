#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件
    //設置列數
    ui->tableWidget->setColumnCount(3);

    //設置水平表頭
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性別"<<"年齡");

    //設置行數
    ui->tableWidget->setRowCount(5);

    //設置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亞瑟"));
    QStringList nameList;
    nameList<<"亞瑟"<<"趙雲"<<"張飛"<<"關羽"<<"花木蘭";

    QList<QString> sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"女";

    for (int i = 0 ; i < 5 ; i ++ )
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(QString::number(18+i)));
    }
}

Widget::~Widget()
{
    delete ui;
}

