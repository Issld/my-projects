#include <apartmentcalcfactory.h>

BstractCalc* ApartmentCalcFactory :: Create() {
    return new ApartmentCalc(); //Указатель на тип продукта квартира эконом-класса
}
