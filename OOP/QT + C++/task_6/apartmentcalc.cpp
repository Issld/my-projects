#include <apartmentcalc.h>

int ApartmentCalc::getCost(Estate* obj) {
    int cost = obj->TakeSquare() * 200;
    cost += obj->TakeSquare() * 2000;
    cost = obj->TakeTime();
    return (obj->TakeSquare() * 200 + obj->TakeQuntity() * 2000) * obj->TakeTime();
}
