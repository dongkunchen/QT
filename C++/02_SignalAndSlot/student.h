#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //早期要寫在public slots:下現在只要寫在public下
    //需要聲明需要實現 可以有參可以重載
    void treat();

    void treat(QString foodName);

signals:

};

#endif // STUDENT_H
