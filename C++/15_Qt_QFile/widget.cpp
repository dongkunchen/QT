#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
       QString path = QFileDialog::getOpenFileName(this,"打開文件","C:\\Users\\IG26\\Desktop");
       //將路徑放入line Edit中
       ui->lineEdit->setText(path);

       //編碼格式類導入QTextCodec在 5.15以後 pro 還要加上 QT += core5compat
       QTextCodec * codec = QTextCodec::codecForName("gbk");

       //讀取內容放入text Edit中
       //QFile默認支持格式是 utf-8
       QFile file(path);
       //設置打開方式
       file.open(QIODevice::ReadOnly);
//       QByteArray array = file.readAll();
       QByteArray array;
       while(!file.atEnd())
       {
       array += file.readLine(); //按行讀
       }
       //將讀取到的數據放入text Edit
//       ui->textEdit->setText(array);
       ui->textEdit->setText(codec->toUnicode(array));

       //對文件對象關閉
       file.close();

       //進行寫文件
//       file.open(QIODevice::Append);
//       file.write("追加文字");
//       file.close();
       //QFileInfo 文件信息類
       QFileInfo info(path);

       qDebug() << "大小: " << info.size() << " 後綴名: " << info.suffix() << " 文件名稱: " << info.fileName() << " 文件路徑: " << info.filePath();
       qDebug() << "創建日期: " << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");//因要顯示要包含QDatetime 舊版用created()
       qDebug() << "最後修改日期: " << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

