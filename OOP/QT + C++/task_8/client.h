#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <clientaddform.h>
#include <clientobject.h>
#include <clientlist.h>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    ClientList *list = new ClientList;

public slots:
    void AddUser(QString, QString, QString, QString, QString);
    void OutputClient();

private slots:
    void on_Return_clicked();
    void on_Add_clicked();
    void on_IndexInput_textChanged();
    void on_SurnameInput_textChanged();
    void on_Search_clicked();
    void on_Delete_clicked();

signals:
    void clientWindow();

private:
    Ui::Client *ui;
    ClientAddForm *clientAddWindow;

};

#endif // CLIENT_H
