#include "clientlist.h"

ClientList::ClientList(QObject *parent) : QObject(parent)
{

}

void ClientList::Add(ClientObject* obj) //Добавление
{
    mass.append(obj);
}

void ClientList::Delete(int index) //Удаление
{
    mass.remove(index - 1);
}

int ClientList::getSize() //Получение размера массива
{
    return mass.size();
}

ClientObject* ClientList::getObject(int index) //Получение объекта
{
    return mass[index];
}

ClientList::~ClientList()
{
    qDeleteAll(mass);
    mass.clear();
}
