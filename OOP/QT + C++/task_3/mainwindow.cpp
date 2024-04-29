#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), res(-1000, 1000, this)
{
    ui->setupUi(this);
    ui->a->setValidator(&res);
    ui->b->setValidator(&res);
    connect(ui->a, SIGNAL(textChanged(QString)), this, SLOT(Result()));
    connect(ui->b, SIGNAL(textChanged(QString)), this, SLOT(Result()));
    ui->comboBox->clear();
    ui->comboBox->addItem("Шёлк");
    ui->comboBox->addItem("Атлас");
    ui->comboBox->addItem("Сатин");
    ui->comboBox->addItem("Кашемир");
    ui->comboBox->addItem("Батист");
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(Price()));
}

void MainWindow::Result() {
    ui->Res->setText("");
    connect(ui->Sum, SIGNAL(clicked()), this, SLOT(Sum()));
}

void MainWindow::Sum() {
    ui->Res->setText(QString::number(ui->a->text().toInt() * ui->b->text().toInt() * ui->Price->text().toInt()));
}

void MainWindow::Price() {
    ui->Res->setText("");
    if(ui->comboBox->currentText() == "Шёлк"){
        ui->Price->setText("2000");
    }
    if(ui->comboBox->currentText() == "Атлас"){
        ui->Price->setText("1500");
    }
    if(ui->comboBox->currentText() == "Сатин"){
        ui->Price->setText("700");
    }
    if(ui->comboBox->currentText() == "Кашемир"){
        ui->Price->setText("2500");
    }
    if(ui->comboBox->currentText() == "Батист"){
        ui->Price->setText("1000");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


