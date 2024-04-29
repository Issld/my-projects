#ifndef SHOPLIST_H
#define SHOPLIST_H

#include <QObject>
#include <shopobject.h>

class ShopList : public QObject
{
    Q_OBJECT

public:
    explicit ShopList(QObject *parent = nullptr);
    ~ShopList();
    void Add(ShopObject *value);
    void Delete(int);
    int getSize();
    ShopObject* getObject(int);

private:
    QList<ShopObject*> mass;
};

#endif // SHOPLIST_H
