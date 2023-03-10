QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    customer.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_page0.cpp \
    mainwindow_page1.cpp \
    mainwindow_page2.cpp \
    mainwindow_page3.cpp \
    mainwindow_page4.cpp \
    mainwindow_page5.cpp \
    mainwindow_page6.cpp

HEADERS += \
    admin.h \
    customer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
