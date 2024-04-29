#include "calculation.h"

int ApartmentCalc::getCost(Estate* obj) {
    int cost = obj->TakeSquare() * 200;
    cost += obj->TakeSquare() * 2000;
    cost = obj->TakeTime();
    return (obj->TakeSquare() * 200 + obj->TakeQuntity() * 2000) * obj->TakeTime();
}

int CottageCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 500 + obj->TakeQuntity() * 5000) * obj->TakeTime();
}

int LuxuriousApartmentCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 400 + obj->TakeQuntity() * 4000) * obj->TakeTime();
}

int TownhouseCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 300 + obj->TakeQuntity() * 3000) * obj->TakeTime();
}
