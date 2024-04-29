#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent) {

}

int CalculationFacade::getCost(Estate *value) {
    int cost;
    switch (value->TakeClass()) {
    case Estate::EstateType::ECONOM:
        cost = ApartmentCalc::getCost(value);
        break;
    case Estate::EstateType::LUXURIOUS:
        cost = LuxuriousApartmentCalc::getCost(value);
        break;
    case Estate::EstateType::TOWN_HOUSE:
        cost = TownhouseCalc::getCost(value);
        break;
    case Estate::EstateType::COTTAGE:
        cost = CottageCalc::getCost(value);
        break;
    default:
        cost = -1;
        break;
    }
    return cost;
}
