#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QTimer>
#include "Data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ReadFile();
    void ReadFile_2();
    void WriteFile();
    void ClearMass();
    void ShowByIndex();
    void DeleteByIndex();
    void DeleteByValue();
    void AddByValue();
    void SummOut();
    void SummEvenOut();
    void Task_1_out();
    void Task_2_out();
    void on_comboBox_currentTextChanged();
    void on_Index_textChanged();
    void on_Value_textChanged();

signals:
    int Summ();

private:
    Ui::MainWindow *ui;
    Data *data{};
};

#endif // MAINWINDOW_H
