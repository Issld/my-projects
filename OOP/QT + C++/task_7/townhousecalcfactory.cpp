#include <townhousecalcfactory.h>


BstractCalc* TownhouseCalcFactory :: Create() {
    return new TownhouseCalc(); //Указатель на тип продукта таун-хаус
}
