#include "shopobject.h"

ShopObject::ShopObject(QString model, int price, QString date, QString fio, QString phone, QString justModel) {
    this->model = model;
    this->price = price;
    this->date = date;
    this->fio = fio;
    this->phone = phone;
    this->justModel = justModel;
}

QString ShopObject::getModel() //Получение поля
{
    return this->model;
}

int ShopObject::getPrice() //Получение поля
{
    return this->price;
}

QString ShopObject::getDate() //Получение поля
{
    return this->date;
}

QString ShopObject::getFio() //Получение поля
{
    return this->fio;
}

QString ShopObject::getPhone() //Получение поля
{
    return this->phone;
}

QString ShopObject::getJustModel() //Получение поля
{
    return this->justModel;
}
