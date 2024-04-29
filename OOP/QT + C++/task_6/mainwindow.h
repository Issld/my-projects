#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <states.h>
#include <estate.h>
#include <calculationfacade.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void update();
    ~MainWindow();

private slots:
    void btnCalcPressed();
    void btnUndoPressed();
    void on_Time_currentTextChanged();
    void on_Clases_currentTextChanged();

private:
    Ui::MainWindow *ui;
    Estate::EstateType type = Estate::EstateType::ECONOM;
    int time = 6;
    States info;
    Estate *processForm();
    void fillForm(Estate *value);
    void showCost(Estate *value);
};

#endif // MAINWINDOW_H
