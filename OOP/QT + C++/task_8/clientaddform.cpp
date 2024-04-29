#include "clientaddform.h"
#include "ui_clientaddform.h"

ClientAddForm::ClientAddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientAddForm)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

ClientAddForm::~ClientAddForm()
{
    delete ui;
}

void ClientAddForm::on_pushButton_clicked() //Возврат к окну
{
    this->close();
    emit clientAddWindow(ui->Surname->text(), ui->Name->text(), ui->Secname->text(), ui->Phone->text(), ui->Mail->text()); //Сигнал для закрытия окна и передачи данных
    ui->Surname->setText("");
    ui->Name->setText("");
    ui->Secname->setText("");
    ui->Phone->setText("");
    ui->Mail->setText("");
}

void ClientAddForm::on_Surname_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Name->text() != "" && ui->Secname->text() != "" && ui->Phone->text() != "" && ui->Mail->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ClientAddForm::on_Name_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Name->text() != "" && ui->Secname->text() != "" && ui->Phone->text() != "" && ui->Mail->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ClientAddForm::on_Secname_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Name->text() != "" && ui->Secname->text() != "" && ui->Phone->text() != "" && ui->Mail->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ClientAddForm::on_Phone_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Name->text() != "" && ui->Secname->text() != "" && ui->Phone->text() != "" && ui->Mail->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ClientAddForm::on_Mail_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Name->text() != "" && ui->Secname->text() != "" && ui->Phone->text() != "" && ui->Mail->text() != "") {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}
