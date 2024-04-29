#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap im(":/new/img/foto_large.jpg");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    connect(ui->Sum, SIGNAL(clicked()), this, SLOT(Res()));
    connect(ui->minus_1, SIGNAL(clicked()), this, SLOT(Res_sub_1()));
    connect(ui->plus_1, SIGNAL(clicked()), this, SLOT(Res_sum_1()));
    connect(ui->minus_2, SIGNAL(clicked()), this, SLOT(Res_sub_2()));
    connect(ui->plus_2, SIGNAL(clicked()), this, SLOT(Res_sum_2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_1_stateChanged()
{
    if(ui->checkBox_1->isChecked()){
        ui->res_1->setText("1");
    }
    else{
        ui->res_1->setText("0");
    }
    ui->Res->setText("");
}

void MainWindow::on_checkBox_2_stateChanged()
{
    if(ui->checkBox_2->isChecked()){
        ui->res_2->setText("1");
    }
    else{
        ui->res_2->setText("0");
    }
    ui->Res->setText("");
}


void MainWindow::on_checkBox_3_stateChanged()
{
    ui->Res->setText("");
}

void MainWindow::on_checkBox_4_stateChanged()
{
    ui->Res->setText("");
}

void MainWindow::on_checkBox_5_stateChanged()
{
    ui->Res->setText("");
}

void MainWindow::on_checkBox_6_stateChanged()
{
    ui->Res->setText("");
}

void MainWindow::on_checkBox_3_clicked()
{
    if(ui->checkBox_4->isChecked()) {
         QMessageBox::critical(this,"", "Нельзы выбрать Каско и ОСАГО одновременно!");
         ui->Res->setText("");
         ui->checkBox_3->setChecked(false);
         ui->checkBox_4->setChecked(false);
    }
}

void MainWindow::on_checkBox_4_clicked()
{
    if(ui->checkBox_3->isChecked()) {
         QMessageBox::critical(this,"", "Нельзы выбрать Каско и ОСАГО одновременно!");
         ui->Res->setText("");
         ui->checkBox_3->setChecked(false);
         ui->checkBox_4->setChecked(false);
    }
}

void MainWindow::Res_sub_1()
{
    if(ui->checkBox_1->isChecked()){
        if(ui->res_1->text().toInt() - 1 < 0){
            ui->checkBox_1->setChecked(false);
        }
        else if(ui->res_1->text().toInt() - 1 == 0){
            ui->checkBox_1->setChecked(false);
            ui->res_1->setText("0");
        }
        else{
            ui->res_1->setText(QString::number(ui->res_1->text().toInt() - 1));
        }
    }
}

void MainWindow::Res_sum_1()
{
    if(ui->checkBox_1->isChecked()){
        if(ui->res_1->text().toInt() + 1 > 6){
            QMessageBox::critical(this,"", "Вы уже выбрали все доступные для покупки товары этого вида из имеющихся на складе!");
        }
        else{
            ui->res_1->setText(QString::number(ui->res_1->text().toInt() + 1));
        }
    }
}

void MainWindow::Res_sub_2()
{
    if(ui->checkBox_2->isChecked()){
        if(ui->res_2->text().toInt() - 1 < 0){
            ui->checkBox_2->setChecked(false);
        }
        else if(ui->res_2->text().toInt() - 1 == 0){
            ui->checkBox_2->setChecked(false);
            ui->res_2->setText("0");
        }
        else{
            ui->res_2->setText(QString::number(ui->res_2->text().toInt() - 1));
        }
    }
}

void MainWindow::Res_sum_2()
{
    if(ui->checkBox_2->isChecked()){
        if(ui->res_2->text().toInt() + 1 > 6){
            QMessageBox::critical(this,"", "Вы уже выбрали все доступные для покупки товары этого вида из имеющихся на складе!");
        }
        else{
            ui->res_2->setText(QString::number(ui->res_2->text().toInt() + 1));
        }
    }
}

void MainWindow::Res()
{
    ui->Res->setText("");
    int summ = 0;
    int disc = 0;
    if(ui->checkBox_1->isChecked()) {
         summ += 30000 * ui->res_1->text().toInt();
    }
    if(ui->checkBox_2->isChecked()) {
         summ += 50000 * ui->res_2->text().toInt();
    }
    if(ui->checkBox_3->isChecked()) {
        summ += 10000;
    }
    if(ui->checkBox_4->isChecked()) {
        summ += 20000;
    }
    if(ui->checkBox_5->isChecked()) {
         summ += 150000;
    }
    if(ui->checkBox_6->isChecked()) {
        summ += 100000;
    }
    if(ui->checkBox_1->isChecked() && ui->checkBox_2->isChecked() && ui->checkBox_5->isChecked() && ui->checkBox_6->isChecked() && (ui->checkBox_4->isChecked() || ui->checkBox_3->isChecked())){
        disc = summ * 0.1;
    }
    ui->Res->setText("Стоимость изделия: 5000000\nСтоимость комплектующих: " + QString::number(summ) + "\nСкидка с комплектующих: " + QString::number(disc) + "\nИтог (с учётом скидки): " + QString::number(5000000 + summ - disc));
}

