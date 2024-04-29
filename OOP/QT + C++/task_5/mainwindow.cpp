#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data = new Data(this);
    ui->comboBox->clear();
    ui->comboBox->addItem("Input_1.txt");
    ui->comboBox->addItem("Input_2.txt");
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("Output_1.txt");
    ui->comboBox_3->addItem("Output_2.txt");
    ui->ShowByIndex->setEnabled(false);
    ui->DeleteByIndex->setEnabled(false);
    ui->DeleteByValue->setEnabled(false);
    ui->Add->setEnabled(false);
    connect(ui->Open, SIGNAL(clicked()), this, SLOT(ReadFile_2()));
    connect(ui->Save, SIGNAL(clicked()), this, SLOT(WriteFile()));
    connect(ui->Clear, SIGNAL(clicked()), this, SLOT(ClearMass()));
    connect(ui->ShowByIndex, SIGNAL(clicked()), this, SLOT(ShowByIndex()));
    connect(ui->DeleteByIndex, SIGNAL(clicked()), this, SLOT(DeleteByIndex()));
    connect(ui->DeleteByValue, SIGNAL(clicked()), this, SLOT(DeleteByValue()));
    connect(ui->Add, SIGNAL(clicked()), this, SLOT(AddByValue()));
    connect(ui->Summ, SIGNAL(clicked()), this, SLOT(SummOut()));
    connect(ui->SumEven, SIGNAL(clicked()), this, SLOT(SummEvenOut()));
    connect(ui->Task_1, SIGNAL(clicked()), this, SLOT(Task_1_out()));
    connect(ui->Task_2, SIGNAL(clicked()), this, SLOT(Task_2_out()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadFile()  //Взятие коллекции из файла
{
    QFile file;
    if(ui->comboBox->currentText() == "Input_1.txt") {
        file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Input_1.txt");
    }
    else {
        file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Input_2.txt");
    }
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    data->count = 0;
    data->mass.clear();
    while(!file.atEnd()){
        data->mass.push_back(file.readLine().toInt());
        data->count ++;
    }
    ui->Output->setText("");
    for (int i = 0; i < data->count; i ++){
        ui->Input->setText(ui->Input->text() + "\n" + QString::number(data->mass[i]));
    }
    file.close();
    ui->Task_2_out->setText("");
}

void MainWindow::ReadFile_2()
{
    QFile file;
    if(ui->comboBox->currentText() == "Input_1.txt") {
        file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Input_1.txt");
    }
    else {
        file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Input_2.txt");
    }
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    data->count = 0;
    data->mass.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data->mass.push_back(line.toInt());
        data->count ++;
    }
    ui->Output->setText("");
    for (int i = 0; i < data->count; i ++){
        ui->Input->setText(ui->Input->text() + "\n" + QString::number(data->mass[i]));
    }
    file.close();
    ui->Task_2_out->setText("");
}

void MainWindow::WriteFile()  //Запись коллекции в файл
{
    QFile file;
    if(ui->comboBox_3->currentText() == "Output_1.txt") {
            file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Output_1.txt");
        }
        else {
            file.setFileName("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Output_2.txt");
        }
    /*if (!QFile::exists("C:/Users/ivan_/Documents/4 семестр/ООП/QT/Lab_5/Output_1.txt")){
        return;
    }*/
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    for (int i = 0; i < data->count; i ++) {
        out << data->mass[i] << "\n";
    }
    file.close();
    QMessageBox msgBox;
    msgBox.setText("Успешно сохранено");
    msgBox.setStyleSheet("QLabel{min-width: 250px;}");
    QTimer::singleShot(1000, &msgBox, SLOT(close()));
    msgBox.exec();
}

void MainWindow::ClearMass() //Отчистка коллекции без сохранения
{
    data->count = 0;
    data->mass.clear();
    ui->Input->setText("");
    ui->Output->setText("");
}

void MainWindow::ShowByIndex() //Вывод элемента по индексу
{
    if(ui->Index->text() != "") {
        if (ui->Index->text().toInt() >= data->count) {
            QMessageBox msgBox;
            msgBox.setText("Ошибка!");
            msgBox.setStyleSheet("QLabel{min-width: 100px;}");
            QTimer::singleShot(1000, &msgBox, SLOT(close()));
            msgBox.exec();
            ui->Index->setText("");
        }
        else {
            ui->out->setText(QString::number(data->mass[ui->Index->text().toInt()]));
        }
    }
}

void MainWindow::DeleteByIndex() //Удаление элемента по индексу
{
    if(ui->Index->text() != "") {
        if (ui->Index->text().toInt() >= data->count) {
            QMessageBox msgBox;
            msgBox.setText("Ошибка!");
            msgBox.setStyleSheet("QLabel{min-width: 100px;}");
            QTimer::singleShot(1000, &msgBox, SLOT(close()));
            msgBox.exec();
            ui->Index->setText("");
        }
        else {
            data->mass.remove(ui->Index->text().toInt());
            data->count--;
            for (int i = 0; i < data->count; i ++) {
                ui->Output->setText(ui->Output->text() + "\n" + QString::number(data->mass[i]));
            }
        }
    }
    ui->Task_2_out->setText("");
}

void MainWindow::DeleteByValue() //Удаление элемента по значению
{
    if(ui->Value->text() != "") {
        for (int i = 0; i < data->count; i ++) {
            if (ui->Value->text().toInt() == data->mass[i]) {
                data->mass.remove(i);
                data->count--;
                break;
            }
        }
        ui->Output->setText("");
        for (int i = 0; i < data->count; i ++) {
            ui->Output->setText(ui->Output->text() + "\n" + QString::number(data->mass[i]));
        }
    }
    ui->Task_2_out->setText("");
}

void MainWindow::AddByValue() //Добавление элемента
{
    if (ui->Value->text() != "") {
        data->mass.push_back(ui->Value->text().toInt());
        data->count ++;
        ui->Output->setText("");
        for (int i = 0; i < data->count; i ++) {
            ui->Output->setText(ui->Output->text() + "\n" + QString::number(data->mass[i]));
        }
    }
    ui->Value->setText("");
    ui->Task_2_out->setText("");
}

void MainWindow::SummOut() //Сумма элементов из собственного класса
{
    ui->SumIn->setText(QString::number(data->Summ()));
}

void MainWindow::SummEvenOut() //Сумма четных элементов из собственного класса
{
    ui->SumIn->setText(QString::number(data->SummEven()));
}

void MainWindow::Task_1_out() //Вызов функции собственного класса для задания 1
{
    ui->Output->setText("");
    data->Task_1();
    for (int i = 0; i < data->count; i ++) {
        ui->Output->setText(ui->Output->text() + "\n" + QString::number(data->mass[i]));
    }
}

void MainWindow::Task_2_out() //Вызов функции собственного класса для задания 2
{
    int summ = data->Task_2();
    if (summ != 0){
        for (int i = 0; i < data->count; i ++) {
            ui->Task_2_out->setText(QString::number(summ));
        }
    }
}

//Блоки чистки окон

void MainWindow::on_comboBox_currentTextChanged()
{
    ui->Input->setText("");
    ui->Output->setText("");
}

void MainWindow::on_Index_textChanged()
{
    ui->out->setText("");
    if (ui->Index->text() != ""){
        ui->ShowByIndex->setEnabled(true);
        ui->DeleteByIndex->setEnabled(true);
    }
    else{
        ui->ShowByIndex->setEnabled(false);
        ui->DeleteByIndex->setEnabled(false);
    }
}


void MainWindow::on_Value_textChanged()
{
    if (ui->Value->text() != ""){
        ui->Add->setEnabled(true);
        ui->DeleteByValue->setEnabled(true);
    }
    else{
        ui->Add->setEnabled(false);
        ui->DeleteByValue->setEnabled(false);
    }
}
