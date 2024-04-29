/********************************************************************************
** Form generated from reading UI file 'clientform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTFORM_H
#define UI_CLIENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientForm
{
public:
    QPushButton *Return;
    QPushButton *Add;
    QTableWidget *tableWidget;
    QPushButton *Delete;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *SurnameInput;
    QPushButton *Search;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *NumberInput;

    void setupUi(QWidget *ClientForm)
    {
        if (ClientForm->objectName().isEmpty())
            ClientForm->setObjectName("ClientForm");
        ClientForm->resize(800, 600);
        Return = new QPushButton(ClientForm);
        Return->setObjectName("Return");
        Return->setGeometry(QRect(670, 350, 120, 30));
        QFont font;
        font.setPointSize(14);
        Return->setFont(font);
        Add = new QPushButton(ClientForm);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(10, 20, 240, 90));
        QFont font1;
        font1.setPointSize(12);
        Add->setFont(font1);
        tableWidget = new QTableWidget(ClientForm);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 400, 800, 200));
        Delete = new QPushButton(ClientForm);
        Delete->setObjectName("Delete");
        Delete->setGeometry(QRect(280, 20, 240, 90));
        Delete->setFont(font1);
        layoutWidget = new QWidget(ClientForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 260, 598, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        SurnameInput = new QLineEdit(layoutWidget);
        SurnameInput->setObjectName("SurnameInput");

        horizontalLayout_2->addWidget(SurnameInput);

        Search = new QPushButton(ClientForm);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(550, 20, 240, 90));
        Search->setFont(font1);
        widget = new QWidget(ClientForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 150, 598, 81));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        NumberInput = new QLineEdit(widget);
        NumberInput->setObjectName("NumberInput");

        horizontalLayout->addWidget(NumberInput);


        retranslateUi(ClientForm);

        QMetaObject::connectSlotsByName(ClientForm);
    } // setupUi

    void retranslateUi(QWidget *ClientForm)
    {
        ClientForm->setWindowTitle(QCoreApplication::translate("ClientForm", "Form", nullptr));
        Return->setText(QCoreApplication::translate("ClientForm", "Return", nullptr));
        Add->setText(QCoreApplication::translate("ClientForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientForm", "\342\204\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ClientForm", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ClientForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ClientForm", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ClientForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ClientForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        Delete->setText(QCoreApplication::translate("ClientForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ClientForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\260\320\274\320\270\320\273\320\270\321\216 \320\270\321\201\320\272\320\276\320\274\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:     ", nullptr));
        Search->setText(QCoreApplication::translate("ClientForm", "\320\235\320\260\320\271\321\202\320\270 \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("ClientForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\203\320\264\320\260\320\273\321\217\320\265\320\274\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientForm: public Ui_ClientForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTFORM_H
