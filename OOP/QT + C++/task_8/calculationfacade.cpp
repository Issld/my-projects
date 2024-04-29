#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent) {

}

int CalculationFacade::getCost(CarObject *value) { //Фасад рассчета стоимости
    int cost;
    switch (value->getGearbox()) {
    case CarObject::GearType::MECHANICAL:
        cost = CalcMechanical::getCost(value);
        break;
    case CarObject::GearType::AUTOMATIC:
        cost = CalcAutomatic::getCost(value);
        break;
    case CarObject::GearType::VARIATOR:
        cost = CalcVariator::getCost(value);
        break;
    case CarObject::GearType::ROBOTIC:
        cost = CalcRobotic::getCost(value);
        break;
    default:
        cost = -1;
        break;
    }
    return cost;
}
