#include "carlist.h"

CarList::CarList(QObject *parent) : QObject(parent)
{

}

void CarList::Add(CarObject* obj) //Добавление
{
    mass.append(obj);
}

void CarList::Delete(int index) //Удаление
{
    mass.remove(index - 1);
}

int CarList::getSize() //Получение размера массива
{
    return mass.size();
}

CarObject* CarList::getObject(int index) //Получение объекта
{
    return mass[index];
}

CarList::~CarList()
{
    qDeleteAll(mass);
    mass.clear();
}
