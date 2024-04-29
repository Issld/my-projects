#ifndef CARFORM_H
#define CARFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <caraddform.h>
#include <carobject.h>
#include <carlist.h>

namespace Ui {
class CarForm;
}

class CarForm : public QWidget
{
    Q_OBJECT

public:
    explicit CarForm(QWidget *parent = nullptr);
    ~CarForm();
    CarList *list = new CarList;

public slots:
    void AddCar(QString, QString, int, const CarObject::GearType&, int);
    void OutputCar();

private slots:
    void on_Return_clicked();
    void on_Add_clicked();
    void on_Delete_clicked();
    void on_Search_clicked();
    void on_NumberInput_textChanged();
    void on_ModelInput_textChanged();

signals:
    void carWindow();

private:
    Ui::CarForm *ui;
    CarAddForm *carAddWindow;

};

#endif // CARFORM_H
