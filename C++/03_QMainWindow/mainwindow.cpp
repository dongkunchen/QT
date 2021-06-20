#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //菜單欄創建
    //菜單欄最多一個
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //創建菜單
    //也有返回值可接收 QMenu * fileMenu = bar->addMenu("文件");
    //不接手也可bar->addMenu("文件");
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("編輯");

    //創建菜單項
//    fileMenu->addAction("新建");
    QAction * newAction = fileMenu->addAction("新建");
    //添加分隔線
    fileMenu->addSeparator();
//    fileMenu->addAction("打開");
    QAction * openAction = fileMenu->addAction("打開");

    //工具欄 可以有多個
    QToolBar * toolBar = new QToolBar(this);
    //默認在上方查文檔(addToolBar)可以知道位置寫法
    //addToolBar(toolBar);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //只允許左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //設置浮動
    toolBar->setFloatable(false);

    //設置移動(總開關)將無法移動
    toolBar->setMovable(false);

    //工具欄中可以設置內容
    toolBar->addAction(newAction);
    //添加分隔線
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //工具欄添加控鍵
    QPushButton * btn = new QPushButton("關閉",this);
    toolBar->addWidget(btn);

    //狀態欄最多一個
    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);
    //放標籤控件
    QLabel * label = new QLabel("提示信息",this);
    stBar->addWidget(label);

    QLabel * label2 = new QLabel("右側提示信息",this);
    stBar->addPermanentWidget(label2);

    //鉚接部件(浮動窗口) 可以多個
    QDockWidget * dockWidget = new QDockWidget("浮動",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //設置後期停靠區域只允許上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //設置中心部件 假設用文本 只能一個
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

