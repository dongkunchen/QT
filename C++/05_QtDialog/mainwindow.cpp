#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //點擊新建按鈕 彈出一個對話框
    connect(ui->actionNew,&QAction::triggered,[=](){
        //對話框 分類
        //模態對話框(不可以對其他窗口進行操作)
        //非模態對話框(可以對其他窗口進行操作)
        //模態創建
//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();

//        qDebug() << "模態對話框彈出了";

        //非模態對話框
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show();
//        //會一直創建新對象有內存問題
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug() << "非模態對話框彈出了";

        //消息對話框
        //錯誤對話框
//        QMessageBox::critical(this,"critical","錯誤");

        //信息對話框
//        QMessageBox::information(this,"info","信息");

        //詢問對話框
        //參數一 父 二 標題 三 提示內容 四 案件類型 五 默認鍵
//        if(QMessageBox::Save == QMessageBox::question(this,"ques","提問",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug() << "選擇的是保存";
//        }
//        else
//        {
//            qDebug() << "選擇的是取消";
//        }

        //警告對話框
//        QMessageBox::warning(this,"warning","警告");

        //其他標準對話框
        //顏色對話框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();

        //文件對話框
        //參數一 父 二 標題 三 默認打開路徑 四 過濾文件格式
//        QString str = QFileDialog::getOpenFileName(this,"打開文件","C:\\Users\\IG26\\Desktop","*.png");
//        qDebug() << str;

        //字體對話框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("新細明體",36));
        qDebug() << "字體: " << font.family().toUtf8().data() << " 大小: " << font.pointSize() << " 是否加粗: " << font.bold() << " 是否斜體: " << font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

