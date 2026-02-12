QT       += core gui
QT       += core gui sql
QT       += network
RESOURCES+= resources.qrc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GameClient.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    othello_window.cpp \
    player.cpp

HEADERS += \
    GameClient.h \
    GameOptions.h \
    loginwindow.h \
    mainwindow.h \
    othello_window.h \
    player.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui

# for Email validation

INCLUDEPATH += $$PWD/smtp/src
SOURCES += $$files($$PWD/smtp/src/*.cpp)
HEADERS += $$files($$PWD/smtp/src/*.h) \
           $$PWD/smtp/src/SmtpMime

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
