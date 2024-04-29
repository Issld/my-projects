#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
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
    clientAddWindow = new ClientAddForm(); //Создание окна добавления
    connect(clientAddWindow, &ClientAddForm::clientAddWindow, this, &Client::AddUser); //Сигнал вызова этого окна
    /*ClientObject* obj = new ClientObject("Петров", "Петр", "Петрович", "1111", "p@mail.ru");
    list->Add(obj);
    obj = new ClientObject("Иванов", "Иван", "Иванович", "2222", "i@mail.ru");
    list->Add(obj);
    obj = new ClientObject("Николаев", "Николай", "Николаевич", "3333", "n@mail.ru");
    list->Add(obj);
    obj = new ClientObject("Александров", "Александр", "Александрович", "4444", "a@mail.ru");
    list->Add(obj);
    obj = new ClientObject("Сергеев", "Сергей", "Сергеевич", "5555", "s@mail.ru");
    list->Add(obj);
    obj = nullptr;
    OutputClient();*/
}

void Client::on_Return_clicked() //Возврат к исходному окну
{
    this->close();
    emit clientWindow();
}


void Client::on_Add_clicked() //Вызов окна для добавления
{
    ui->Add->setEnabled(false);
    clientAddWindow->show();
}

void Client::AddUser(QString surname, QString name, QString secname, QString phone, QString mail) //Добавление элемента
{
    ui->Add->setEnabled(true);
    ClientObject* obj = new ClientObject(surname, name, secname, phone, mail); //Создание объекта класса ClientObject
    list->Add(obj); //Внесение его в массив
    obj = nullptr;
    OutputClient(); //Отображение в таблице
}

void Client::on_Delete_clicked() //Удаление элемента
{
    if (ui->IndexInput->text().toInt() - 1 < list->getSize()) { //Проверка ревалетности индекса
        list->Delete(ui->IndexInput->text().toInt());
        OutputClient(); //Отображение в таблице
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    ui->IndexInput->setText("");
}

void Client::on_Search_clicked() //Поиск элемента
{
    for (int i = 0; i < list->getSize(); i ++) {
        ClientObject* obj = list->getObject(i);
        if(obj->getSurname() == ui->SurnameInput->text()) {
            ui->tableWidget->selectRow(i); //Выделение ряда таблицы
            break;
        }
    }
    ui->SurnameInput->setText("");
}

void Client::OutputClient()//Отображение таблицы
{
    ui->tableWidget->clearContents(); //Чистка старых записей
    for (int i = 0; i < list->getSize(); i ++) {
        ClientObject* obj = list->getObject(i);
        for (int j = 0; j < 6; j ++) {
            QTableWidgetItem *item; //Создание объекта таблицы
            switch (j) {
            case(0): item = new QTableWidgetItem(QString::number(i+1));
                break;
            case(1): item = new QTableWidgetItem(obj->getSurname());
                break;
            case(2): item = new QTableWidgetItem(obj->getName());
                break;
            case(3): item = new QTableWidgetItem(obj->getSecname());
                break;
            case(4): item = new QTableWidgetItem(obj->getPhone());
                break;
            case(5): item = new QTableWidgetItem(obj->getMail());
                break;
            }
            ui->tableWidget->setItem(i, j, item); //Запись в ячейку
        }
    }
}

void Client::on_IndexInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->IndexInput->text() != "") {
        ui->Delete->setEnabled(true);
    }
    else {
        ui->Delete->setEnabled(false);
    }
}

void Client::on_SurnameInput_textChanged() //Проверка нужно ли активировать кнопку
{
    if (ui->SurnameInput->text() != "") {
        ui->Search->setEnabled(true);
    }
    else {
        ui->Search->setEnabled(false);
    }
}

Client::~Client()
{
    delete ui;
}
