#ifndef CARLIST_H
#define CARLIST_H

#include <QObject>
#include <carobject.h>

class CarList : public QObject
{
    Q_OBJECT

public:
    explicit CarList(QObject *parent = nullptr);
    ~CarList();
    void Add(CarObject *value);
    void Delete(int);
    int getSize();
    CarObject* getObject(int);

private:
    QList<CarObject*> mass;
};

#endif // CARLIST_H
