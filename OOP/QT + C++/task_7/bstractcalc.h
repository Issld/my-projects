#ifndef BSTRACTCALC_H
#define BSTRACTCALC_H

#include <QObject>
#include <estate.h>

class BstractCalc : public QObject
{
    Q_OBJECT
public:
    explicit BstractCalc(QObject *parent = nullptr);
    virtual int getCost(Estate *value) = 0; //Виртуальная функция рассчета страховой стоимости (реализация в наследниках)
};

#endif //BSTRACTCALC_H
