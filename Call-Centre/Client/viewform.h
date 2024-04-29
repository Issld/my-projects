#ifndef VIEWFORM_H
#define VIEWFORM_H

#include <QWidget>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QCloseEvent>

namespace Ui {
class viewForm;
}

class viewForm : public QWidget
{
    Q_OBJECT

public:
    explicit viewForm(QWidget *parent = nullptr);
    ~viewForm();

private slots:
    void setText(QJsonArray);
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::viewForm *ui;
};

#endif // VIEWFORM_H
