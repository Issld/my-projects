QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apartmentcalc.cpp \
    apartmentcalcfactory.cpp \
    bstractcalc.cpp \
    calcfactory.cpp \
    calculationfacade.cpp \
    cottagecalc.cpp \
    cottagecalcfactory.cpp \
    estate.cpp \
    luxuriousapartmentcalc.cpp \
    luxuriousapartmentcalcfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    states.cpp \
    townhousecalc.cpp \
    townhousecalcfactory.cpp

HEADERS += \
    apartmentcalc.h \
    apartmentcalcfactory.h \
    bstractcalc.h \
    calcfactory.h \
    calculationfacade.h \
    cottagecalc.h \
    cottagecalcfactory.h \
    estate.h \
    luxuriousapartmentcalc.h \
    luxuriousapartmentcalcfactory.h \
    mainwindow.h \
    states.h \
    townhousecalc.h \
    townhousecalcfactory.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
