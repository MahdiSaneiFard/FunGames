/********************************************************************************
** Form generated from reading UI file 'connectfourwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTFOURWINDOW_H
#define UI_CONNECTFOURWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectFourWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConnectFourWindow)
    {
        if (ConnectFourWindow->objectName().isEmpty())
            ConnectFourWindow->setObjectName("ConnectFourWindow");
        ConnectFourWindow->resize(800, 600);
        centralwidget = new QWidget(ConnectFourWindow);
        centralwidget->setObjectName("centralwidget");
        ConnectFourWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConnectFourWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ConnectFourWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ConnectFourWindow);
        statusbar->setObjectName("statusbar");
        ConnectFourWindow->setStatusBar(statusbar);

        retranslateUi(ConnectFourWindow);

        QMetaObject::connectSlotsByName(ConnectFourWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConnectFourWindow)
    {
        ConnectFourWindow->setWindowTitle(QCoreApplication::translate("ConnectFourWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectFourWindow: public Ui_ConnectFourWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTFOURWINDOW_H
