#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <QObject>
#include <estate.h>

class TownhouseCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

#endif // TOWNHOUSECALC_H
