#include "shopaddform.h"
#include "ui_shopaddform.h"

ShopAddForm::ShopAddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopAddForm)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

ShopAddForm::~ShopAddForm()
{
    delete ui;
}

void ShopAddForm::on_pushButton_clicked() //Возврат к окну
{
    this->close();
    emit shopAddWindow(ui->Surname->text(), ui->Model->text(), ui->Date->text()); //Сигнал для закрытия окна и передачи данных
    ui->Surname->setText("");
    ui->Model->setText("");
    ui->Date->setText("");
}

void ShopAddForm::on_Surname_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Model->text() != "" && ui->Date->text() != "" ) {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ShopAddForm::on_Model_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Model->text() != "" && ui->Date->text() != "" ) {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void ShopAddForm::on_Date_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->Surname->text() != "" && ui->Model->text() != "" && ui->Date->text() != "" ) {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}
