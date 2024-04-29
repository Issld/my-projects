#include "clientobject.h"

ClientObject::ClientObject(QString surname, QString name, QString secname, QString phone, QString mail)
{
    this->surname = surname;
    this->name = name;
    this->secname = secname;
    this->phone = phone;
    this->mail = mail;
}

QString ClientObject::getSurname() //Получение поля
{
    return this->surname;
}

QString ClientObject::getName() //Получение поля
{
    return this->name;
}

QString ClientObject::getSecname() //Получение поля
{
    return this->secname;
}

QString ClientObject::getPhone() //Получение поля
{
    return this->phone;
}

QString ClientObject::getMail() //Получение поля
{
    return this->mail;
}
