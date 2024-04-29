#ifndef CARADDFORM_H
#define CARADDFORM_H

#include <QWidget>
#include <carobject.h>

namespace Ui {
class CarAddForm;
}

class CarAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit CarAddForm(QWidget *parent = nullptr);
    ~CarAddForm();

signals:
    void carAddWindow(QString, QString, int, const CarObject::GearType&, int);

private slots:
    void on_pushButton_clicked();
    void on_Label_textChanged();
    void on_Model_textChanged();
    void on_Year_textChanged();
    void on_Gearbox_currentTextChanged();
    void on_Power_textChanged();

private:
    Ui::CarAddForm *ui;
};

#endif // CARADDFORM_H
