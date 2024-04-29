#include "caraddform.h"
#include "ui_caraddform.h"

CarAddForm::CarAddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarAddForm)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

CarAddForm::~CarAddForm()
{
    delete ui;
}

void CarAddForm::on_pushButton_clicked() //Возврат к окну
{
    CarObject::GearType type;
    if (ui->Gearbox->currentText() == "Механическая коробка") {
        type = CarObject::GearType::MECHANICAL;
    }
    else if (ui->Gearbox->currentText() == "Автоматическая коробка") {
        type = CarObject::GearType::AUTOMATIC;
    }
    else if (ui->Gearbox->currentText() == "Вариатор") {
        type = CarObject::GearType::VARIATOR;
    }
    else {
        type = CarObject::GearType::ROBOTIC;
    }
    this->close();
    emit carAddWindow(ui->Label->text(), ui->Model->text(), ui->Year->text().toInt(), type, ui->Power->text().toInt()); //Сигнал для закрытия окна и передачи данных
    ui->Label->setText("");
    ui->Model->setText("");
    ui->Year->setText("");
    ui->Gearbox->setCurrentText("Механическая коробка");
    ui->Power->setText("");
}


void CarAddForm::on_Label_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Label->text() != "" && ui->Model->text() != "" && ui->Year->text() != "" && ui->Power->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void CarAddForm::on_Model_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Label->text() != "" && ui->Model->text() != "" && ui->Year->text() != "" && ui->Power->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void CarAddForm::on_Year_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Label->text() != "" && ui->Model->text() != "" && ui->Year->text() != "" && ui->Power->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void CarAddForm::on_Gearbox_currentTextChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Label->text() != "" && ui->Model->text() != "" && ui->Year->text() != "" && ui->Power->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void CarAddForm::on_Power_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Label->text() != "" && ui->Model->text() != "" && ui->Year->text() != "" && ui->Power->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}
