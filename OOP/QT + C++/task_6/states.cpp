#include "states.h"

States::States(QObject *parent) : QObject(parent) {
    actualData = nullptr;
}

void States::add(Estate* obj) {
    Estate* newest = new Estate(obj->TakeName(), obj->TakeAge(), obj->TakeClass(), obj->TakeSquare(), obj->TakeQuntity(), obj->TakeTime());
    mass.append(newest);
    newest = nullptr;
}

void States::undo() {
    if(!hasStates()){
        actualData = nullptr;
    }
    else{
        actualData = mass.takeAt(mass.size() - 1);
        //mass.removeLast();
    }
    emit notifyObservers();
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
