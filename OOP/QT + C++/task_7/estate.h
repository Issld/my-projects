#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject
{
Q_OBJECT
public:
    enum class EstateType { ECONOM, LUXURIOUS, TOWN_HOUSE, COTTAGE }; //Объявление своих типов
    Estate(QString, int, const EstateType&, int, int, int);
    QString TakeName(); //Получение имени съемщика
    int TakeAge(); //Получение возраста съемщика
    EstateType TakeClass(); //Получение типа жилья
    int TakeSquare(); //Получение площади жилья
    int TakeQuntity(); //Получение количества проживающих людей
    int TakeTime(); //Получение срока страхования

private:
    QString name;
    int age;
    EstateType clases;
    int square;
    int quntity;
    int time;
};

#endif // ESTATE_H
