#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QString>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>
#include <QBoxLayout>
#include <QTableWidget>
#include <viewform.h>
#include <QDate>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class archTable : public QTableWidget
{
public:
    enum
    {
        COLUMN_NUMBER,
        COLUMN_NAME,
        COLUMN_DATE_NAME,
        COLUMN_ACTION,
        COLUMN_PATH
    };
};

class docList : public QTableWidget
{
public:
    enum
    {
        COLUMN_NUMBER,
        COLUMN_NAME,
        COLUMN_ACTION,
        COLUMN_BOX,
        COLUMN_PATH
    };
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pop_back_widget();
    // Добавление нового(дочернего) виджета в QStackedWidget
    void push_back_widget(QWidget*);

signals:
    void sendSignal(QJsonArray);

private slots:
    void begin_clicked();
    void accept_clicked();
    void logout_clicked();
    void wTurnBack_clicked();
    void end_clicked();
    void delivery_clicked();
    void receipt_clicked();
    void master_clicked();
    void go_d_clicked();
    void go_r_clicked();
    void go_m_clicked();
    void seeAcc_clicked();
    void returnLookAcc_clicked();
    void genRep_clicked();
    void generate_clicked();
    void seeRep_clicked();
    void returnRep_clicked();
    void delArch_clicked();
    void genList_clicked();
    void returnDel_1_clicked();
    void deleteDoc_clicked();
    void seeArch_clicked();
    void returnArch_clicked();
    void workAcc_clicked();
    void addAcc_clicked();
    void changeAcc_clicked();
    void delAcc_clicked();
    void returnAcc_clicked();
    void add_clicked();
    void returnAddAcc_clicked();
    void change_clicked();
    void returnChangeAcc_clicked();
    void deleteAcc_clicked();
    void returnDelAcc_clicked();
    void authentification(QJsonObject, QJsonArray, QJsonArray);
    bool addNewRowIfAllFilled(QTableWidget* table);
    void OutputActual(QJsonArray, QJsonArray);
    void OutputWork(QJsonObject);
    void end_task(QJsonArray, QJsonArray);
    void gen_delivery(QJsonArray, QJsonArray);
    void gen_record(QJsonArray, QJsonArray);
    void gen_master(QJsonArray, QJsonArray);
    void OutputAccount(QJsonArray);
    void genReport(QJsonObject);
    void viewText(QJsonObject, QJsonArray);
    void OutputArchive(QJsonArray);
    void onBtnClicked();
    void OutputDelete(QJsonObject, QJsonArray);
    void finishDelete(QJsonObject);
    void onBtnDelClicked();
    void setDateBegin();
    void setDateEnd();
    void setDateDefault(QDate, QDate);
    void slotReadyRead();
    void closeEvent(QCloseEvent *event) override;
    void on_count_del_textChanged();
    void on_week_clicked();
    void on_month_clicked();
    void on_quarter_clicked();
    void on_year_clicked();
    void on_custom_clicked();
    void on_login_textChanged();
    void on_password_textChanged();
    void on_surname_d_textChanged();
    void on_name_d_textChanged();
    void on_patronymic_d_textChanged();
    void on_number_d_textChanged();
    void on_model_d_textChanged();
    void on_series_d_textChanged();
    void on_address_d_textChanged();
    void on_time_d_textChanged();
    void on_date_d_textChanged();
    void on_surname_r_textChanged();
    void on_name_r_textChanged();
    void on_patronymic_r_textChanged();
    void on_number_r_textChanged();
    void on_model_r_textChanged();
    void on_series_r_textChanged();
    void on_address_r_textChanged();
    void on_time_r_textChanged();
    void on_date_r_textChanged();
    void on_surname_m_textChanged();
    void on_name_m_textChanged();
    void on_patronymic_m_textChanged();
    void on_number_m_textChanged();
    void on_model_m_textChanged();
    void on_series_m_textChanged();
    void on_address_m_textChanged();
    void on_time_m_textChanged();
    void on_date_m_textChanged();
    void on_FIO_gen_textChanged();
    void on_surname_add_textChanged();
    void on_name_add_textChanged();
    void on_patronymic_add_textChanged();
    void on_role_add_textChanged();
    void on_login_add_textChanged();
    void on_password_add_textChanged();
    void on_login_change_textChanged();
    void on_new_password_textChanged();
    void on_old_password_textChanged();
    void on_login_del_textChanged();
    void on_see_clicked();
    void on_see_2_clicked();
    void on_see_3_clicked();
    void on_see_4_clicked();

private:
    Ui::MainWindow *ui;
    int role;
    QString login;
    QString surname;
    QString name;
    QString _id;
    QString repPath;
    QTcpSocket *socket;
    QByteArray data;
    viewForm *window;
    QWidget* createButtonWidget() const;
    QWidget* createButtonDelWidget() const;
    QCheckBox* createBoxWidget() const;
    QRegExpValidator* rus = new QRegExpValidator(QRegExp("[а-яА-Я]*"));
    QRegExpValidator* eng = new QRegExpValidator(QRegExp("[a-zA-Z0-9]*"));
    QRegExpValidator* address = new QRegExpValidator(QRegExp("[а-яА-Я0-9,]*"));
    QRegExpValidator* time = new QRegExpValidator(QRegExp("[а-яА-Я0-9:]*"));
    QRegExpValidator* date = new QRegExpValidator(QRegExp("[0-9-]*"));
    QRegExpValidator* device = new QRegExpValidator(QRegExp("[a-zA-Z]*"));
    QRegExpValidator* num = new QRegExpValidator(QRegExp("[0-9]*"));
};
#endif // MAINWINDOW_H
