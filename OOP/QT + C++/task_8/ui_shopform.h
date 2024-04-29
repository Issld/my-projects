/********************************************************************************
** Form generated from reading UI file 'shopform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPFORM_H
#define UI_SHOPFORM_H

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

class Ui_ShopForm
{
public:
    QTableWidget *tableWidget;
    QPushButton *Return;
    QPushButton *Add;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *SurnameInput_2;
    QPushButton *Delete;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *NumberInput_2;
    QPushButton *Search;

    void setupUi(QWidget *ShopForm)
    {
        if (ShopForm->objectName().isEmpty())
            ShopForm->setObjectName("ShopForm");
        ShopForm->resize(800, 600);
        tableWidget = new QTableWidget(ShopForm);
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
        Return = new QPushButton(ShopForm);
        Return->setObjectName("Return");
        Return->setGeometry(QRect(670, 350, 120, 30));
        QFont font;
        font.setPointSize(14);
        Return->setFont(font);
        Add = new QPushButton(ShopForm);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(10, 20, 240, 90));
        QFont font1;
        font1.setPointSize(12);
        Add->setFont(font1);
        layoutWidget = new QWidget(ShopForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 260, 598, 81));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        SurnameInput_2 = new QLineEdit(layoutWidget);
        SurnameInput_2->setObjectName("SurnameInput_2");

        horizontalLayout_3->addWidget(SurnameInput_2);

        Delete = new QPushButton(ShopForm);
        Delete->setObjectName("Delete");
        Delete->setGeometry(QRect(280, 20, 240, 90));
        Delete->setFont(font1);
        layoutWidget_2 = new QWidget(ShopForm);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 150, 598, 81));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        NumberInput_2 = new QLineEdit(layoutWidget_2);
        NumberInput_2->setObjectName("NumberInput_2");

        horizontalLayout_4->addWidget(NumberInput_2);

        Search = new QPushButton(ShopForm);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(550, 20, 240, 90));
        Search->setFont(font1);

        retranslateUi(ShopForm);

        QMetaObject::connectSlotsByName(ShopForm);
    } // setupUi

    void retranslateUi(QWidget *ShopForm)
    {
        ShopForm->setWindowTitle(QCoreApplication::translate("ShopForm", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ShopForm", "\342\204\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ShopForm", "\320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ShopForm", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ShopForm", "\320\224\320\260\321\202\320\260 \320\277\320\276\320\272\321\203\320\277\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ShopForm", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ShopForm", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        Return->setText(QCoreApplication::translate("ShopForm", "Return", nullptr));
        Add->setText(QCoreApplication::translate("ShopForm", "\320\232\321\203\320\277\320\270\321\202\321\214 \320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("ShopForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\260\320\274\320\270\320\273\320\270\321\216 \320\270\321\201\320\272\320\276\320\274\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:     ", nullptr));
        Delete->setText(QCoreApplication::translate("ShopForm", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("ShopForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\260\320\265\320\274\320\276\320\263\320\276 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\217:     ", nullptr));
        Search->setText(QCoreApplication::translate("ShopForm", "\320\235\320\260\320\271\321\202\320\270 \320\237\320\276\320\272\321\203\320\277\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopForm: public Ui_ShopForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPFORM_H
