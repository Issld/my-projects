#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    carWindow = new CarForm(); //Создане окна для отображения автомобилей
    connect(carWindow, &CarForm::carWindow, this, &MainWindow::show); //Сигнал вызова исходного окна
    clientWindow = new Client(); //Создане окна для отображения пользователейлей
    connect(clientWindow, &Client::clientWindow, this, &MainWindow::show); //Сигнал вызова исходного окна
    shopWindow = new Shop(carWindow, clientWindow); //Создане окна для отображения покупок
    connect(shopWindow, &Shop::shopWindow, this, &MainWindow::show); //Сигнал вызова исходного окна
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Client_clicked() //Открытие окна отображения клиентов
{
    clientWindow->show();
    this->close();
}


void MainWindow::on_Car_clicked() //Открытие окна отображения автомобилей
{
    carWindow->show();
    this->close();
}


void MainWindow::on_Shop_clicked() //Открытие окна отображения магазин
{
    shopWindow->show();
    this->close();
}

