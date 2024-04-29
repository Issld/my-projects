#include <calculationfacade.h>

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent) {

}

//Рассчет для остальных типов аналогичен рассчету для продукта типа эконом

int CalculationFacade::getCost(Estate *value) {
    int cost;
    switch (value->TakeClass()) {
    case Estate::EstateType::ECONOM: {
        ApartmentCalcFactory factory;
        auto obj = factory.Create(); //Создание продукта
        cost = obj->getCost(value); //Рассчет в соответствии с типом продукта
        break;
    }
    case Estate::EstateType::LUXURIOUS: {
        LuxuriousApartmentCalcFactory factory;
        auto obj = factory.Create();
        cost = obj->getCost(value);
        break;
    }
    case Estate::EstateType::TOWN_HOUSE: {
        TownhouseCalcFactory factory;
        auto obj = factory.Create();
        cost = obj->getCost(value);
        break;
    }
    case Estate::EstateType::COTTAGE: {
        CottageCalcFactory factory;
        auto obj = factory.Create();
        cost = obj->getCost(value);
        break;
    }
    default:
        cost = -1;
        break;
    }
    return cost;
}
