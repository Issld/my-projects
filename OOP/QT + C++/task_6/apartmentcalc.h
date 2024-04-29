#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <QObject>
#include <estate.h>

class ApartmentCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

#endif // APARTMENTCALC_H
