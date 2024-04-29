/********************************************************************************
** Form generated from reading UI file 'caraddform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARADDFORM_H
#define UI_CARADDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarAddForm
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *Label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *Model;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *Year;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QComboBox *Gearbox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *Power;
    QPushButton *pushButton;

    void setupUi(QWidget *CarAddForm)
    {
        if (CarAddForm->objectName().isEmpty())
            CarAddForm->setObjectName("CarAddForm");
        CarAddForm->resize(400, 480);
        layoutWidget = new QWidget(CarAddForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 331, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        Label = new QLineEdit(layoutWidget);
        Label->setObjectName("Label");

        horizontalLayout_6->addWidget(Label);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        Model = new QLineEdit(layoutWidget);
        Model->setObjectName("Model");

        horizontalLayout_7->addWidget(Model);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        Year = new QLineEdit(layoutWidget);
        Year->setObjectName("Year");

        horizontalLayout_8->addWidget(Year);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);

        Gearbox = new QComboBox(layoutWidget);
        Gearbox->addItem(QString());
        Gearbox->addItem(QString());
        Gearbox->addItem(QString());
        Gearbox->addItem(QString());
        Gearbox->setObjectName("Gearbox");

        horizontalLayout_9->addWidget(Gearbox);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_10->addWidget(label_10);

        Power = new QLineEdit(layoutWidget);
        Power->setObjectName("Power");

        horizontalLayout_10->addWidget(Power);


        verticalLayout_2->addLayout(horizontalLayout_10);

        pushButton = new QPushButton(CarAddForm);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 400, 331, 61));
        QFont font;
        font.setPointSize(18);
        pushButton->setFont(font);

        retranslateUi(CarAddForm);

        QMetaObject::connectSlotsByName(CarAddForm);
    } // setupUi

    void retranslateUi(QWidget *CarAddForm)
    {
        CarAddForm->setWindowTitle(QCoreApplication::translate("CarAddForm", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("CarAddForm", "\320\234\320\260\321\200\320\272\320\260:  ", nullptr));
        label_7->setText(QCoreApplication::translate("CarAddForm", "\320\234\320\276\320\264\320\265\320\273\321\214:  ", nullptr));
        label_8->setText(QCoreApplication::translate("CarAddForm", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260:  ", nullptr));
        label_9->setText(QCoreApplication::translate("CarAddForm", "\320\232\320\276\321\200\320\276\320\261\320\272\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\207:", nullptr));
        Gearbox->setItemText(0, QCoreApplication::translate("CarAddForm", "\320\234\320\265\321\205\320\260\320\275\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\272\320\276\321\200\320\276\320\261\320\272\320\260", nullptr));
        Gearbox->setItemText(1, QCoreApplication::translate("CarAddForm", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\272\320\276\321\200\320\276\320\261\320\272\320\260", nullptr));
        Gearbox->setItemText(2, QCoreApplication::translate("CarAddForm", "\320\222\320\260\321\200\320\270\320\260\321\202\320\276\321\200", nullptr));
        Gearbox->setItemText(3, QCoreApplication::translate("CarAddForm", "\320\240\320\276\320\261\320\276\321\202\320\270\320\267\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\272\320\276\321\200\320\276\320\261\320\272\320\260", nullptr));

        label_10->setText(QCoreApplication::translate("CarAddForm", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\264\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\217:  ", nullptr));
        pushButton->setText(QCoreApplication::translate("CarAddForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarAddForm: public Ui_CarAddForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARADDFORM_H
