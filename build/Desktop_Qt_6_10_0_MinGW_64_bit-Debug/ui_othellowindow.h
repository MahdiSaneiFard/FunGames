/********************************************************************************
** Form generated from reading UI file 'othellowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHELLOWINDOW_H
#define UI_OTHELLOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OthelloWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *boardContainer;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *white_score;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OthelloWindow)
    {
        if (OthelloWindow->objectName().isEmpty())
            OthelloWindow->setObjectName("OthelloWindow");
        OthelloWindow->resize(800, 600);
        centralwidget = new QWidget(OthelloWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(70, 50, 661, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        boardContainer = new QFrame(gridLayoutWidget);
        boardContainer->setObjectName("boardContainer");
        boardContainer->setFrameShape(QFrame::Shape::StyledPanel);
        boardContainer->setFrameShadow(QFrame::Shadow::Raised);

        gridLayout->addWidget(boardContainer, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 10, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 10, 91, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 20, 49, 16));
        white_score = new QLabel(centralwidget);
        white_score->setObjectName("white_score");
        white_score->setGeometry(QRect(510, 20, 49, 16));
        OthelloWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(OthelloWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        OthelloWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(OthelloWindow);
        statusbar->setObjectName("statusbar");
        OthelloWindow->setStatusBar(statusbar);

        retranslateUi(OthelloWindow);

        QMetaObject::connectSlotsByName(OthelloWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OthelloWindow)
    {
        OthelloWindow->setWindowTitle(QCoreApplication::translate("OthelloWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("OthelloWindow", "black score", nullptr));
        label_2->setText(QCoreApplication::translate("OthelloWindow", "white score", nullptr));
        label_3->setText(QCoreApplication::translate("OthelloWindow", "2", nullptr));
        white_score->setText(QCoreApplication::translate("OthelloWindow", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OthelloWindow: public Ui_OthelloWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHELLOWINDOW_H
