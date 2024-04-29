#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QList>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = nullptr);
    int count = 0;
    QList<int> mass;

public slots:
    int Summ();
    int SummEven();
    void Task_1();
    QList <int> Check_task();
    int Task_2();

};

#endif // DATA_H
