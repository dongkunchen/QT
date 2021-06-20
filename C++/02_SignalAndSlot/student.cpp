#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "請老師吃飯";
}

void Student::treat(QString foodName)
{
    //輸出會"foodName" 有引號~ 先轉成QByArray(文檔) 使用.toUtf8()轉QByArray
    //qDebug() << "請老師吃飯,老師要吃: " << foodName;
    //解決引號
    qDebug() << "請老師吃飯,老師要吃: " << foodName.toUtf8().data();
}
