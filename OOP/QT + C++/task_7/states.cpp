#include <states.h>

States::States(QObject *parent) : QObject(parent) {
    actualData = nullptr;
}

void States::add(Estate* obj) {
    Estate* newObj = new Estate(obj->TakeName(), obj->TakeAge(), obj->TakeClass(), obj->TakeSquare(), obj->TakeQuntity(), obj->TakeTime());
    mass.append(newObj);
    newObj = nullptr;
}

void States::undo() {
    if(!hasStates()){
        actualData = nullptr;
    }
    else{
        actualData = getActualData();
        mass.removeLast();
    }
    emit notifyObservers(); //Излучение сигнала для паттерна "Наблюдатель"
}

bool States::hasStates() {
    return !mass.isEmpty();
}

bool States::myHasStates() {
    if(mass.size() < 2){
        return 0;
    }
    return 1;
}

void States::Clear() {
    mass.clear();
}

Estate* States::getActualData() {
    if (!this->mass.isEmpty()) {
        return mass.at(mass.size() - 1);
    }
    else {
        return nullptr;
    }
}

States::~States() {
    if(actualData){
        delete actualData;
        actualData = nullptr;
    }
    qDeleteAll(mass);
    mass.clear();
}
