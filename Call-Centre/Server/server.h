#ifndef SERVER_H
#define SERVER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QCryptographicHash>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QFont>
#include <QTextStream>
#include <QPdfWriter>
#include <QPainter>
#include <poppler/qt5/poppler-qt5.h>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;

public slots:
    void incomingConnection(qintptr socketDesc);
    void slotReadyRead();
    void authentification(QJsonObject);
    void output_tables(QString, QJsonArray);
    void logout(QJsonObject);
    void take_task(QJsonObject);
    void end_task(QJsonObject);
    void gen_delivery(QJsonObject);
    void gen_record(QJsonObject);
    void gen_master(QJsonObject);
    void output_accounts();
    void gen_report(QJsonObject);
    void view_text(QJsonObject);
    void output_delete(QJsonObject);
    void delete_files(QJsonArray);
    void output_archive();
    void add_acc(QJsonObject);
    void change_acc(QJsonObject);
    void delete_acc(QJsonObject);

private:
    QVector <QTcpSocket*> sockets;
    QByteArray data;
    void SendToClient(QJsonDocument);
    QStringList logins;
};

#endif // SERVER_H
