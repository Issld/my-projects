#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include <estate.h>

class LuxuriousApartmentCalc : public QObject {
    Q_OBJECT
public:
    static int getCost(Estate*);
};

#endif // LUXURIOUSAPARTMENTCALC_H
