#include <estate.h>

Estate::Estate(QString name, int age, const EstateType& clases, int square, int quntity, int time) {
    this->name = name;
    this->age = age;
    this->clases = clases;
    this->square = square;
    this->quntity = quntity;
    this->time = time;
}

QString Estate::TakeName() {
    return this->name;
}
int Estate::TakeAge() {
    return this->age;
}
Estate::EstateType Estate::TakeClass() {
    return this->clases;
}
int Estate::TakeSquare() {
    return this->square;
}
int Estate::TakeQuntity() {
    return this->quntity;
}
int Estate::TakeTime() {
    return this->time;
}
