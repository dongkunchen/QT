#include "smallwidget.h"
#include "ui_smallwidget.h"


SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QSpinBox移動 QSlider跟著移動
    //因為有重載有同樣(個數參數)的函數無法知道用那個參數函數不能直接&QSpinBox::valueChanged
//    connect(ui->spinBox,&QSpinBox::valueChanged,ui->horizontalSlider,&QSlider::setValue);
    //指針指向int才知道要用那個函數
    void(QSpinBox:: * spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);

    //反向 QSilder滑動 QSpinBox數字要跟著動
    //因為重載只有一個單個參數函數所以傳一個值必定是掉那個函數所以不用額外指針去指定
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}

//設置數字
void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

//獲取數字
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}


SmallWidget::~SmallWidget()
{
    delete ui;
}
