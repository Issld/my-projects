#ifndef CALCULATION_H
#define CALCULATION_H


#include <QObject>
#include <estate.h>

class ApartmentCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

class CottageCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

class LuxuriousApartmentCalc : public QObject {
    Q_OBJECT
public:
    static int getCost(Estate*);
};

class TownhouseCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

#endif // CALCULATION_H
