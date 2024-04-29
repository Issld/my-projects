#ifndef TOWNHOUSECALCFACTORY_H
#define TOWNHOUSECALCFACTORY_H

#include <calcfactory.h>
#include <townhousecalc.h>


class TownhouseCalcFactory : public CalcFactory
{
public:
    BstractCalc* Create(); //Создание продукта
};

#endif // TOWNHOUSECALCFACTORY_H
