#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject
{
Q_OBJECT
public:
    enum class EstateType { ECONOM, LUXURIOUS, TOWN_HOUSE, COTTAGE };
    Estate(QString, int, const EstateType&, int, int, int);
    QString TakeName();
    int TakeAge();
    EstateType TakeClass();
    int TakeSquare();
    int TakeQuntity();
    int TakeTime();

private:
    QString name;
    int age;
    EstateType clases;
    int square;
    int quntity;
    int time;
};

#endif // ESTATE_H
