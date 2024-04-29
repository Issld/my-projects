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
    void btnCalcPressed(); //Рассчет стоимости страхования
    void btnUndoPressed(); //Возврат последнего сохраненного состояния
    void on_Time_currentTextChanged();
    void on_Clases_currentTextChanged();

private:
    Ui::MainWindow *ui;
    Estate::EstateType type = Estate::EstateType::ECONOM;
    int time = 6;
    States info; //Объект-хранилище состояний
    Estate *processForm(); //Инициализация формы страхования
    void fillForm(Estate *value); //Заполнение формы значениями
    void showCost(Estate *value); //Вывод стоимости страхования
};

#endif // MAINWINDOW_H
