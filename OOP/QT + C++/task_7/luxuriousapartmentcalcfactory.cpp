#include <luxuriousapartmentcalcfactory.h>

BstractCalc* LuxuriousApartmentCalcFactory :: Create() {
    return new LuxuriousApartmentCalc(); //Указатель на тип продукта элитная кватрира
}
