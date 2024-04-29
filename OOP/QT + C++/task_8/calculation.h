#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>
#include <carobject.h>

class CalcMechanical : public QObject
{
    Q_OBJECT

public:
    static int getCost(CarObject*);
};

class CalcAutomatic : public QObject
{
    Q_OBJECT

public:
    static int getCost(CarObject*);
};

class CalcVariator : public QObject
{
    Q_OBJECT

public:
    static int getCost(CarObject*);
};

class CalcRobotic : public QObject
{
    Q_OBJECT

public:
    static int getCost(CarObject*);
};

#endif // CALCULATION_H
