#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <estate.h>
#include <bstractcalc.h>

class ApartmentCalc :public BstractCalc {
    Q_OBJECT
public:
    int getCost(Estate*); //Рассчет страховой стоимости
};

#endif // APARTMENTCALC_H
