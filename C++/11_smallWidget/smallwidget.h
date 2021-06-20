#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);
    ~SmallWidget();

    //設置數字
    void setNum(int num);

    //獲取數字
    int getNum();

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
