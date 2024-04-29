/********************************************************************************
** Form generated from reading UI file 'clientaddform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTADDFORM_H
#define UI_CLIENTADDFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientAddForm
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Surname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Secname;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *Phone;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *Mail;
    QPushButton *pushButton;

    void setupUi(QWidget *ClientAddForm)
    {
        if (ClientAddForm->objectName().isEmpty())
            ClientAddForm->setObjectName("ClientAddForm");
        ClientAddForm->resize(400, 480);
        layoutWidget = new QWidget(ClientAddForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 331, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        Surname = new QLineEdit(layoutWidget);
        Surname->setObjectName("Surname");

        horizontalLayout->addWidget(Surname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        Name = new QLineEdit(layoutWidget);
        Name->setObjectName("Name");

        horizontalLayout_2->addWidget(Name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        Secname = new QLineEdit(layoutWidget);
        Secname->setObjectName("Secname");

        horizontalLayout_3->addWidget(Secname);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        Phone = new QLineEdit(layoutWidget);
        Phone->setObjectName("Phone");

        horizontalLayout_4->addWidget(Phone);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        Mail = new QLineEdit(layoutWidget);
        Mail->setObjectName("Mail");

        horizontalLayout_5->addWidget(Mail);


        verticalLayout->addLayout(horizontalLayout_5);

        pushButton = new QPushButton(ClientAddForm);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 400, 331, 61));
        QFont font;
        font.setPointSize(18);
        pushButton->setFont(font);

        retranslateUi(ClientAddForm);

        QMetaObject::connectSlotsByName(ClientAddForm);
    } // setupUi

    void retranslateUi(QWidget *ClientAddForm)
    {
        ClientAddForm->setWindowTitle(QCoreApplication::translate("ClientAddForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("ClientAddForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ClientAddForm", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("ClientAddForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("ClientAddForm", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_5->setText(QCoreApplication::translate("ClientAddForm", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientAddForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientAddForm: public Ui_ClientAddForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTADDFORM_H
