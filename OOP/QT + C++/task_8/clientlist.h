#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include <QObject>
#include <clientobject.h>

class ClientList : public QObject
{
    Q_OBJECT

public:
    explicit ClientList(QObject *parent = nullptr);
    ~ClientList();
    void Add(ClientObject *value);
    void Delete(int);
    int getSize();
    ClientObject* getObject(int);

private:
    QList<ClientObject*> mass;
};



#endif // CLIENTLIST_H
