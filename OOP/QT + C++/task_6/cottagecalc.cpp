#include <cottagecalc.h>

int CottageCalc::getCost(Estate* obj) {
    return (obj->TakeSquare() * 500 + obj->TakeQuntity() * 5000) * obj->TakeTime();
}
