#include <luxuriousapartmentcalc.h>

int LuxuriousApartmentCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 400 + obj->TakeQuntity() * 4000) * obj->TakeTime();
}
