
#ifndef SHOPOBJECT_H
#define SHOPOBJECT_H


#include <QObject>
#include <carobject.h>
#include <clientobject.h>

class ShopObject : public QObject
{
    Q_OBJECT

public:
    ShopObject(QString, int, QString, QString, QString, QString);
    QString getModel();
    int getPrice();
    QString getDate();
    QString getFio();
    QString getPhone();
    QString getJustModel();

private:
    QString model;
    int price;
    QString date;
    QString fio;
    QString phone;
    QString justModel;
};

#endif // SHOPOBJECT_H
