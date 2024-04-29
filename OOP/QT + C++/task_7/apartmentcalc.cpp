#include <apartmentcalc.h>

int ApartmentCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 200 + obj->TakeQuntity() * 2000) * obj->TakeTime();
}
