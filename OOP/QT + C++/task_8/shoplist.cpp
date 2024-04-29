#include "shoplist.h"

ShopList::ShopList(QObject *parent) : QObject(parent)
{

}

void ShopList::Add(ShopObject* obj) //Добавление
{
    mass.append(obj);
}

void ShopList::Delete(int index) //Удаление
{
    mass.remove(index);
}

int ShopList::getSize() //Получение размера массива
{
    return mass.size();
}

ShopObject* ShopList::getObject(int index) //Получение объекта
{
    return mass[index];
}

ShopList::~ShopList()
{
    qDeleteAll(mass);
    mass.clear();
}
