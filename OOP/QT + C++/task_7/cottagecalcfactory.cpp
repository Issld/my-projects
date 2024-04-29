#include <cottagecalcfactory.h>

BstractCalc* CottageCalcFactory :: Create() {
    return new CottageCalc(); //Указатель на тип продукта коттедж
}
