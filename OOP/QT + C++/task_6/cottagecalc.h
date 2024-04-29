#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <QObject>
#include <estate.h>

class CottageCalc : public QObject {
Q_OBJECT
public:
    static int getCost(Estate*);
};

#endif // COTTAGECALC_H
