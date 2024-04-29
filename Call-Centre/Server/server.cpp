#include "server.h"

//Список id-шников команд используемых в системе
//0 Авторизация
//1 Выход из системы
//2 Получение текущей задачи
//3 Простое завершение задачи
//4 Завершение задачи с оформлением доставки
//5 Завершение задачи с записью в отделение
//6 Завершение задачи с отправкой мастера
//7 Отобажение таблицы текущих аккаунтов
//8 Генерация отчета о деятельности сотрудника
//9 Отобажение pdf-файла
//10 Создание списка удаляемых документов
//11 Удаление документов
//12 Отображение архива
//13 Добавление аккаунта сотрудника
//14 Изменение аккаунта сотрудника
//15 Удаление аккаунта сотрудника

Server::Server()
{
    if (!this->listen(QHostAddress::Any, 2323))
    {
      qDebug() << "Start error";
    }
    else{
        qDebug() << "Server started";
    }
}

void Server::incomingConnection(qintptr socketDesc)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDesc);
    qDebug() << "Client connected";
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    sockets.push_back(socket);
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QByteArray receivedData = socket->readAll();
    qDebug() << "get file";
    QJsonDocument receivedJsonDoc = QJsonDocument::fromJson(receivedData);
    QJsonArray receivedJsonArray = receivedJsonDoc.array();
    if(receivedJsonArray[0].toObject().value("id").toInt() == 0){
        authentification(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 1){
        logout(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 2){
        take_task(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 3){
        end_task(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 4){
        gen_delivery(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 5){
        gen_record(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 6){
        gen_master(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 7){
        output_accounts();
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 8){
        gen_report(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 9){
        view_text(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 10){
        output_delete(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 11){
        delete_files(receivedJsonArray[1].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 12){
        output_archive();
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 13){
        add_acc(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 14){
        change_acc(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 15){
        delete_acc(receivedJsonArray[1].toObject());
    }
}

void Server::authentification(QJsonObject jsonObj)
{
    QString login = jsonObj.value("login").toString();
    QString password = jsonObj.value("password").toString();
    if(logins.contains(login)){
        QJsonObject jsonObj_1;
        jsonObj_1["id"] = 0;
        QJsonObject jsonObj_2;
        jsonObj_2["isOk"] = -1;
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        SendToClient(jsonDoc);
    }
    else {
        logins.append(login);
        QSqlQuery query("SELECT out_status, out_role, out_surname, out_name FROM enter('" + login + "', '" + password + "');");
        query.next();
        if(query.value(0).toBool()) {
            QJsonObject jsonObj_1;
            QJsonObject jsonObj_2;
            jsonObj_1["id"] = 0;
            jsonObj_2["isOk"] = 1;
            jsonObj_2["role"] = query.value(1).toInt();
            jsonObj_2["surname"] = query.value(2).toString();
            jsonObj_2["name"] = query.value(3).toString();
            query.exec("CREATE TABLE IF NOT EXISTS " + login + "_made_tasks (task_id integer PRIMARY KEY, phone_num varchar(15) NOT NULL, task_date date NOT NULL, type integer NOT NULL);");
            query.exec("CREATE TABLE IF NOT EXISTS " + login + "_current (task_id integer PRIMARY KEY, phone_num varchar(15) NOT NULL, task_date date NOT NULL);");
            query.exec("CREATE TABLE IF NOT EXISTS " + login + "_work (_id int PRIMARY KEY, time_begin TIMESTAMP, time_end TIMESTAMP, diff TIME);");
            query.exec("SELECT COALESCE(MAX(_id)+1, 1) FROM " + login + "_work"); //Извлечение максимального id в таблице work и присвоение его переменной _id для дальнейшей работы
            query.next();
            QString _id = query.value(0).toString();
            query.exec("INSERT INTO " + login + "_work VALUES(" + _id + ", (SELECT CURRENT_TIMESTAMP));"); //Внесение времени начала работы пользователя в системе в БД
            jsonObj_2["_id"] = _id;
            QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
            output_tables(login, jsonArray);
        }
        else {
            QJsonObject jsonObj_1;
            jsonObj_1["id"] = 0;
            QJsonObject jsonObj_2;
            jsonObj_2["isOk"] = 0;
            QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
            QJsonDocument jsonDoc(jsonArray);
            SendToClient(jsonDoc);
        }
    }
}

void Server::output_tables(QString login, QJsonArray jsonArray){
    QJsonArray jsonArray_1;
    QJsonObject buffObj;
    int n = 0;
    QSqlQuery query("SELECT task_id, phone_num, task_date, status FROM task WHERE status = FALSE ORDER BY task_date;"); //Получение записей из БД для заполнения таблицы
    while(query.next()){
        n++;
        buffObj["number"] = QString::number(n);
        buffObj["task_id"] = query.value(0).toString();
        buffObj["phone_num"] = query.value(1).toString();
        buffObj["date"] = query.value(2).toDate().toString("dd.MM.yyyy");
        jsonArray_1.append(buffObj);
        buffObj  = QJsonObject();
    }
    QJsonArray jsonArray_2;
    n = 0;
    query.exec("SELECT task_id, task_date FROM " + login + "_current ORDER BY task_id;");
    while(query.next()){
        n++;
        buffObj["number"] = QString::number(n);
        buffObj["task_id"] = query.value(0).toString();
        buffObj["date"] = query.value(1).toDate().toString("dd.MM.yyyy");
        jsonArray_2.append(buffObj);
        buffObj  = QJsonObject();
    }
    jsonArray.append(jsonArray_1);
    jsonArray.append(jsonArray_2);
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::logout(QJsonObject jsonObj){
    QString login = jsonObj.value("login").toString();
    QString _id = jsonObj.value("_id").toString();
    logins.removeOne(login);
    QSqlQuery query("UPDATE " + login + "_work SET time_end = (SELECT CURRENT_TIMESTAMP) WHERE _id = " + _id + ";"); //Запись времени выхода пользователя и запись его в БД
    query.exec("UPDATE " + login + "_work SET diff = (SELECT difference((SELECT time_begin FROM " + login + "_work WHERE _id = " + _id + "), (SELECT time_end FROM " + login + "_work WHERE _id = " + _id + "))) WHERE _id = " + _id + ";"); //Нахождение разницы между временем входа и выхода пользователя и запись её в БД
    query.exec("DROP TABLE " + login + "_current;"); //Удаление таблицы задач обработанных в рамках сессии
}

void Server::take_task(QJsonObject jsonObj){
    QSqlQuery query("SELECT task_id, phone_num, task_date, status FROM task WHERE status = FALSE ORDER BY task_date LIMIT 1;"); //Получение обрабатываемой задачи
    query.next();
    if(query.value(0).toString() != "") {
        QString phone_num = query.value(1).toString();
        QString date = query.value(2).toDate().toString("dd.MM.yyyy");
        QSqlQuery query2("INSERT INTO " + jsonObj.value("login").toString() + "_current(task_id, phone_num, task_date) VALUES (" + query.value(0).toString() + ", '" + phone_num + "', '" + date + "');"); //Запись задачи в обработанные в рамках сессии
        QString id = QString::number(query.value(0).toInt());
        query.exec("UPDATE task SET status = TRUE WHERE task_id = " + id + ";");
        QJsonObject jsonObj_1;
        jsonObj_1["id"] = 2;
        QJsonObject jsonObj_2;
        jsonObj_2["isOk"] = 1;
        jsonObj_2["phone_num"] = phone_num;
        jsonObj_2["date"] = date;
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        SendToClient(jsonDoc);
    }
    else{
        QJsonObject jsonObj_1;
        jsonObj_1["id"] = 2;
        QJsonObject jsonObj_2;
        jsonObj_2["isOk"] = 0;
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        SendToClient(jsonDoc);
    }
}

void Server::end_task(QJsonObject jsonObj){
    QString login = jsonObj.value("login").toString();
    QSqlQuery query("SELECT task_id, phone_num, task_date FROM " + login + "_current ORDER BY task_id DESC LIMIT 1;"); //Получение данных обрабатываемой задачи из БД
    query.next();
    query.exec("INSERT INTO " + login + "_made_tasks (task_id, phone_num, task_date, type) VALUES (" + query.value(0).toString() + ", '" + query.value(1).toString() + "', '" + query.value(2).toString() + "', 0);"); //Запись задачи в список обработанных пользователем
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 3;
    QJsonArray jsonArray = {jsonObj_1};
    output_tables(login, jsonArray);
}

void Server::gen_delivery(QJsonObject jsonObj){
    QString login = jsonObj.value("login").toString();
    QSqlQuery query("SELECT task_id, phone_num, task_date FROM " + login + "_current ORDER BY task_id DESC LIMIT 1;"); //Получение обрабатываемой задачи
    query.next();
    QString date = query.value(2).toString();
    query.exec("INSERT INTO " + login + "_made_tasks (task_id, phone_num, task_date, type) VALUES (" + query.value(0).toString() + ", '" + query.value(1).toString() + "', '" + date + "', 2);"); //Запись задачи в список обработанных пользователем
    query.exec("SELECT COALESCE(MAX(file_id)+1, 1) FROM archive");
    query.next();
    QString fileName = "delivery_" + query.value(0).toString() + ".pdf"; //Создание имени генерируемого файла
    QString filePath = "/home/isd/CallCenter/delivery/" + fileName; //Создание пути к генерируемому файлу
    query.exec("INSERT INTO archive (file_name, file_date, file_path) VALUES ('" + fileName + "', '" + date + "', '" + filePath + "');");
    QPdfWriter pdf(filePath); //Создание файла
    QPainter painter(&pdf); //Инициализация painter
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 14));
    //Запись данных в файл
    int i = 800; //Левый отступ
    int j = 600; //Промежуток между строками
    painter.drawText(i, j, "Акт для отдела логистики.");
    j += 400;
    painter.drawText(i, j, "Клиент: " + jsonObj.value("surname").toString() + " " + jsonObj.value("name").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Устройство: " + jsonObj.value("model").toString() + ".");
    j += 400;
    painter.drawText(i, j, "S/N: " + jsonObj.value("series").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Адрес доставки: " + jsonObj.value("address").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Дата доставки: " + jsonObj.value("date").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Время доставки: " + jsonObj.value("time").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Телефон для связи: " + jsonObj.value("phone_num").toString() + ".");
    painter.end();
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 4;
    QJsonArray jsonArray = {jsonObj_1};
    output_tables(login, jsonArray);
}

void Server::gen_record(QJsonObject jsonObj) {
    QString login = jsonObj.value("login").toString();
    QSqlQuery query("SELECT task_id, phone_num, task_date FROM " + login + "_current ORDER BY task_id DESC LIMIT 1;"); //Получение обрабатываемой задачи
    query.next();
    QString date = query.value(2).toString();
    query.exec("INSERT INTO " + login + "_made_tasks (task_id, phone_num, task_date, type) VALUES (" + query.value(0).toString() + ", '" + query.value(1).toString() + "', '" + date + "', 1);"); //Запись задачи в список обработанных пользователем
    query.exec("SELECT COALESCE(MAX(file_id)+1, 1) FROM archive");
    query.next();
    QString fileName = "record_" + query.value(0).toString() + ".pdf"; //Создание имени генерируемого файла
    QString filePath = "/home/isd/CallCenter/record/" + fileName;
    QSqlQuery query2("INSERT INTO archive (file_name, file_date, file_path) VALUES ('" + fileName + "', '" + date + "', '" + filePath + "');");
    QPdfWriter pdf(filePath);
    QPainter painter(&pdf);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 14));
    int i = 800;
    int j = 600;
    painter.drawText(i, j, "Уважаемый(ая), " + jsonObj.value("surname").toString() + " " + jsonObj.value("name").toString() + ". Для разрешения вашего обращения просим вас");
    j += 400;
    painter.drawText(i, j, "обратиться в наш филиал, расположенный по адресу: " + jsonObj.value("address").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Дата вашей записи: " + jsonObj.value("date").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Время вашей записи: " + jsonObj.value("time").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Телефон для связи: " + jsonObj.value("phone_num").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Убедительно просим удостовериться, что принесенное вами, для дальнейшего");
    j += 400;
    painter.drawText(i, j, "ремонта, устройство соответствует названному нашему сотруднику.");
    j += 500;
    painter.drawText(i, j, "В случае ошибки повторите обращение!");
    j += 500;
    painter.drawText(i, j, "Устройство: " + jsonObj.value("model").toString() + ".");
    j += 400;
    painter.drawText(i, j, "S/N: " + jsonObj.value("series").toString() + ".");
    j += 700;
    painter.drawText(i, j, "Благодарим за выбор нашего сервисного центра.");
    painter.end();
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 5;
    QJsonArray jsonArray = {jsonObj_1};
    output_tables(login, jsonArray);
}

void Server::gen_master(QJsonObject jsonObj) {
    QString login = jsonObj.value("login").toString();
    QSqlQuery query("SELECT task_id, phone_num, task_date FROM " + login + "_current ORDER BY task_id DESC LIMIT 1;"); //Получение обрабатываемой задачи
    query.next();
    QString date = query.value(2).toString();
    query.exec("INSERT INTO " + login + "_made_tasks (task_id, phone_num, task_date, type) VALUES (" + query.value(0).toString() + ", '" + query.value(1).toString() + "', '" + date + "', 2);"); //Запись задачи в список обработанных пользователем
    query.exec("SELECT COALESCE(MAX(file_id)+1, 1) FROM archive");
    query.next();
    QString fileName = "master_" + query.value(0).toString() + ".pdf"; //Создание имени генерируемого файла
    QString filePath = "/home/isd/CallCenter/master/" + fileName; //Создание пути к генерируемому файлу
    query.exec("INSERT INTO archive (file_name, file_date, file_path) VALUES ('" + fileName + "', '" + date + "', '" + filePath + "');");
    QPdfWriter pdf(filePath); //Создание файла
    QPainter painter(&pdf); //Инициализация painter
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 14));
    //Запись данных в файл
    int i = 800; //Левый отступ
    int j = 600; //Промежуток между строками
    painter.drawText(i, j, "Акт для отдела логистики.");
    j += 400;
    painter.drawText(i, j, "Клиент: " + jsonObj.value("surname").toString() + " " + jsonObj.value("name").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Устройство: " + jsonObj.value("model").toString() + ".");
    j += 400;
    painter.drawText(i, j, "S/N: " + jsonObj.value("series").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Адрес приема: " + jsonObj.value("address").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Дата приема: " + jsonObj.value("date").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Время приема: " + jsonObj.value("time").toString() + ".");
    j += 400;
    painter.drawText(i, j, "Телефон для связи: " + jsonObj.value("phone_num").toString() + ".");
    painter.end();
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 6;
    QJsonArray jsonArray = {jsonObj_1};
    output_tables(login, jsonArray);
}

void Server::output_accounts() {
    QSqlQuery query("SELECT login, u_surname, u_role FROM account;"); //получение записей для таблицы из БД
    int n = 0;
    QString r;
    QJsonArray jsonArray_1;
    QJsonObject buffObj;
    while (query.next()) {
        n++;
        r = "";
        if (query.value(2).toInt() == 0){
            r = "Оператор";
        }
        else if (query.value(2).toInt() == 1){
            r = "Супервизор";
        }
        buffObj["number"] = QString::number(n);
        buffObj["login"] = query.value(0).toString();
        buffObj["role"] = r;
        buffObj["surname"] = query.value(1).toString();
        jsonArray_1.append(buffObj);
        buffObj  = QJsonObject();
    }
    buffObj["id"] = 7;
    QJsonArray jsonArray = {buffObj, jsonArray_1};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::gen_report(QJsonObject jsonObj) //Исправь порядок следования в датах отчета
{
    QString login_gen = jsonObj.value("login_gen").toString();
    QString beginDate = jsonObj.value("beginDate").toString();
    QString endDate = jsonObj.value("endDate").toString();
    QSqlQuery query("SELECT SUM(diff) FROM " + login_gen + "_work WHERE (time_begin BETWEEN '" + beginDate + "' AND '" + endDate + "') AND (time_end BETWEEN '" + beginDate + "' AND '" + endDate + "');");
    query.next();
    QString time = query.value(0).toString().mid(0, 8);
    query.exec("SELECT COALESCE(MAX(file_id)+1, 1) FROM archive");
    query.next();
    QString fileName = "report_" + query.value(0).toString() + ".pdf"; //Создание имени генерируемого файла
    QString filePath = "/home/isd/CallCenter/report/" + fileName;
    query.exec("INSERT INTO archive (file_name, file_date, file_path) VALUES ('" + fileName + "', '" + endDate + "', '" + filePath + "');");
    query.exec("SELECT u_surname, u_name FROM account WHERE login = '" + login_gen + "';");
    query.next();
    QPdfWriter pdf(filePath);
    QPainter painter(&pdf);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 14));
    int i = 800;
    int j = 600;
    painter.drawText(i, j, "Отчет о деятельности сотрудника.");
    j += 400;
    painter.drawText(i, j, "Сотрудник: " + query.value(0).toString() + " " + query.value(1).toString() + ".");
    j += 400;
    painter.drawText(i, j, "Общее время работы: " + time + ".");
    j += 400;
    query.exec("SELECT COUNT(*) FROM " + login_gen + "_made_tasks;");
    query.next();
    painter.drawText(i, j, "Всего заявок принято: " + query.value(0).toString() + ".");
    j += 400;
    painter.drawText(i, j, "Дата начала отслеживания деятельности: " + beginDate + ".");
    j += 400;
    painter.drawText(i, j, "Дата начала отслеживания деятельности: " + endDate + ".");
    j += 400;
    painter.drawText(i, j, "Подробности о обработанных заявках изложены ниже.");
    j += 400;
    query.exec("SELECT COUNT(*) FROM " + login_gen + "_made_tasks WHERE type = 0;");
    query.next();
    painter.drawText(i, j, "Решенные заявки: " + query.value(0).toString() + ".");
    j += 400;
    query.exec("SELECT COUNT(*) FROM " + login_gen + "_made_tasks WHERE type = 1;");
    query.next();
    painter.drawText(i, j, "Заявок на запись в отделение: " + query.value(0).toString() + ".");
    j += 400;
    query.exec("SELECT COUNT(*) FROM " + login_gen + "_made_tasks WHERE type = 2;");
    query.next();
    painter.drawText(i, j, "Заявок на оформление доставки: " + query.value(0).toString() + ".");
    j += 400;
    query.exec("SELECT COUNT(*) FROM " + login_gen + "_made_tasks WHERE type = 3;");
    query.next();
    painter.drawText(i, j, "Заявок на отправку мастера: " + query.value(0).toString() + ".");
    painter.end();
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 8;
    QJsonObject jsonObj_2;
    jsonObj_2["path"] = filePath;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::view_text(QJsonObject jsonObj)
{
    Poppler::Document *doc = Poppler::Document::load(jsonObj.value("path").toString());
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 9;
    QJsonObject jsonObj_2;
    QJsonArray jsonArray_1;
    if (!doc || doc->isLocked()) {
        jsonObj_2["isOk"] = 0;
        qDebug() << "Error loading PDF file";
    }
    else {
        jsonObj_2["isOk"] = 1;
        QList<Poppler::TextBox *> box = doc->page(0)->textList();
        QString text;
        QJsonObject buffObj;
        for(int i = 0; i < box.size(); i ++){
            text += box[i]->text();
            if (text.endsWith(".") or text.endsWith("!")){
                buffObj["text"] = text;
                jsonArray_1.append(buffObj);
                buffObj  = QJsonObject();
                text = "";
            }
            else {
                text += " ";
            }
        }
    }
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2, jsonArray_1};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::output_delete(QJsonObject jsonObj)
{
    int n = 0;
    int countDel = jsonObj.value("countDel").toInt();
    QSqlQuery query;
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 10;
    QJsonObject jsonObj_2;
    jsonObj_2["countDel"] = countDel;
    QJsonArray jsonArray_1;
    QJsonObject buffObj;
    if (countDel == 0){
        query.exec("SELECT file_name, file_path FROM archive ORDER BY file_date;");
    }
    else {
        query.exec("SELECT file_name, file_path FROM archive ORDER BY file_date LIMIT " + QString::number(countDel) + ";");
    }
    while(query.next()) {
        n ++;
        buffObj["number"] = QString::number(n);
        buffObj["file_name"] = query.value(0).toString();
        buffObj["file_path"] = query.value(1).toString();
        jsonArray_1.append(buffObj);
        buffObj  = QJsonObject();
    }
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2, jsonArray_1};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::delete_files(QJsonArray jsonArray_1)
{
    QSqlQuery query;
    QString path;
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 11;
    QJsonObject jsonObj_2;
    bool f = 1;
    for (int i = 0; i < jsonArray_1.size(); i ++){
        path = jsonArray_1[i].toObject().value("path").toString();
        QFile file(path);
        if (file.exists()) {
            file.remove();
            query.exec("DELETE FROM archive WHERE file_path = '" + path + "';");
        }
        else {
            f = 0;
        }
    }
    if(f){
        jsonObj_2["isOk"] = 1;
    }
    else{
        jsonObj_2["isOk"] = 0;
    }
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::output_archive() {
    QSqlQuery query("SELECT file_name, file_date, file_path FROM archive ORDER BY file_date;"); //получение записей для таблицы из БД
    int n = 0;
    QJsonArray jsonArray_1;
    QJsonObject buffObj;
    while (query.next()) {
        n++;
        buffObj["number"] = QString::number(n);
        buffObj["file_name"] = query.value(0).toString();
        buffObj["file_date"] = query.value(1).toDate().toString("dd.MM.yyyy");
        buffObj["file_path"] = query.value(2).toString();
        jsonArray_1.append(buffObj);
        buffObj  = QJsonObject();
    }
    buffObj["id"] = 12;
    QJsonArray jsonArray = {buffObj, jsonArray_1};
    QJsonDocument jsonDoc(jsonArray);
    SendToClient(jsonDoc);
}

void Server::add_acc(QJsonObject jsonObj)
{
    QSqlQuery query("INSERT INTO account (login, password_hash, u_role, u_surname, u_name) VALUES('" + jsonObj.value("login").toString() + "', '" + jsonObj.value("password").toString() + "', " + jsonObj.value("role").toString() + ", '" + jsonObj.value("surname").toString() + "', '" + jsonObj.value("name").toString() + "');");
}

void Server::change_acc(QJsonObject jsonObj)
{
    QSqlQuery query("UPDATE account SET password_hash = '" + jsonObj.value("new_password").toString() + "' WHERE login = '" + jsonObj.value("login_change").toString() + "' AND password_hash = '" + jsonObj.value("old_password").toString() + "';");
}

void Server::delete_acc(QJsonObject jsonObj)
{
    QSqlQuery query("DELETE FROM account WHERE login = '" + jsonObj.value("login").toString() + "';");
}

void Server::SendToClient(QJsonDocument jsonDoc){
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
    qDebug() << "send file";
}
