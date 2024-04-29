#include "carform.h"
#include "ui_carform.h"

CarForm::CarForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarForm)
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
    carAddWindow = new CarAddForm(); //Создание окна добавления
    connect(carAddWindow, &CarAddForm::carAddWindow, this, &CarForm::AddCar); //Сигнал вызова этогого окна
    /*CarObject* obj = new CarObject("BMV", "m5", 2012, CarObject::GearType::AUTOMATIC, 250, 1);
    list->Add(obj);
    obj = new CarObject("Shcoda", "Octavia", 2009, CarObject::GearType::MECHANICAL, 180, 1);
    list->Add(obj);
    obj = new CarObject("Audi", "A4", 2008, CarObject::GearType::VARIATOR, 200, 1);
    list->Add(obj);
    obj = new CarObject("Exeed", "LX", 2023, CarObject::GearType::ROBOTIC, 150, 1);
    list->Add(obj);
    obj = new CarObject("Mercedes", "CLS 250", 2015, CarObject::GearType::AUTOMATIC, 204, 1);
    list->Add(obj);
    obj = nullptr;
    OutputCar();*/
}

void CarForm::on_Return_clicked() //Возврат к исходному окну
{
    this->close();
    emit carWindow();
}

void CarForm::on_Add_clicked() //Вызов окна для добавления
{
    ui->Add->setEnabled(false);
    carAddWindow->show();
}

void CarForm::AddCar(QString label, QString model, int year, const CarObject::GearType& gearbox, int power) //Добавление элемента
{
    ui->Add->setEnabled(true);
    CarObject* obj = new CarObject(label, model, year, gearbox, power, 1); //Создание объекта класса CarObject
    list->Add(obj); //Внесение его в массив
    obj = nullptr;
    OutputCar(); //Отображение в таблице
}


void CarForm::on_Delete_clicked() //Удаление элемента
{
    if (ui->NumberInput->text().toInt() - 1 < list->getSize()) { //Проверка ревалетности индекса
        list->Delete(ui->NumberInput->text().toInt());
        OutputCar(); //Отображение в таблице
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    ui->NumberInput->setText("");
}

void CarForm::on_Search_clicked() //Поиск элемента
{
    for (int i = 0; i < list->getSize(); i ++) {
        CarObject* obj = list->getObject(i);
        if(obj->getModel() == ui->ModelInput->text()) {
            ui->tableWidget->selectRow(i); //Выделение ряда таблицы
        }
    }
    ui->ModelInput->setText("");
}

void CarForm::OutputCar() //Отображение таблицы
{
    ui->tableWidget->clearContents(); //Чистка старых записей
    int n = 0;
    for (int i = 0; i < list->getSize(); i ++) {
        CarObject* obj = list->getObject(i);
        if (obj->getView()) {
            n++;
            for (int j = 0; j < 6; j ++) {
                QTableWidgetItem *item; //Создание объекта таблицы
                QString type;
                if (obj->getGearbox() == CarObject::GearType::MECHANICAL) {
                    type = "Механическая коробка";
                }
                else if (obj->getGearbox() == CarObject::GearType::AUTOMATIC) {
                    type = "Автоматическая коробка";
                }
                else if (obj->getGearbox() == CarObject::GearType::VARIATOR) {
                    type = "Вариатор";
                }
                else {
                    type = "Роботизированная коробка";
                }
                switch (j) {
                case(0): item = new QTableWidgetItem(QString::number(n));
                    break;
                case(1): item = new QTableWidgetItem(obj->getLabel());
                    break;
                case(2): item = new QTableWidgetItem(obj->getModel());
                    break;
                case(3): item = new QTableWidgetItem(QString::number(obj->getYear()));
                    break;
                case(4): item = new QTableWidgetItem(type);
                    break;
                case(5): item = new QTableWidgetItem(QString::number(obj->getPower()));
                    break;
                }
                ui->tableWidget->setItem(i, j, item); //Запись в ячейку
            }
        }
    }
}

void CarForm::on_NumberInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->NumberInput->text() != "") {
        ui->Delete->setEnabled(true);
    }
    else {
        ui->Delete->setEnabled(false);
    }
}

void CarForm::on_ModelInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->ModelInput->text() != "") {
        ui->Search->setEnabled(true);
    }
    else {
        ui->Search->setEnabled(false);
    }
}

CarForm::~CarForm()
{
    delete ui;
}
