#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), res(-1000, 1000, this)
{
    ui->setupUi(this);
    ui->Input->setValidator(&res);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Result()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Ask()));
    connect(ui->Input, SIGNAL(textChanged(QString)), this, SLOT(Clear()));
}

void MainWindow::Result() {
    if((ui->size1->isChecked() || ui->size2->isChecked() || ui->size3->isChecked()) && (ui->type1->isChecked() || ui->type2->isChecked()) && (ui->Input->text() != "")){
        int a = 100;
        if (ui->size2->isChecked()){
            a += 25;
        }
        else if (ui->size3->isChecked()){
            a += 50;
        }
        if (ui->type1->isChecked()){
            a += 100;
        }
        if(ui->Input->text().toInt() >= 15) {
            ui->Res->setText(QString::number((ui->Input->text().toInt() * a) * 0.9));
        }
        else{
            ui->Res->setText(QString::number(ui->Input->text().toInt() * a));
        }
    }
    else{
        ui->Res->setText("");
    }
}

void MainWindow::Ask() {
    QMessageBox::information(this,"","При покупке 15 и более фото вам предусмотрена скидка в 10%");
}

void MainWindow::Clear() {
    ui->Res->setText("");
}

void MainWindow::on_size1_clicked()
{
    ui->Res->setText("");
    if(ui->type1->isChecked()){
        QPixmap im(":/new/img/size1.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
    else{
        QPixmap im(":/new/img/mat1.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
}

void MainWindow::on_size2_clicked()
{
    if(ui->type1->isChecked()){
        QPixmap im(":/new/img/size2.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
    else{
        QPixmap im(":/new/img/mat2.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
}

void MainWindow::on_size3_clicked()
{
    if(ui->type1->isChecked()){
        QPixmap im(":/new/img/size3.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
    else{
        QPixmap im(":/new/img/mat3.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->image->setPixmap(im.scaled(w, h, Qt::KeepAspectRatio));
    }
}

void MainWindow::on_type1_clicked()
{
    ui->Res->setText("");
}

void MainWindow::on_type2_clicked()
{
    ui->Res->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}
