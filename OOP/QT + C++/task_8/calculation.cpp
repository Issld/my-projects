#include "calculation.h"

int CalcMechanical::getCost(CarObject* obj) //Рассчет стоимости для механической коробки передач
{
    return (obj->getPower() * 50 + (obj->getYear() - 1990) * 1000 + 500000);
}

int CalcAutomatic::getCost(CarObject* obj) //Рассчет стоимости для автоматической коробки передач
{
    return (obj->getPower() * 50 + (obj->getYear() - 1990) * 1000 + 1000000);
}

int CalcVariator::getCost(CarObject* obj) //Рассчет стоимости для вариатора
{
    return (obj->getPower() * 50 + (obj->getYear() - 1990) * 1000 + 1500000);
}

int CalcRobotic::getCost(CarObject* obj) //Рассчет стоимости для роботизированной коробки передач
{
    return (obj->getPower() * 50 + (obj->getYear() - 1990) * 1000 + 750000);
}
