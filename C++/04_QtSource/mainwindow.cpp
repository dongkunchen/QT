#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->actionNew->setIcon(QIcon("E:/code/icon/Luffy.png"));
    //: + 前名(/)
    ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionOpen->setIcon(QIcon(":/Image/LuffyQ.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

