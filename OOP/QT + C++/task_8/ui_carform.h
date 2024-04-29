/********************************************************************************
** Form generated from reading UI file 'carform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARFORM_H
#define UI_CARFORM_H

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

class Ui_CarForm
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ModelInput;
    QPushButton *Delete;
    QPushButton *Return;
    QPushButton *Search;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *NumberInput;
    QPushButton *Add;

    void setupUi(QWidget *CarForm)
    {
        if (CarForm->objectName().isEmpty())
            CarForm->setObjectName("CarForm");
        CarForm->resize(800, 600);
        tableWidget = new QTableWidget(CarForm);
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
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 393, 800, 207));
        layoutWidget = new QWidget(CarForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 260, 598, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        ModelInput = new QLineEdit(layoutWidget);
        ModelInput->setObjectName("ModelInput");

        horizontalLayout_2->addWidget(ModelInput);

        Delete = new QPushButton(CarForm);
        Delete->setObjectName("Delete");
        Delete->setGeometry(QRect(280, 20, 240, 90));
        QFont font1;
        font1.setPointSize(12);
        Delete->setFont(font1);
        Return = new QPushButton(CarForm);
        Return->setObjectName("Return");
        Return->setGeometry(QRect(670, 350, 120, 30));
        Return->setFont(font);
        Search = new QPushButton(CarForm);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(550, 20, 240, 90));
        Search->setFont(font1);
        layoutWidget_2 = new QWidget(CarForm);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 150, 598, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        NumberInput = new QLineEdit(layoutWidget_2);
        NumberInput->setObjectName("NumberInput");

        horizontalLayout->addWidget(NumberInput);

        Add = new QPushButton(CarForm);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(10, 20, 240, 90));
        Add->setFont(font1);

        retranslateUi(CarForm);

        QMetaObject::connectSlotsByName(CarForm);
    } // setupUi

    void retranslateUi(QWidget *CarForm)
    {
        CarForm->setWindowTitle(QCoreApplication::translate("CarForm", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CarForm", "\342\204\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CarForm", "\320\234\320\260\321\200\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CarForm", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CarForm", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CarForm", "\320\232\320\276\321\200\320\276\320\261\320\272\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CarForm", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("CarForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\276\320\264\320\265\320\273\321\214 \320\270\321\201\320\272\320\276\320\274\320\276\320\263\320\276 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\217:     ", nullptr));
        Delete->setText(QCoreApplication::translate("CarForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        Return->setText(QCoreApplication::translate("CarForm", "Return", nullptr));
        Search->setText(QCoreApplication::translate("CarForm", "\320\235\320\260\320\271\321\202\320\270 \320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("CarForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\203\320\264\320\260\320\273\321\217\320\265\320\274\320\276\320\263\320\276 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\217:     ", nullptr));
        Add->setText(QCoreApplication::translate("CarForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarForm: public Ui_CarForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARFORM_H
