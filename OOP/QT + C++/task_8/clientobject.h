#ifndef CLIENTOBJECT_H
#define CLIENTOBJECT_H

#include <QObject>

class ClientObject : public QObject
{
    Q_OBJECT

public:
    ClientObject(QString, QString, QString, QString, QString);
    QString getSurname();
    QString getName();
    QString getSecname();
    QString getPhone();
    QString getMail();

private:
    QString surname;
    QString name;
    QString secname;
    QString phone;
    QString mail;
};

#endif // CLIENTOBJECT_H
