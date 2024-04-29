#ifndef LUXURIOUSAPARTMENTCALCFACTORY_H
#define LUXURIOUSAPARTMENTCALCFACTORY_H

#include <calcfactory.h>
#include <luxuriousapartmentcalc.h>

class LuxuriousApartmentCalcFactory : public CalcFactory
{
public:
    BstractCalc* Create(); //Создание продукта
};

#endif // LUXURIOUSAPARTMENTCALCFACTORY_H
