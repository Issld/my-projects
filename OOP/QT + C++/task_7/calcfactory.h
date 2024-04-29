#ifndef CALCFACTORY_H
#define CALCFACTORY_H

#include <QObject>
#include <apartmentcalc.h>
#include <luxuriousapartmentcalc.h>
#include <cottagecalc.h>
#include <townhousecalc.h>
#include <bstractcalc.h>

class CalcFactory : public QObject
{
    Q_OBJECT
public:
    explicit CalcFactory(QObject *parent = nullptr);
    virtual BstractCalc* Create() = 0; //Виртуальная функция создания продукта (реализация в наследниках)
};

#endif //CALCFACTORY_H
