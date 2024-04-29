#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>
#include <carobject.h>
#include <calculation.h>

class CalculationFacade : public QObject
{
    Q_OBJECT

public:
    explicit CalculationFacade(QObject *parent = nullptr);
    static int getCost(CarObject *value);
};

#endif // CALCULATIONFACADE_H
