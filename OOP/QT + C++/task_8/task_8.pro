QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculation.cpp \
    calculationfacade.cpp \
    caraddform.cpp \
    carform.cpp \
    carlist.cpp \
    carobject.cpp \
    client.cpp \
    clientaddform.cpp \
    clientlist.cpp \
    clientobject.cpp \
    main.cpp \
    mainwindow.cpp \
    shop.cpp \
    shopaddform.cpp \
    shoplist.cpp \
    shopobject.cpp

HEADERS += \
    calculation.h \
    calculationfacade.h \
    caraddform.h \
    carform.h \
    carlist.h \
    carobject.h \
    client.h \
    clientaddform.h \
    clientlist.h \
    clientobject.h \
    mainwindow.h \
    shop.h \
    shopaddform.h \
    shoplist.h \
    shopobject.h

FORMS += \
    caraddform.ui \
    carform.ui \
    client.ui \
    clientaddform.ui \
    mainwindow.ui \
    shop.ui \
    shopaddform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
