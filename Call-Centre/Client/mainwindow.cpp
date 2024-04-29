#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Принудительная установка страницы авторизации как стартовой
    push_back_widget(ui->mainpage);
    //Установка сокрытия вводимого пароля
    ui->password->setEchoMode(QLineEdit::Password);
    ui->password_add->setEchoMode(QLineEdit::Password);
    ui->new_password->setEchoMode(QLineEdit::Password);
    ui->old_password->setEchoMode(QLineEdit::Password);
    ui->see->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    ui->see_2->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    ui->see_3->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    ui->see_4->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    //Запрет нажатия кнопок до введения данных
    ui->begin->setEnabled(false);
    ui->go_d->setEnabled(false);
    ui->go_r->setEnabled(false);
    ui->go_m->setEnabled(false);
    ui->generete->setEnabled(false);
    ui->add->setEnabled(false);
    ui->change->setEnabled(false);
    ui->deleteAcc->setEnabled(false);
    //Установка масок
    ui->number_d->setInputMask("+7 (999) 999-99-99");
    ui->number_r->setInputMask("+7 (999) 999-99-99");
    ui->number_m->setInputMask("+7 (999) 999-99-99");
    //Запрет на ввод символов в соответствии с ТЗ
    ui->login->setValidator(eng);
    ui->login_add->setValidator(eng);
    ui->login_change->setValidator(eng);
    ui->login_del->setValidator(eng);
    ui->password->setValidator(eng);
    ui->password_add->setValidator(eng);
    ui->new_password->setValidator(eng);
    ui->old_password->setValidator(eng);
    ui->surname_d->setValidator(rus);
    ui->surname_r->setValidator(rus);
    ui->surname_m->setValidator(rus);
    ui->surname_add->setValidator(rus);
    ui->name_d->setValidator(rus);
    ui->name_r->setValidator(rus);
    ui->name_m->setValidator(rus);
    ui->name_add->setValidator(rus);
    ui->patronymic_d->setValidator(rus);
    ui->patronymic_r->setValidator(rus);
    ui->patronymic_m->setValidator(rus);
    ui->patronymic_add->setValidator(rus);
    ui->role_add->setValidator(rus);
    ui->address_d->setValidator(address);
    ui->address_r->setValidator(address);
    ui->address_m->setValidator(address);
    ui->model_d->setValidator(device);
    ui->model_r->setValidator(device);
    ui->model_m->setValidator(device);
    ui->series_d->setValidator(device);
    ui->series_r->setValidator(device);
    ui->series_m->setValidator(device);
    ui->count_del->setValidator(num);
    //Создание окна для отображения pdf файла и связь слота и сигнала для его вызова
    window = new viewForm();
    connect(this, SIGNAL(sendSignal(QJsonArray)), window, SLOT(setText(QJsonArray)));
    //Установка размеров колонок для таблиц
    ui->actual->setColumnWidth(0, ui->actual->width() * 0.08);
    ui->actual->setColumnWidth(1, ui->actual->width() * 0.21);
    ui->actual->setColumnWidth(2, ui->actual->width() * 0.365);
    ui->actual->setColumnWidth(3, ui->actual->width() * 0.34);
    ui->finish->setColumnWidth(0, ui->finish->width() * 0.08);
    ui->finish->setColumnWidth(1, ui->finish->width() * 0.40);
    ui->finish->setColumnWidth(2, ui->finish->width() * 0.513);
    ui->actual_s->setColumnWidth(0, ui->actual_s->width() * 0.08);
    ui->actual_s->setColumnWidth(1, ui->actual_s->width() * 0.21);
    ui->actual_s->setColumnWidth(2, ui->actual_s->width() * 0.36);
    ui->actual_s->setColumnWidth(3, ui->actual_s->width() * 0.34);
    ui->finish_s->setColumnWidth(0, ui->finish_s->width() * 0.08);
    ui->finish_s->setColumnWidth(1, ui->finish_s->width() * 0.40);
    ui->finish_s->setColumnWidth(2, ui->finish_s->width() * 0.513);
    ui->clientInfo->setColumnWidth(0,361);
    ui->hotHelp->setColumnWidth(0,380);
    ui->accLookTable->setColumnWidth(0,40);
    ui->accLookTable->setColumnWidth(1,120);
    ui->accLookTable->setColumnWidth(2,200);
    ui->accLookTable->setColumnWidth(3,337);
    ui->docList->setColumnWidth(0,50);
    ui->docList->setColumnWidth(1,348);
    ui->docList->setColumnWidth(2,149);
    ui->docList->setColumnWidth(3,149);
    ui->docList->hideColumn(4); //Сокрытие столбца
    ui->archLookTable->setColumnWidth(0,50);
    ui->archLookTable->setColumnWidth(1,308);
    ui->archLookTable->setColumnWidth(2,194);
    ui->archLookTable->setColumnWidth(3,154);
    ui->archLookTable->hideColumn(4); //Сокрытие столбца
    ui->beginDate->setDate(QDate::currentDate()); //Установка в поле даты начала генерация отчета текущей даты
    ui->endDate->setDate(QDate::currentDate()); //Установка в поле даты окончания генерация отчета текущей даты
    ui->time_d->setTime(QTime::currentTime());
    ui->date_d->setDate(QDate::currentDate());
    ui->time_r->setTime(QTime::currentTime());
    ui->date_r->setDate(QDate::currentDate());
    ui->time_m->setTime(QTime::currentTime());
    ui->date_m->setDate(QDate::currentDate());
    ui->calendarWidget->setStyleSheet("QTableView{selection-background-color: cyan}"); //Установка подсветки значений на виджете календаря
    connect(ui->accept, &QPushButton::clicked, this, &MainWindow::accept_clicked);
    connect(ui->accept_s, &QPushButton::clicked, this, &MainWindow::accept_clicked);
    connect(ui->logOut, &QPushButton::clicked, this, &MainWindow::logout_clicked);
    connect(ui->logOut_s, &QPushButton::clicked, this, &MainWindow::logout_clicked);
    connect(ui->end, &QPushButton::clicked, this, &MainWindow::end_clicked);
    connect(ui->wTurnBack, &QPushButton::clicked, this, &MainWindow::wTurnBack_clicked);
    connect(ui->delivery, &QPushButton::clicked, this, &MainWindow::delivery_clicked);
    connect(ui->receipt, &QPushButton::clicked, this, &MainWindow::receipt_clicked);
    connect(ui->master, &QPushButton::clicked, this, &MainWindow::master_clicked);
    connect(ui->go_d, &QPushButton::clicked, this, &MainWindow::go_d_clicked);
    connect(ui->go_r, &QPushButton::clicked, this, &MainWindow::go_r_clicked);
    connect(ui->go_m, &QPushButton::clicked, this, &MainWindow::go_m_clicked);
    connect(ui->seeAcc, &QPushButton::clicked, this, &MainWindow::seeAcc_clicked);
    connect(ui->returnLookAcc, &QPushButton::clicked, this, &MainWindow::returnLookAcc_clicked);
    connect(ui->genRep, &QPushButton::clicked, this, &MainWindow::genRep_clicked);
    connect(ui->generete, &QPushButton::clicked, this, &MainWindow::generate_clicked);
    connect(ui->returnRep, &QPushButton::clicked, this, &MainWindow::returnRep_clicked);
    connect(ui->seeRep, &QPushButton::clicked, this, &MainWindow::seeRep_clicked);
    connect(ui->returnDesRep, &QPushButton::clicked, this, &MainWindow::returnRep_clicked);
    connect(ui->delArch, &QPushButton::clicked, this, &MainWindow::delArch_clicked);
    connect(ui->genList, &QPushButton::clicked, this, &MainWindow::genList_clicked);
    connect(ui->returnDel_1, &QPushButton::clicked, this, &MainWindow::returnDel_1_clicked);
    connect(ui->deleteDoc, &QPushButton::clicked, this, &MainWindow::deleteDoc_clicked);
    connect(ui->seeArch, &QPushButton::clicked, this, &MainWindow::seeArch_clicked);
    connect(ui->returnArch, &QPushButton::clicked, this, &MainWindow::returnArch_clicked);
    connect(ui->workAcc, &QPushButton::clicked, this, &MainWindow::workAcc_clicked);
    connect(ui->addAcc, &QPushButton::clicked, this, &MainWindow::addAcc_clicked);
    connect(ui->changeAcc, &QPushButton::clicked, this, &MainWindow::changeAcc_clicked);
    connect(ui->delAcc, &QPushButton::clicked, this, &MainWindow::delAcc_clicked);
    connect(ui->returnAcc, &QPushButton::clicked, this, &MainWindow::returnAcc_clicked);
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::add_clicked);
    connect(ui->returnAddAcc, &QPushButton::clicked, this, &MainWindow::returnAddAcc_clicked);
    connect(ui->change, &QPushButton::clicked, this, &MainWindow::change_clicked);
    connect(ui->returnChangeAcc, &QPushButton::clicked, this, &MainWindow::returnChangeAcc_clicked);
    connect(ui->deleteAcc, &QPushButton::clicked, this, &MainWindow::deleteAcc_clicked);
    connect(ui->returnDelAcc, &QPushButton::clicked, this, &MainWindow::returnDelAcc_clicked);
    connect(ui->begin, &QPushButton::clicked, this, &MainWindow::begin_clicked);
    //Изменение отображения промежутка дат на календаре при изменении дат
    connect(ui->beginDate, &QDateEdit::dateChanged, this, &MainWindow::setDateBegin);
    connect(ui->endDate, &QDateEdit::dateChanged, this, &MainWindow::setDateEnd);
    //Подключение к серверу
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost("127.0.0.1", 2323);
}

void MainWindow::setDateBegin() //Отображение дат на календаре
{
    ui->calendarWidget->setDateRange(ui->beginDate->date(), ui->endDate->date()); //Установка промежутка дат
    if(ui->beginDate->date() > ui->endDate->date()){
        ui->beginDate->setDate(ui->endDate->date());
    }
    ui->custom->setChecked(true); //Установка радиокнопки свой промежуток генерации
}

void MainWindow::setDateEnd() //Отображение дат на календаре
{
    ui->calendarWidget->setSelectedDate(ui->endDate->date());
    ui->calendarWidget->setDateRange(ui->beginDate->date(), ui->endDate->date()); //Установка промежутка дат
    if(ui->beginDate->date() > ui->endDate->date()){
        ui->endDate->setDate(ui->beginDate->date());
    }
    ui->custom->setChecked(true); //Установка радиокнопки свой промежуток генерации
}

void MainWindow::setDateDefault(QDate begin, QDate end) //Отображение дат на календаре для стандартных промежутков
{
    ui->calendarWidget->setDateRange(end, begin); //Установка промежутка дат
    //подкраска ячеек
//    QTextCharFormat fmt;
//    fmt.setBackground(Qt::cyan);
//    ui->calendarWidget->setDateTextFormat(begin, fmt);
//    ui->calendarWidget->setDateTextFormat(end, fmt);
}

void MainWindow::slotReadyRead()
{
    QByteArray receivedData = socket->readAll();
    QJsonDocument receivedJsonDoc = QJsonDocument::fromJson(receivedData);
    QJsonArray receivedJsonArray = receivedJsonDoc.array();
    //qDebug() << receivedJsonDoc;
    if(receivedJsonArray[0].toObject().value("id").toInt() == 0){
        authentification(receivedJsonArray[1].toObject(), receivedJsonArray[2].toArray(), receivedJsonArray[3].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 2){
        OutputWork(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 3){
        end_task(receivedJsonArray[1].toArray(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 4){
        gen_delivery(receivedJsonArray[1].toArray(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 5){
        gen_record(receivedJsonArray[1].toArray(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 6){
        gen_master(receivedJsonArray[1].toArray(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 7){
        OutputAccount(receivedJsonArray[1].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 8){
        genReport(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 9){
        viewText(receivedJsonArray[1].toObject(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 10){
        OutputDelete(receivedJsonArray[1].toObject(), receivedJsonArray[2].toArray());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 11){
        finishDelete(receivedJsonArray[1].toObject());
    }
    else if(receivedJsonArray[0].toObject().value("id").toInt() == 12){
        OutputArchive(receivedJsonArray[1].toArray());
    }
}

bool MainWindow::addNewRowIfAllFilled(QTableWidget* table)
{
    bool f = true;
    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem* item = table->item(row, col);
            if (!item && row == 0){
                f = true;
                break;
            }
            else if (!item || item->text().isEmpty()) {
                f = false;
                break;
            }
        }
    }
    if (f) {
        int newRow = table->rowCount();
        table->insertRow(newRow);
        table->setVerticalHeaderItem(newRow, new QTableWidgetItem(""));
        return 1;
    }
    return 0;
}

void MainWindow::OutputActual(QJsonArray jsonArr1, QJsonArray jsonArr2) //Отображение таблицы
{
    QTableWidget* table;
    QTableWidgetItem *item; //Создание объекта таблицы
    QJsonObject currentObj;
    bool f = 1;
    if (role == 0) {table = ui->actual;} //Чистка старых записей
    else if (role == 1) {table = ui->actual_s;}
    else {f = 0;}
    if (f){
        table->clearContents();
        for (int i = 0; i < jsonArr1.size(); i ++) {
            currentObj = jsonArr1[i].toObject();
            if (currentObj.value("status").toBool() == false) {
                if(addNewRowIfAllFilled(table)){
                    table->setColumnWidth(2, table->width() * 0.35);
                    table->setColumnWidth(3, table->width() * 0.317);
                }
                for (int j = 0; j < 4; j ++) {
                    switch (j) {
                    case(0): item = new QTableWidgetItem(currentObj.value("number").toString());
                        break;
                    case(1): item = new QTableWidgetItem(currentObj.value("task_id").toString());
                        break;
                    case(2): item = new QTableWidgetItem(currentObj.value("phone_num").toString());
                        break;
                    case(3): item = new QTableWidgetItem(currentObj.value("date").toString());
                        break;
                    //Выбор переменной соответствующей текущей ячейке
                    }
                    table->setItem(i, j, item); //Запись в ячейку
                }
            }
        }
    }
    f = 1;
    if (role == 0) {table = ui->finish;}
    else if (role == 1) {table = ui->finish_s;}
    else {f = 0;}
    if (f){
        table->clearContents(); //Чистка старых записей
        for (int i = 0; i < jsonArr2.size(); i ++) {
            currentObj = jsonArr2[i].toObject();
            if(addNewRowIfAllFilled(table)){
                table->setColumnWidth(1, table->width() * 0.377);
                table->setColumnWidth(2, table->width() * 0.50);
            }
            for (int j = 0; j < 3; j ++) {
                switch (j) {
                case(0): item = new QTableWidgetItem(currentObj.value("number").toString());
                    break;
                case(1): item = new QTableWidgetItem(currentObj.value("task_id").toString());
                    break;
                case(2): item = new QTableWidgetItem(currentObj.value("date").toString("dd.MM.yyyy"));
                    break;
                //Выбор переменной соответствующей текущей ячейке
                }
                table->setItem(i, j, item); //Запись в ячейку
            }
        }
    }
    //delete item;
}

void MainWindow::authentification(QJsonObject jsonObj, QJsonArray jsonArr1, QJsonArray jsonArr2)
{
    if(jsonObj.value("isOk").toInt() == 1) {
        login = ui->login->text();
        role = jsonObj.value("role").toInt();
        surname = jsonObj.value("surname").toString();
        name = jsonObj.value("name").toString();
        _id = jsonObj.value("_id").toString();
        if(role == 1) //Переход к окну супервизора
        {
            ui->surname_s->setText(surname);
            ui->name_s->setText(name);
            OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
            push_back_widget(ui->supermainpage);
        }
        else if(role == 0) //Переход к окну оператора
        {
            ui->surname->setText(surname);
            ui->name->setText(name);
            OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
            push_back_widget(ui->mainpage);
        }
    }
    else if(jsonObj.value("isOk").toInt() == -1){
        ui->login->setText("");
        ui->password->setText("");
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка авторизации!", "Похоже кто-то уже использует этот аккаунт!\nДля уточнения свяжитесь с администратором");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        ui->login->setText("");
        ui->password->setText("");
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка авторизации!", "Повторите вход!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::begin_clicked() //Завершение обработки окна авторизации
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 0;
    jsonObj_2["login"] = ui->login->text();
    jsonObj_2["password"] = QString::fromUtf8(QCryptographicHash::hash(ui->password->text().toLatin1(),QCryptographicHash::Md5).toHex());
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::logout_clicked() //Обработка выхода из системы
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 1;
    jsonObj_2["login"] = login;
    jsonObj_2["_id"] = _id;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
    ui->login->setText("");
    ui->password->setText("");
    push_back_widget(ui->autorizationpage);
}

void MainWindow::OutputWork(QJsonObject jsonObj) //Отображение таблицы
{
    if (jsonObj.value("isOk").toInt() == 1) {
        ui->clientInfo->clearContents(); //Чистка старых записей
        QTableWidgetItem *item = new QTableWidgetItem(jsonObj.value("date").toString("dd.MM.yyyy"));
        ui->clientInfo->setItem(0, 0, item);
        item = new QTableWidgetItem(jsonObj.value("phone_num").toString());
        ui->clientInfo->setItem(1, 0, item);
        push_back_widget(ui->workpage);
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Нет доступных для выполнения задач!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::accept_clicked() //Обработка нажатия кнопки принятия задачи
{
    ui->surname_w->setText(surname);
    ui->name_w->setText(name);
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 2;
    QJsonObject jsonObj_2;
    jsonObj_2["login"] = login;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void::MainWindow::end_task(QJsonArray jsonArr1, QJsonArray jsonArr2){
    if(role == 1) //Переход к окну супервизора
    {
        ui->surname_s->setText(surname);
        ui->name_s->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->supermainpage);
    }
    else if(role == 0) //Переход к окну оператора
    {
        ui->surname->setText(surname);
        ui->name->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->mainpage);
    }
}

void MainWindow::end_clicked() //Обработка нажатия кнопки завершения выполнения задачи
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 3;
    jsonObj_2["login"] = login;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::wTurnBack_clicked() //Обработка нажатия кнопки выбора результата обработки задачи
{
    push_back_widget(ui->finalworkpage);
}

void MainWindow::delivery_clicked() //Обработка нажатия кнопки перехода к окну оформления доставки
{
    push_back_widget(ui->deliverypage);
}

void MainWindow::receipt_clicked() //Обработка нажатия кнопки перехода к окну оформления записи
{
    push_back_widget(ui->receiptpage);
}

void MainWindow::master_clicked() //Обработка нажатия кнопки перехода к окну оформления вызова мастера
{
    push_back_widget(ui->masterpage);
}

void MainWindow::gen_delivery(QJsonArray jsonArr1, QJsonArray jsonArr2)
{
    ui->surname_d->setText("");
    ui->name_d->setText("");
    ui->model_d->setText("");
    ui->series_d->setText("");
    ui->address_d->setText("");
    ui->time_d->setTime(QTime::currentTime());
    ui->date_d->setDate(QDate::currentDate());
    ui->number_d->setText("");
    if(role == 1) //Переход к окну супервизора
    {
        ui->surname_s->setText(surname);
        ui->name_s->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->supermainpage);
    }
    else if(role == 0) //Переход к окну оператора
    {
        ui->surname->setText(surname);
        ui->name->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->mainpage);
    }
}

void MainWindow::go_d_clicked() //Генерация документа о оформлении доставки и переход к основному рабочему окну
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 4;
    jsonObj_2["login"] = login;
    jsonObj_2["surname"] = ui->surname_d->text();
    jsonObj_2["name"] = ui->name_d->text();
    jsonObj_2["model"] = ui->model_d->text();
    jsonObj_2["series"] = ui->series_d->text();
    jsonObj_2["address"] = ui->address_d->text();
    jsonObj_2["date"] = ui->date_d->text();
    jsonObj_2["time"] = ui->time_d->text();
    jsonObj_2["phone_num"] = ui->number_d->text();
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::gen_record(QJsonArray jsonArr1, QJsonArray jsonArr2)
{
    ui->surname_r->setText("");
    ui->name_r->setText("");
    ui->model_r->setText("");
    ui->series_r->setText("");
    ui->address_r->setText("");
    ui->time_r->setTime(QTime::currentTime());
    ui->date_r->setDate(QDate::currentDate());
    ui->number_r->setText("");
    if(role == 1) //Переход к окну супервизора
    {
        ui->surname_s->setText(surname);
        ui->name_s->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->supermainpage);
    }
    else if(role == 0) //Переход к окну оператора
    {
        ui->surname->setText(surname);
        ui->name->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->mainpage);
    }
}

void MainWindow::go_r_clicked() //Генерация документа о записи в отделение и переход к основному рабочему окну
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 5;
    jsonObj_2["login"] = login;
    jsonObj_2["surname"] = ui->surname_r->text();
    jsonObj_2["name"] = ui->name_r->text();
    jsonObj_2["model"] = ui->model_r->text();
    jsonObj_2["series"] = ui->series_r->text();
    jsonObj_2["address"] = ui->address_r->text();
    jsonObj_2["date"] = ui->date_r->text();
    jsonObj_2["time"] = ui->time_r->text();
    jsonObj_2["phone_num"] = ui->number_r->text();
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::gen_master(QJsonArray jsonArr1, QJsonArray jsonArr2)
{
    ui->surname_m->setText("");
    ui->name_m->setText("");
    ui->model_m->setText("");
    ui->series_m->setText("");
    ui->address_m->setText("");
    ui->time_m->setTime(QTime::currentTime());
    ui->date_m->setDate(QDate::currentDate());
    ui->number_m->setText("");
    if(role == 1) //Переход к окну супервизора
    {
        ui->surname_s->setText(surname);
        ui->name_s->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->supermainpage);
    }
    else if(role == 0) //Переход к окну оператора
    {
        ui->surname->setText(surname);
        ui->name->setText(name);
        OutputActual(jsonArr1, jsonArr2); //Вызов функции заполнения таблиц
        push_back_widget(ui->mainpage);
    }
}

void MainWindow::go_m_clicked() //Генерация документа о вызове мастера и переход к основному рабочему окну
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 6;
    jsonObj_2["login"] = login;
    jsonObj_2["surname"] = ui->surname_m->text();
    jsonObj_2["name"] = ui->name_m->text();
    jsonObj_2["model"] = ui->model_m->text();
    jsonObj_2["series"] = ui->series_m->text();
    jsonObj_2["address"] = ui->address_m->text();
    jsonObj_2["date"] = ui->date_m->text();
    jsonObj_2["time"] = ui->time_m->text();
    jsonObj_2["phone_num"] = ui->number_m->text();
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::OutputAccount(QJsonArray jsonArr) //Отображение таблицы
{
    ui->accLookTable->clearContents(); //Чистка старых записей
    QTableWidgetItem *item; //Создание объекта таблицы
    QJsonObject currentObj;
    for (int i = 0; i < jsonArr.size(); i ++) {
        currentObj = jsonArr[i].toObject();
        if (currentObj.value("status").toBool() == false) {
            if(addNewRowIfAllFilled(ui->accLookTable)){
                ui->accLookTable->setColumnWidth(3,322);
            }
            for (int j = 0; j < 4; j ++) {
                switch (j) {
                case(0): item = new QTableWidgetItem(currentObj.value("number").toString());
                    break;
                case(1): item = new QTableWidgetItem(currentObj.value("login").toString());
                    break;
                case(2): item = new QTableWidgetItem(currentObj.value("role").toString());
                    break;
                case(3): item = new QTableWidgetItem(currentObj.value("surname").toString());
                    break;
                //Выбор переменной соответствующей текущей ячейке
                }
                ui->accLookTable->setItem(i, j, item);
            }
        }
    }
    push_back_widget(ui->acclookpage);
}

void MainWindow::seeAcc_clicked()
{
    QJsonObject jsonObj;
    jsonObj["id"] = 7;
    QJsonArray jsonArray = {jsonObj};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::returnLookAcc_clicked()
{
    push_back_widget(ui->supermainpage);
}

void MainWindow::genRep_clicked()
{
    push_back_widget(ui->reportpage);
}

void MainWindow::genReport(QJsonObject jsonObj){
    repPath = jsonObj.value("path").toString();
}

void MainWindow::generate_clicked()
{
    QDate currentDate = QDate::currentDate();
    QDate boarderDate;
    QString login_gen = ui->FIO_gen->text();
    bool f = 1;
    if (ui->week->isChecked()) {
        boarderDate = currentDate.addDays(-7);
    }
    else if (ui->month->isChecked()) {
        boarderDate = currentDate.addMonths(-1);
    }
    else if (ui->quarter->isChecked()) {
        boarderDate = currentDate.addMonths(-3);
    }
    else if (ui->year->isChecked()) {
        boarderDate = currentDate.addYears(-1);
    }
    else if (ui->custom->isChecked()) {
        currentDate = ui->beginDate->date();
        boarderDate = ui->endDate->date();
    }
    else {
        f = 0;
    }
    if(f) {
        currentDate = currentDate.addDays(+1);
        QJsonObject jsonObj_1;
        QJsonObject jsonObj_2;
        jsonObj_1["id"] = 8;
        jsonObj_2["login_gen"] = login_gen;
        jsonObj_2["beginDate"] = boarderDate.toString("yyyy-MM-dd");
        jsonObj_2["endDate"] = currentDate.toString("yyyy-MM-dd");
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        QByteArray jsonData = jsonDoc.toJson();
        socket->write(jsonData);
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Невозможна генерация отчета без заданного периода времени!");
        messageBox.setFixedSize(500,200);
    }
    push_back_widget(ui->reportdespage);
}

void MainWindow::viewText(QJsonObject jsonObj, QJsonArray jsonArray)
{
    if(jsonObj.value("isOk").toInt() == 1) {
        emit sendSignal(jsonArray);
        window->show();
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Ошибка отображения файла!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::seeRep_clicked()
{
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 9;
    jsonObj_2["path"] = repPath;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::returnRep_clicked()
{
    ui->beginDate->setDate(QDate::currentDate());
    ui->endDate->setDate(QDate::currentDate());
    ui->FIO_gen->setText("");
    repPath = "";
    push_back_widget(ui->supermainpage);
}

void MainWindow::delArch_clicked()
{
    push_back_widget(ui->deletepage_1);
}

void MainWindow::OutputDelete(QJsonObject jsonObj, QJsonArray jsonArray) //Отображение таблицы
{
    int countDel = jsonObj.value("countDel").toInt();
    if (countDel == -1){
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Необходимо выбрать количество документов для удаления!");
        messageBox.setFixedSize(500,200);
    }
    else {
        QTableWidgetItem *item;
        ui->docList->clearContents();
        for(int i = 0; i < jsonArray.size(); i ++) {
            if(addNewRowIfAllFilled(ui->docList)){
                ui->docList->setColumnWidth(0,333);
            }
            item = new QTableWidgetItem(jsonArray[i].toObject().value("number").toString());
            ui->docList->setItem(i, 0, item);
            item = new QTableWidgetItem(jsonArray[i].toObject().value("file_name").toString());
            ui->docList->setItem(i, 1, item);
            ui->docList->setIndexWidget(ui->docList->model()->index(i, docList::COLUMN_ACTION), createButtonDelWidget());
            ui->docList->setIndexWidget(ui->docList->model()->index(i, docList::COLUMN_BOX), createBoxWidget());
            ui->docList->rowHeight(50);
            ui->docList->model()->setData(ui->docList->model()->index(i, docList::COLUMN_PATH), jsonArray[i].toObject().value("file_path").toString());
        }
        push_back_widget(ui->deletepage_2);
    }
}

void MainWindow::onBtnDelClicked() {
    if(QPushButton* btn = qobject_cast< QPushButton* >(sender()))  {
        QModelIndex index = ui->docList->indexAt(btn->parentWidget()->pos());
        QString path;
        QString name;
        for(int i = 0; i < ui->docList->rowCount(); ++i) {
            if (i == docList::COLUMN_NAME){
                path = ui->docList->model()->data(ui->docList->model()->index(index.row(), docList::COLUMN_PATH)).toString();
                QJsonObject jsonObj_1;
                QJsonObject jsonObj_2;
                jsonObj_1["id"] = 9;
                jsonObj_2["path"] = path;
                QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
                QJsonDocument jsonDoc(jsonArray);
                QByteArray jsonData = jsonDoc.toJson();
                socket->write(jsonData);
                break;
            }
        }
    }
}

QWidget* MainWindow::createButtonDelWidget() const {
    QWidget* wgt = new QWidget;
    QBoxLayout* l = new QHBoxLayout;
    QPushButton* btn = new QPushButton("");
    btn->setFixedSize(30, 30);
    btn->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/pdf.jpg);" "}");
    connect(btn, SIGNAL(clicked(bool)), SLOT(onBtnDelClicked()));
    l->setMargin(0);
    l->addStretch();
    l->addWidget(btn);
    l->addStretch();
    wgt->setLayout(l);
    return wgt;
}

QCheckBox* MainWindow::createBoxWidget() const {
    QCheckBox* box = new QCheckBox("");
    box->setStyleSheet("margin-left:68%;");
    return box;
}

void MainWindow::genList_clicked()
{
    int countDel;
    if (ui->deleteAll->isChecked()){
        countDel = 0;
    }
    else if (ui->deleteCustom->isChecked()){
        countDel = ui->count_del->text().toInt();
    }
    else {
        countDel = -1;
    }
    ui->count_del->setText("");
    QJsonObject jsonObj_1;
    QJsonObject jsonObj_2;
    jsonObj_1["id"] = 10;
    jsonObj_2["countDel"] = countDel;
    QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::returnDel_1_clicked()
{
    ui->count_del->setText("");
    push_back_widget(ui->supermainpage);
}

void MainWindow::finishDelete(QJsonObject jsonObj)
{
    if(jsonObj.value("isOk").toInt() == 1) {
        push_back_widget(ui->supermainpage);
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Во время удаления файлов произошла ошибка!");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::deleteDoc_clicked()
{
    QString path;
    QJsonObject jsonObj_1;
    QJsonObject buffObj;
    QJsonArray jsonArray_1;
    jsonObj_1["id"] = 11;
    for (int row = 0; row < ui->docList->rowCount(); ++row) {
        QWidget* cellWidget = ui->docList->cellWidget(row, 3);
        if (cellWidget) {
            QCheckBox* box = qobject_cast<QCheckBox*>(cellWidget);
            if (box && box->isChecked()) {
                path = ui->docList->model()->data(ui->docList->model()->index(row, docList::COLUMN_PATH)).toString();
                buffObj["path"] = path;
                jsonArray_1.append(buffObj);
                buffObj  = QJsonObject();
            }
        }
    }
    QJsonArray jsonArray = {jsonObj_1, jsonArray_1};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::OutputArchive(QJsonArray jsonArray) //Отображение таблицы
{
    QTableWidgetItem *item; //Создание объекта таблицы
    ui->archLookTable->clearContents();
    for(int i = 0; i < jsonArray.size(); i ++) {
        if(addNewRowIfAllFilled(ui->archLookTable)){
            ui->archLookTable->setColumnWidth(1,293);
        }
        for (int j = 0; j < 3; j ++) {
            switch (j) {
            case(0): item = new QTableWidgetItem(jsonArray[i].toObject().value("number").toString());
                break;
            case(1): item = new QTableWidgetItem(jsonArray[i].toObject().value("file_name").toString());
                break;
            case(2): item = new QTableWidgetItem(jsonArray[i].toObject().value("file_date").toString());
                break;
            }
            ui->archLookTable->setItem(i, j, item);
        }
        ui->archLookTable->setIndexWidget(ui->archLookTable->model()->index(i, archTable::COLUMN_ACTION), createButtonWidget()); //создание кнопки как элемента таблицы
        ui->archLookTable->rowHeight(50);
        ui->archLookTable->model()->setData(ui->archLookTable->model()->index(i, archTable::COLUMN_PATH), jsonArray[i].toObject().value("file_path").toString());
    }
    push_back_widget(ui->archlookpage);
}

void MainWindow::onBtnClicked() {
    if(QPushButton* btn = qobject_cast< QPushButton* >(sender()))  {
        QModelIndex index = ui->archLookTable->indexAt(btn->parentWidget()->pos());
        QString path;
        QString name;
        for(int i = 0; i < ui->archLookTable->rowCount(); ++i) {
            if (i == archTable::COLUMN_NAME){
                path = ui->archLookTable->model()->data(ui->archLookTable->model()->index(index.row(), archTable::COLUMN_PATH)).toString();
                QJsonObject jsonObj_1;
                QJsonObject jsonObj_2;
                jsonObj_1["id"] = 9;
                jsonObj_2["path"] = path;
                QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
                QJsonDocument jsonDoc(jsonArray);
                QByteArray jsonData = jsonDoc.toJson();
                socket->write(jsonData);
                break;
            }
        }
    }
}

QWidget* MainWindow::createButtonWidget() const {
    QWidget* wgt = new QWidget;
    QBoxLayout* l = new QHBoxLayout;
    QPushButton* btn = new QPushButton("");
    btn->setFixedSize(30, 30);
    btn->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/pdf.jpg);" "}");
    connect(btn, SIGNAL(clicked(bool)), SLOT(onBtnClicked()));
    l->setMargin(0);
    l->addStretch();
    l->addWidget(btn);
    l->addStretch();
    wgt->setLayout(l);
    return wgt;
}

void MainWindow::seeArch_clicked()
{
    QJsonObject jsonObj_1;
    jsonObj_1["id"] = 12;
    QJsonArray jsonArray = {jsonObj_1};
    QJsonDocument jsonDoc(jsonArray);
    QByteArray jsonData = jsonDoc.toJson();
    socket->write(jsonData);
}

void MainWindow::returnArch_clicked()
{
    push_back_widget(ui->supermainpage);
}

void MainWindow::workAcc_clicked()
{
    push_back_widget(ui->workaccpage);
}

void MainWindow::addAcc_clicked()
{
    push_back_widget(ui->addaccpage);
}

void MainWindow::changeAcc_clicked()
{
    push_back_widget(ui->changeaccpage);
}

void MainWindow::delAcc_clicked()
{
    push_back_widget(ui->delaccpage);
}

void MainWindow::returnAcc_clicked()
{
    push_back_widget(ui->supermainpage);
}

void MainWindow::add_clicked()
{
    int role;
    bool f = 1;
    if (ui->role_add->text() == "Оператор"){
        role = 0;
    }
    else if (ui->role_add->text() == "Супервизор"){
        role = 1;
    }
    else {
        f = 0;
    }
    if(f){
        QJsonObject jsonObj_1;
        QJsonObject jsonObj_2;
        jsonObj_1["id"] = 13;
        jsonObj_2["login"] = ui->login_add->text();
        jsonObj_2["password"] = QString::fromUtf8(QCryptographicHash::hash(ui->password_add->text().toLatin1(),QCryptographicHash::Md5).toHex());
        jsonObj_2["surname"] = ui->surname_add->text();
        jsonObj_2["name"] = ui->name_add->text();
        jsonObj_2["role"] = QString::number(role);
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        QByteArray jsonData = jsonDoc.toJson();
        socket->write(jsonData);
        push_back_widget(ui->supermainpage);
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Не существует введенной роли!");
        messageBox.setFixedSize(500,200);
    }
    //Отчистка полей записи
    ui->login_add->setText("");
    ui->name_add->setText("");
    ui->surname_add->setText("");
    ui->patronymic_add->setText("");
    ui->password_add->setText("");
    ui->role_add->setText("");
}

void MainWindow::returnAddAcc_clicked()
{
    //Отчистка полей записи
    ui->login_add->setText("");
    ui->name_add->setText("");
    ui->surname_add->setText("");
    ui->patronymic_add->setText("");
    ui->password_add->setText("");
    ui->role_add->setText("");
    push_back_widget(ui->workaccpage);
}

void MainWindow::change_clicked()
{
    QString pwn = ui->new_password->text();
    QString pwo = ui->old_password->text();
    if (ui->login_change->text() != login) {
        QJsonObject jsonObj_1;
        QJsonObject jsonObj_2;
        jsonObj_1["id"] = 14;
        jsonObj_2["login_change"] = ui->login_change->text();
        jsonObj_2["new_password"] = QString::fromUtf8(QCryptographicHash::hash(ui->new_password->text().toLatin1(),QCryptographicHash::Md5).toHex());
        jsonObj_2["old_password"] = QString::fromUtf8(QCryptographicHash::hash(ui->old_password->text().toLatin1(),QCryptographicHash::Md5).toHex());
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        QByteArray jsonData = jsonDoc.toJson();
        socket->write(jsonData);
        push_back_widget(ui->supermainpage);
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Нельзя редактировать используемый аккаунт!");
        messageBox.setFixedSize(500,200);
    }
    //Отчистка полей записи
    ui->login_change->setText("");
    ui->old_password->setText("");
    ui->new_password->setText("");
}

void MainWindow::returnChangeAcc_clicked()
{
    //Отчистка полей записи
    ui->login_change->setText("");
    ui->old_password->setText("");
    ui->new_password->setText("");
    push_back_widget(ui->workaccpage);
}

void MainWindow::deleteAcc_clicked()
{
    if (ui->login_del->text() != login) {
        QJsonObject jsonObj_1;
        QJsonObject jsonObj_2;
        jsonObj_1["id"] = 15;
        jsonObj_2["login"] = ui->login_del->text();
        QJsonArray jsonArray = {jsonObj_1, jsonObj_2};
        QJsonDocument jsonDoc(jsonArray);
        QByteArray jsonData = jsonDoc.toJson();
        socket->write(jsonData);
        push_back_widget(ui->supermainpage);
    }
    else {
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Нельзя удалить используемый аккаунт!");
        messageBox.setFixedSize(500,200);
    }
    //Отчистка полей записи
    ui->login_del->setText("");
    ui->reason->setText("");
}

void MainWindow::returnDelAcc_clicked()
{
    //Отчистка полей записи
    ui->login_del->setText("");
    ui->reason->setText("");
    push_back_widget(ui->workaccpage);
}

void MainWindow::pop_back_widget() //Удаление отображаемого виджета из QStackedWidget
{
    QWidget *widget = ui->stackedWidget->currentWidget();
    if (ui->stackedWidget->indexOf(widget) >= 0) {
        ui->stackedWidget->removeWidget(widget);
        widget->close();
    }
}

void MainWindow::push_back_widget(QWidget *widget) //Добавление нового виджета в QStackedWidget
{
    if (ui->stackedWidget->indexOf(widget) <= 0) {
        pop_back_widget();
    }
    ui->stackedWidget->addWidget(widget);
    ui->stackedWidget->setCurrentWidget(widget);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->stackedWidget->currentWidget() == ui->autorizationpage){
        event->accept();
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0, "Ошибка!", "Перед закрытием программы необходимо выйти из системы!");
        messageBox.setFixedSize(500,200);
        event->ignore();
    }
}

//Блок активации кнопки генерации отчета
void MainWindow::on_week_clicked() //Установка отметки промежутка времени для недели
{
    setDateDefault(QDate::currentDate(), QDate::currentDate().addDays(-7));
    if(ui->FIO_gen->text() != ""){
        ui->generete->setEnabled(true);
    }
}

void MainWindow::on_month_clicked() //Установка отметки промежутка времени для месяца
{
    setDateDefault(QDate::currentDate(), QDate::currentDate().addMonths(-1));
    if(ui->FIO_gen->text() != ""){
        ui->generete->setEnabled(true);
    }
}

void MainWindow::on_quarter_clicked() //Установка отметки промежутка времени для квартала
{
    setDateDefault(QDate::currentDate(), QDate::currentDate().addMonths(-3));
    if(ui->FIO_gen->text() != ""){
        ui->generete->setEnabled(true);
    }
}

void MainWindow::on_year_clicked() //Установка отметки промежутка времени для года
{
    setDateDefault(QDate::currentDate(), QDate::currentDate().addYears(-1));
    if(ui->FIO_gen->text() != ""){
        ui->generete->setEnabled(true);
    }
}

void MainWindow::on_custom_clicked()
{
    if(ui->FIO_gen->text() != ""){
        ui->generete->setEnabled(true);
    }
}

//Блок отвечающий за активацию кнопки входа
void MainWindow::on_login_textChanged()
{
    if (ui->login->text() != "" && ui->password->text() != "") {
        ui->begin->setEnabled(true);
    }
    else {
        ui->begin->setEnabled(false);
    }
}

void MainWindow::on_password_textChanged()
{
    if (ui->login->text() != "" && ui->password->text() != "") {
        ui->begin->setEnabled(true);
    }
    else {
        ui->begin->setEnabled(false);
    }
}

//Блок отвечающий за активацию кнопки оформления заявления на доставку
void MainWindow::on_surname_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_name_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_patronymic_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_number_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_model_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_series_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_address_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_time_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

void MainWindow::on_date_d_textChanged()
{
    if (ui->surname_d->text() != "" && ui->name_d->text() != "" && ui->patronymic_d->text() != "" && ui->number_d->text() != "" && ui->model_d->text() != "" && ui->series_d->text() != "" && ui->address_d->text() != "" && ui->time_d->text() != "" && ui->date_d->text() != "") {
        ui->go_d->setEnabled(true);
    }
    else {
        ui->go_d->setEnabled(false);
    }
}

//Блок отвечающий за активацию кнопки оформления записи в отделение
void MainWindow::on_surname_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_name_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_patronymic_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_number_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_model_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_series_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_address_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_time_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

void MainWindow::on_date_r_textChanged()
{
    if (ui->surname_r->text() != "" && ui->name_r->text() != "" && ui->patronymic_r->text() != "" && ui->number_r->text() != "" && ui->model_r->text() != "" && ui->series_r->text() != "" && ui->address_r->text() != "" && ui->time_r->text() != "" && ui->date_r->text() != "") {
        ui->go_r->setEnabled(true);
    }
    else {
        ui->go_r->setEnabled(false);
    }
}

//Блок отвечающий за активацию кнопки оформления отправки мастера
void MainWindow::on_surname_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_name_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_patronymic_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_number_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_model_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_series_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_address_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_time_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_date_m_textChanged()
{
    if (ui->surname_m->text() != "" && ui->name_m->text() != "" && ui->patronymic_m->text() != "" && ui->number_m->text() != "" && ui->model_m->text() != "" && ui->series_m->text() != "" && ui->address_m->text() != "" && ui->time_m->text() != "" && ui->date_m->text() != "") {
        ui->go_m->setEnabled(true);
    }
    else {
        ui->go_m->setEnabled(false);
    }
}

void MainWindow::on_FIO_gen_textChanged() //Активация кнопки генерации отчета о сотруднике
{
    if(ui->FIO_gen->text() != "" && (ui->week->isChecked() == true || ui->month->isChecked() == true || ui->quarter->isChecked() == true || ui->year->isChecked() == true || ui->custom->isChecked() == true)){
        ui->generete->setEnabled(true);
    }
    else {
        ui->generete->setEnabled(false);
    }
}

void MainWindow::on_count_del_textChanged() //Установка радиокнопки своего количества док-тов при изменении текстового поля количество док-тов
{
    ui->deleteCustom->setChecked(true);
}

//Блок отвечающий за активацию кнопки добавления аккаунта сотрудника
void MainWindow::on_surname_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

void MainWindow::on_name_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

void MainWindow::on_patronymic_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

void MainWindow::on_role_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

void MainWindow::on_login_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

void MainWindow::on_password_add_textChanged()
{
    if (ui->surname_add->text() != "" && ui->name_add->text() != "" && ui->patronymic_add->text() != "" && ui->role_add->text() != "" && ui->login_add->text() != "" && ui->password_add->text() != "") {
        ui->add->setEnabled(true);
    }
    else {
        ui->add->setEnabled(false);
    }
}

//Блок отвечающий за активацию кнопки изменения аккаунта сотрудника
void MainWindow::on_login_change_textChanged()
{
    if (ui->login_change->text() != "" && ui->new_password->text() != "" && ui->old_password->text() != "") {
        ui->change->setEnabled(true);
    }
    else {
        ui->change->setEnabled(false);
    }
}

void MainWindow::on_old_password_textChanged()
{
    if (ui->login_change->text() != "" && ui->new_password->text() != "" && ui->old_password->text() != "") {
        ui->change->setEnabled(true);
    }
    else {
        ui->change->setEnabled(false);
    }
}

void MainWindow::on_new_password_textChanged()
{
    if (ui->login_change->text() != "" && ui->new_password->text() != "" && ui->old_password->text() != "") {
        ui->change->setEnabled(true);
    }
    else {
        ui->change->setEnabled(false);
    }
}

void MainWindow::on_login_del_textChanged() //Активация кнопки удаления аккаунта сотрудника
{
    if (ui->login_del->text() != "") {
        ui->deleteAcc->setEnabled(true);
    }
    else {
        ui->deleteAcc->setEnabled(false);
    }
}

void MainWindow::on_see_clicked()
{
    if(ui->password->echoMode() == QLineEdit::Password) {
        ui->password->setEchoMode(QLineEdit::Normal);
        ui->see->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/open.png);" "}");
    }
    else {
        ui->password->setEchoMode(QLineEdit::Password);
        ui->see->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    }
}

void MainWindow::on_see_2_clicked()
{
    if(ui->password_add->echoMode() == QLineEdit::Password) {
        ui->password_add->setEchoMode(QLineEdit::Normal);
        ui->see_2->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/open.png);" "}");
    }
    else {
        ui->password_add->setEchoMode(QLineEdit::Password);
        ui->see_2->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    }
}

void MainWindow::on_see_3_clicked()
{
    if(ui->old_password->echoMode() == QLineEdit::Password) {
        ui->old_password->setEchoMode(QLineEdit::Normal);
        ui->see_3->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/open.png);" "}");
    }
    else {
        ui->old_password->setEchoMode(QLineEdit::Password);
        ui->see_3->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    }
}

void MainWindow::on_see_4_clicked()
{
    if(ui->new_password->echoMode() == QLineEdit::Password) {
        ui->new_password->setEchoMode(QLineEdit::Normal);
        ui->see_4->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/open.png);" "}");
    }
    else {
        ui->new_password->setEchoMode(QLineEdit::Password);
        ui->see_4->setStyleSheet("QPushButton {" "border: none;" "image: url(:/res/image/close.png);" "}");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
