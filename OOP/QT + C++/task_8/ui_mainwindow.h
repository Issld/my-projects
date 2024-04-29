/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Client;
    QPushButton *Car;
    QPushButton *Shop;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(439, 404);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Client = new QPushButton(centralwidget);
        Client->setObjectName("Client");
        Client->setGeometry(QRect(20, 30, 381, 91));
        QFont font;
        font.setPointSize(18);
        Client->setFont(font);
        Car = new QPushButton(centralwidget);
        Car->setObjectName("Car");
        Car->setGeometry(QRect(20, 150, 381, 91));
        Car->setFont(font);
        Shop = new QPushButton(centralwidget);
        Shop->setObjectName("Shop");
        Shop->setGeometry(QRect(20, 270, 381, 91));
        Shop->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Client->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\213", nullptr));
        Car->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\320\270", nullptr));
        Shop->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\263\320\260\320\267\320\270\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
