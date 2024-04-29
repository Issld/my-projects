#ifndef SHOPADDFORM_H
#define SHOPADDFORM_H

#include <QWidget>

namespace Ui {
class ShopAddForm;
}

class ShopAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShopAddForm(QWidget *parent = nullptr);
    ~ShopAddForm();

signals:
    void shopAddWindow(QString, QString, QString);

private slots:
    void on_pushButton_clicked();
    void on_Surname_textChanged();
    void on_Model_textChanged();
    void on_Date_textChanged();

private:
    Ui::ShopAddForm *ui;
};

#endif // SHOPADDFORM_H
