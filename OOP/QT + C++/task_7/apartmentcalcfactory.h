#ifndef APARTMENTCALCFACTORY_H
#define APARTMENTCALCFACTORY_H

#include <calcfactory.h>
#include <apartmentcalc.h>

class ApartmentCalcFactory : public CalcFactory
{
public:
    BstractCalc* Create(); //Создание продукта
};

#endif // APARTMENTCALCFACTORY_H
