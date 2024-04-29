#include <townhousecalc.h>

int TownhouseCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 300 + obj->TakeQuntity() * 3000) * obj->TakeTime();
}
