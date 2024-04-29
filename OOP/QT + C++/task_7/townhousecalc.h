#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <estate.h>
#include <bstractcalc.h>

class TownhouseCalc : public BstractCalc {
Q_OBJECT
public:
    int getCost(Estate*); //Рассчет страховой стоимости
};

#endif // TOWNHOUSECALC_H
