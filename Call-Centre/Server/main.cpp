#include <QApplication>
#include "server.h"

void setUpBase(){

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("12345");
    if(!db.open()) {
        qDebug() << db.lastError().text();
    }
    if (!db.tables().contains("CallCenter")) {
        QSqlQuery query("CREATE DATABASE my_new_database");
    }
    db.removeDatabase("QPSQL");
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("CallCenter");
    db.setUserName("postgres");
    db.setPassword("12345");
    if(!db.open()) {
        qDebug() << db.lastError().text();
    }
    QSqlQuery q("CREATE TABLE IF NOT EXISTS account(login varchar(30) PRIMARY KEY, password_hash varchar(255) NOT NULL, u_role integer NOT NULL, u_surname varchar(30) NOT NULL, u_name varchar(30) NOT NULL);");
    q.exec("CREATE TABLE IF NOT EXISTS task(task_id serial PRIMARY KEY, phone_num varchar(15) NOT NULL, task_date date NOT NULL, status bool);");
    q.exec("CREATE OR REPLACE FUNCTION enter(login_try character varying, password_hash_try character varying) RETURNS TABLE(out_status bool, out_role integer, out_surname varchar(30), out_name varchar(30)) AS $$ BEGIN IF EXISTS (SELECT * FROM account WHERE login_try = login AND password_hash_try = password_hash) THEN  RETURN QUERY (SELECT TRUE, u_role, u_surname, u_name FROM account WHERE login_try = login AND password_hash_try = password_hash); ELSE RETURN QUERY (SELECT FALSE, -1, 'NO'::varchar(30), 'NO'::varchar(30)); END IF; END; $$ LANGUAGE plpgsql;");
    q.exec("CREATE TABLE IF NOT EXISTS archive(file_id serial PRIMARY KEY, file_name varchar(30) NOT NULL, file_date date NOT NULL, file_path varchar(255) NOT NULL);");
    q.exec("SELECT login FROM account;");
    q.next();
    if(q.value(0).toString() == ""){
        q.exec("INSERT INTO account (login, password_hash, u_role, u_surname, u_name) VALUES('base', '593616de15330c0fb2d55e55410bf994', 1, 'No', 'No');");
        qDebug() << "INSERT INTO account (login, password_hash, u_role, u_surname, u_name) VALUES('base', '593616de15330c0fb2d55e55410bf994', 1, 'No', 'No');";
    }
    QDir dir("/home/isd");
    if (!dir.exists("CallCenter")) {
        dir.mkpath("CallCenter");
    }
    dir.setPath("/home/isd/CallCenter");
    if (!dir.exists("delivery")) {
        dir.mkpath("delivery");
    }
    if (!dir.exists("master")) {
        dir.mkpath("master");
    }
    if (!dir.exists("record")) {
        dir.mkpath("record");
    }
    if (!dir.exists("report")) {
        dir.mkpath("report");
    }
    Server server;
    return a.exec();
}
