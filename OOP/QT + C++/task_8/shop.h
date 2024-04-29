#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <client.h>
#include <clientobject.h>
#include <clientlist.h>
#include <carform.h>
#include <carobject.h>
#include <carlist.h>
#include <shopaddform.h>
#include <shopobject.h>
#include <shoplist.h>
#include <calculationfacade.h>

namespace Ui {
class Shop;
}

class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(CarForm*, Client*, QWidget *parent = nullptr);
    ~Shop();

signals:
    void shopWindow();

public slots:
    void AddBuy(QString, QString, QString);

private slots:
    void on_Return_clicked();
    void OutputShop();
    void on_Add_clicked();
    void on_Search_clicked();
    void on_Delete_clicked();
    void on_NumberInput_textChanged();
    void on_CostInput_textChanged();

private:
    Ui::Shop *ui;
    CarForm *car;
    Client *client;
    ShopAddForm *shopAddWindow;
    ShopList *list = new ShopList;
};

#endif // SHOP_H
