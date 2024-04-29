#ifndef CAROBJECT_H
#define CAROBJECT_H

#include <QObject>

class CarObject : public QObject
{
    Q_OBJECT

public:
    enum class GearType { MECHANICAL, AUTOMATIC, VARIATOR, ROBOTIC };
    CarObject(QString, QString, int, const GearType&, int, bool);
    QString getLabel();
    QString getModel();
    int getYear();
    GearType getGearbox();
    int getPower();
    bool getView();
    void setVisible();
    void setInvisible();

private:
    QString label;
    QString model;
    int year;
    GearType gearbox;
    int power;
    bool view;
};

#endif // CAROBJECT_H
