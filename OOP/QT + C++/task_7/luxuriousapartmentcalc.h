#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <estate.h>
#include <bstractcalc.h>

class LuxuriousApartmentCalc : public BstractCalc {
    Q_OBJECT
public:
    int getCost(Estate*); //Рассчет страховой стоимости
};

#endif // LUXURIOUSAPARTMENTCALC_H
