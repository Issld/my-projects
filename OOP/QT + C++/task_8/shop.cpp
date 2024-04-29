#include "shop.h"
#include "ui_shop.h"

Shop::Shop(CarForm *inputCar, Client *inputClient, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,43);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(3,150);
    ui->tableWidget->setColumnWidth(4,150);
    ui->tableWidget->setColumnWidth(5,150);
    ui->Delete->setEnabled(false);
    ui->Search->setEnabled(false);
    car = inputCar; //Связывание с окном автомобилей
    client = inputClient; //Связывание с окном клиентов
    shopAddWindow = new ShopAddForm(); //Создание окна добавления
    connect(shopAddWindow, &ShopAddForm::shopAddWindow, this, &Shop::AddBuy); //Сигнал вызова этого окна
}

void Shop::on_Return_clicked() //Возврат к исходному окну
{
    this->close();
    emit shopWindow();
}

void Shop::on_Add_clicked() //Вызов окна для добавления
{
    ui->Add->setEnabled(false);
    shopAddWindow->show();
}

void Shop::AddBuy(QString surname, QString model, QString date) //Добавление элемента
{
    ui->Add->setEnabled(true);
    QString finalModel = "";
    QString fio = "";
    QString phone = "";
    int price = 0;
    bool found = 0;
    for (int i = 0; i < client->list->getSize(); i ++) { //Поиск для досоздания объекта
        ClientObject* obj = client->list->getObject(i);
        if(obj->getSurname() == surname) {
            fio = surname + " " + obj->getName() + " " + obj->getSecname();
            phone = obj->getPhone();
            found = 1;
            break;
        }
    }
    for (int i = 0; i < car->list->getSize(); i ++) { //Поиск для досоздания объекта
        CarObject* obj = car->list->getObject(i);
        if(obj->getModel() == model) {
            finalModel = obj->getLabel() + " " + model;
            price = CalculationFacade::getCost(obj); //Рассчет стоимости
            obj->setInvisible();
            car->OutputCar(); //Переотображение в таблице автомобилей
            found = 1;
            break;
        }
    }
    if (found == 1) { //Проверка на наличие необходимых входных данных
        ShopObject* shopObj = new ShopObject(finalModel, price, date, fio, phone, model); //Создание объекта класса CarObject
        list->Add(shopObj); //Внесение его в массив
        shopObj = nullptr;
        OutputShop(); //Отображение в таблице
    }
}

void Shop::on_Delete_clicked() //Удаление элемента
{
    for (int i = 0; i < list->getSize(); i ++) {
        ShopObject* obj = list->getObject(i);
        if(obj->getJustModel() == ui->NumberInput->text()) {
            list->Delete(i);
            break;
        }
    }
    OutputShop(); //Отображение в таблице
    for (int i = 0; i < car->list->getSize(); i ++) { //Восстановление элемента автомобиля
        CarObject* obj = car->list->getObject(i);
        if(obj->getModel() == ui->NumberInput->text()) {
            obj->setVisible();
            car->OutputCar(); //Переотображение в таблице автомобилей
            break;
        }
    }
    ui->NumberInput->setText("");
}


void Shop::on_Search_clicked() //Поиск элемента
{
    for (int i = 0; i < list->getSize(); i ++) {
        ShopObject* obj = list->getObject(i);
        if(obj->getPrice() == ui->CostInput->text().toInt()) {
            ui->tableWidget->selectRow(i); //Поиск элемента
            break;
        }
    }
    ui->CostInput->setText("");
}

void Shop::OutputShop() //Отображение таблицы
{
    ui->tableWidget->clearContents(); //Чистка старых записей
    for (int i = 0; i < list->getSize(); i ++) {
        ShopObject* obj = list->getObject(i);
        for (int j = 0; j < 6; j ++) {
            QTableWidgetItem *item; //Создание объекта таблицы
            switch (j) {
            case(0): item = new QTableWidgetItem(QString::number(i+1));
                break;
            case(1): item = new QTableWidgetItem(obj->getModel());
                break;
            case(2): item = new QTableWidgetItem(QString::number(obj->getPrice()));
                break;
            case(3): item = new QTableWidgetItem(obj->getDate());
                break;
            case(4): item = new QTableWidgetItem(obj->getFio());
                break;
            case(5): item = new QTableWidgetItem(obj->getPhone());
                break;
            }
            ui->tableWidget->setItem(i, j, item); //Запись в ячейку
        }
    }
}

void Shop::on_NumberInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->NumberInput->text() != "") {
        ui->Delete->setEnabled(true);
    }
    else{
        ui->Delete->setEnabled(false);
    }
}

void Shop::on_CostInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->CostInput->text() != "") {
        ui->Search->setEnabled(true);
    }
    else{
        ui->Search->setEnabled(false);
    }
}

Shop::~Shop()
{
    delete ui;
}
