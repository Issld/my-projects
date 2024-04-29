#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>
#include <estate.h>
#include <apartmentcalcfactory.h>
#include <luxuriousapartmentcalcfactory.h>
#include <townhousecalcfactory.h>
#include <cottagecalcfactory.h>
#include <calcfactory.h>

class CalculationFacade : public QObject {
Q_OBJECT
public:
    explicit CalculationFacade(QObject *parent = nullptr);
    static int getCost(Estate *value); //Рассчет итоговой стоимости
};

#endif // CALCULATIONFACADE_H
