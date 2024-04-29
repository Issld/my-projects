#include "viewform.h"
#include "ui_viewform.h"

viewForm::viewForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewForm)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
}

viewForm::~viewForm()
{
    delete ui;
}

void viewForm::setText(QJsonArray jsonArr)
{
    for (int i = 0; i < jsonArr.size(); i ++){
        ui->label->setText(ui->label->text() + "\n" + jsonArr[i].toObject().value("text").toString());
    }
}

void viewForm::on_pushButton_clicked()
{
    ui->label->setText("");
    this->close();
}

void viewForm::closeEvent(QCloseEvent *event)
{
    ui->label->setText("");
    event->accept();
}
