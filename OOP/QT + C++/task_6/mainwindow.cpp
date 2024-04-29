#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <calculationfacade.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Previous->setEnabled(false);
    ui->Clases->clear();
    ui->Clases->addItem("Квартира эконом-класс");
    ui->Clases->addItem("Элитная квартира");
    ui->Clases->addItem("Таун-хаус");
    ui->Clases->addItem("Коттедж");
    ui->Time->clear();
    ui->Time->addItem("6 месяцев");
    ui->Time->addItem("12 месяцев");
    ui->Time->addItem("18 месяцев");
    connect(&info, &States::notifyObservers, this, &MainWindow::update);
    connect(ui->Count, SIGNAL(clicked()), this, SLOT(btnCalcPressed()));
    connect(ui->Previous, SIGNAL(clicked()), this, SLOT(btnUndoPressed()));
}

void MainWindow::on_Time_currentTextChanged()
{
    if (ui->Time->currentText() == "6 месяцев") {
        this->time = 6;
    }
    else if (ui->Time->currentText() == "12 месяцев") {
        this->time = 12;
    }
    else {
        this->time = 18;
    }
}

void MainWindow::on_Clases_currentTextChanged()
{
    if (ui->Clases->currentText() == "Квартира эконом-класс") {
        this->type = Estate::EstateType::ECONOM;
    }
    else if (ui->Clases->currentText() == "Элитная квартира") {
        this->type = Estate::EstateType::LUXURIOUS;
    }
    else if (ui->Clases->currentText() == "Таун-хаус") {
        this->type = Estate::EstateType::TOWN_HOUSE;
    }
    else {
        this->type = Estate::EstateType::COTTAGE;
    }
}

void MainWindow::update()
{
    Estate* obj = info.getActualData();
    if(obj != nullptr){
        showCost(obj);
        fillForm(obj);
    }
    ui->Previous->setEnabled(info.myHasStates());
    if (!info.myHasStates()){
        info.Clear();
    }
    obj = nullptr;
}

void MainWindow::btnCalcPressed()
{
    Estate* obj = processForm();
    showCost(obj);
    info.add(obj);
    ui->Previous->setEnabled(true);
    obj = nullptr;
}
void MainWindow::btnUndoPressed()
{
    info.undo();
}

Estate* MainWindow::processForm()
{
    return new Estate(ui->Name->text(), ui->Age->text().toInt(), this->type, ui->Square->text().toInt(), ui->Quantity->text().toInt(), this->time);;
}

void MainWindow::fillForm(Estate *obj)
{
    ui->Name->setText(obj->TakeName());
    ui->Age->setText(QString::number(obj->TakeAge()));
    ui->Quantity->setText(QString::number(obj->TakeQuntity()));
    ui->Square->setText(QString::number(obj->TakeSquare()));
    if (obj->TakeClass() == Estate::EstateType::ECONOM) {
        ui->Clases->setCurrentText("Квартира эконом-класс");
    }
    else if (obj->TakeClass() == Estate::EstateType::LUXURIOUS) {
        ui->Clases->setCurrentText("Элитная квартира");
    }
    else if (obj->TakeClass() == Estate::EstateType::TOWN_HOUSE) {
        ui->Clases->setCurrentText("Таун-хаус");
    }
    else {
        ui->Clases->setCurrentText("Коттедж");
    }
    if (obj->TakeTime() == 6) {
        ui->Time->setCurrentText("6 месяцев");
    }
    else if (obj->TakeTime() == 12) {
        ui->Time->setCurrentText("12 месяцев");
    }
    else {
        ui->Time->setCurrentText("18 месяцев");
    }
}

void MainWindow::showCost(Estate *obj)
{
    ui->Output->setText(QString::number(CalculationFacade::getCost(obj)));
}

MainWindow::~MainWindow() {
    delete ui;
}
