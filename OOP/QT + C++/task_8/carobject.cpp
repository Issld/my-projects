#include "carobject.h"

CarObject::CarObject(QString label, QString model, int year, const GearType& gearbox, int power, bool view)
{
    this->label = label;
    this->model = model;
    this->year = year;
    this->gearbox = gearbox;
    this->power = power;
    this->view = view;
}

QString CarObject::getLabel() //Получение поля
{
    return this->label;
}

QString CarObject::getModel() //Получение поля
{
    return this->model;
}

int CarObject::getYear() //Получение поля
{
    return this->year;
}

CarObject::GearType CarObject::getGearbox() //Получение поля
{
    return this->gearbox;
}

int CarObject::getPower() //Получение поля
{
    return this->power;
}

bool CarObject::getView() //Получение поля
{
    return this->view;
}

void CarObject::setVisible() //Установка видимости объекта
{
    this->view = 1;
}

void CarObject::setInvisible() //Установка невидимости объекта
{
    this->view = 0;
}
