#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <estate.h>
#include <bstractcalc.h>

class CottageCalc : public BstractCalc {
    Q_OBJECT
public:
    int getCost(Estate*); //Рассчет страховой стоимости
};

#endif // COTTAGECALC_H
