#ifndef COTTAGECALCFACTORY_H
#define COTTAGECALCFACTORY_H

#include <calcfactory.h>
#include <apartmentcalc.h>

class CottageCalcFactory : public CalcFactory
{
public:
    BstractCalc* Create(); //Создание продукта

};

#endif // COTTAGECALCFACTORY_H
