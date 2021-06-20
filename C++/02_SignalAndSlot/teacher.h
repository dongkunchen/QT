#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
//自定義信號寫在singnals下只要聲明不用實現可以有參可以重載
    void hungry();

    void hungry(QString foodName);
};

#endif // TEACHER_H
