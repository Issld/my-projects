#ifndef CLIENTADDFORM_H
#define CLIENTADDFORM_H

#include <QWidget>
#include <clientobject.h>

namespace Ui {
class ClientAddForm;
}

class ClientAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClientAddForm(QWidget *parent = nullptr);
    ~ClientAddForm();

signals:
    void clientAddWindow(QString, QString, QString, QString, QString);

private slots:
    void on_pushButton_clicked();
    void on_Surname_textChanged();
    void on_Name_textChanged();
    void on_Secname_textChanged();
    void on_Phone_textChanged();
    void on_Mail_textChanged();

private:
    Ui::ClientAddForm *ui;
};

#endif // CLIENTADDFORM_H
