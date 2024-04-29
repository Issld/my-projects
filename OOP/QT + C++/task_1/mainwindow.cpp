#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), res(-1000, 1000, this)
{
    QMessageBox::about(this,"","Приветствуем вас в приложении калькулятор");
    ui->setupUi(this);
    ui->a->setValidator(&res);
    ui->b->setValidator(&res);
    connect(ui->a, SIGNAL(textChanged(QString)), this, SLOT(Result()));
    connect(ui->b, SIGNAL(textChanged(QString)), this, SLOT(Result()));
}

//void MainWindow::Hello(){
//    QMessageBox::about(this,"","Приветствуем вас в приложении калькулятор");}

void MainWindow::Result() {
    ui->Res->setText("");
    connect(ui->Sum, SIGNAL(clicked()), this, SLOT(Sum()));
    connect(ui->Sub, SIGNAL(clicked()), this, SLOT(Sub()));
    connect(ui->Mult, SIGNAL(clicked()), this, SLOT(Mult()));
    connect(ui->Div, SIGNAL(clicked()), this, SLOT(Div()));
}

void MainWindow::Sum() {
    ui->Res->setText(QString::number(ui->a->text().toInt() + ui->b->text().toInt()));
}

void MainWindow::Sub() {
    ui->Res->setText(QString::number(ui->a->text().toInt() - ui->b->text().toInt()));
}

void MainWindow::Mult() {
    ui->Res->setText(QString::number(ui->a->text().toInt() * ui->b->text().toInt()));
}

void MainWindow::Div() {
    if(ui->b->text().toInt() != 0){
        ui->Res->setText(QString::number(ui->a->text().toInt() / ui->b->text().toInt()));
    }
    else{
        ui->Res->setText("Делить на 0 нельзя");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

