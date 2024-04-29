#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>
#include <clientobject.h>
#include <clientlist.h>
#include <carform.h>
#include <carobject.h>
#include <carlist.h>
#include <shop.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_Client_clicked();
    void on_Car_clicked();
    void on_Shop_clicked();

private:
    Ui::MainWindow *ui;
    CarForm *carWindow;
    Client *clientWindow;
    Shop *shopWindow;
};

#endif // MAINWINDOW_H
