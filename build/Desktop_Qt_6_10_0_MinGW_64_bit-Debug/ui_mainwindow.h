/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_26;
    QSpacerItem *horizontalSpacer;
    QPushButton *ExitPushButton;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *guestLineEdit;
    QPushButton *ConnectToHostPushButton;
    QHBoxLayout *horizontalLayout_25;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Profile_name_label;
    QLineEdit *Profile_name_line;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Profile_username_label;
    QLineEdit *Profile_username_line;
    QHBoxLayout *horizontalLayout_10;
    QLabel *Profile_email_label;
    QLineEdit *Profile_Email_line;
    QHBoxLayout *horizontalLayout_11;
    QLabel *Profile_phone_label;
    QLineEdit *Profile_phone_line;
    QHBoxLayout *horizontalLayout_12;
    QLabel *Profile_pass_label;
    QLineEdit *Profile_pass_line;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *Change_btn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *Old_Pass_label;
    QLineEdit *Old_pass_line;
    QHBoxLayout *horizontalLayout_15;
    QLabel *email_code_label;
    QLineEdit *Code_email_line;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *Aply_btn;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_3;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QRadioButton *guestRadioButton;
    QRadioButton *HostRadioButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_24;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QLabel *ipLable;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label;
    QComboBox *gameModeComboBox;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_2;
    QSpinBox *timeSpinBox;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_3;
    QComboBox *colorComboBox;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *CreatePushButton;
    QLabel *label_4;
    QTableWidget *createdGamesTableWidget;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_28;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QTableWidget *activeMatchesTableWidget;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *JoinPushButton;
    QWidget *page_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1135, 811);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer);

        ExitPushButton = new QPushButton(centralwidget);
        ExitPushButton->setObjectName("ExitPushButton");

        horizontalLayout_26->addWidget(ExitPushButton);


        verticalLayout_8->addLayout(horizontalLayout_26);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        guestLineEdit = new QLineEdit(centralwidget);
        guestLineEdit->setObjectName("guestLineEdit");

        verticalLayout_6->addWidget(guestLineEdit);

        ConnectToHostPushButton = new QPushButton(centralwidget);
        ConnectToHostPushButton->setObjectName("ConnectToHostPushButton");

        verticalLayout_6->addWidget(ConnectToHostPushButton);


        verticalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::West);
        tabWidget->setTabShape(QTabWidget::TabShape::Triangular);
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        horizontalLayout_17 = new QHBoxLayout(tab_4);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Profile_name_label = new QLabel(tab_4);
        Profile_name_label->setObjectName("Profile_name_label");

        horizontalLayout_8->addWidget(Profile_name_label);

        Profile_name_line = new QLineEdit(tab_4);
        Profile_name_line->setObjectName("Profile_name_line");

        horizontalLayout_8->addWidget(Profile_name_line);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        Profile_username_label = new QLabel(tab_4);
        Profile_username_label->setObjectName("Profile_username_label");

        horizontalLayout_9->addWidget(Profile_username_label);

        Profile_username_line = new QLineEdit(tab_4);
        Profile_username_line->setObjectName("Profile_username_line");

        horizontalLayout_9->addWidget(Profile_username_line);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        Profile_email_label = new QLabel(tab_4);
        Profile_email_label->setObjectName("Profile_email_label");

        horizontalLayout_10->addWidget(Profile_email_label);

        Profile_Email_line = new QLineEdit(tab_4);
        Profile_Email_line->setObjectName("Profile_Email_line");

        horizontalLayout_10->addWidget(Profile_Email_line);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        Profile_phone_label = new QLabel(tab_4);
        Profile_phone_label->setObjectName("Profile_phone_label");

        horizontalLayout_11->addWidget(Profile_phone_label);

        Profile_phone_line = new QLineEdit(tab_4);
        Profile_phone_line->setObjectName("Profile_phone_line");

        horizontalLayout_11->addWidget(Profile_phone_line);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        Profile_pass_label = new QLabel(tab_4);
        Profile_pass_label->setObjectName("Profile_pass_label");

        horizontalLayout_12->addWidget(Profile_pass_label);

        Profile_pass_line = new QLineEdit(tab_4);
        Profile_pass_line->setObjectName("Profile_pass_line");
        Profile_pass_line->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_12->addWidget(Profile_pass_line);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);

        Change_btn = new QPushButton(tab_4);
        Change_btn->setObjectName("Change_btn");

        horizontalLayout_13->addWidget(Change_btn);


        verticalLayout_2->addLayout(horizontalLayout_13);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        Old_Pass_label = new QLabel(tab_4);
        Old_Pass_label->setObjectName("Old_Pass_label");

        horizontalLayout_14->addWidget(Old_Pass_label);

        Old_pass_line = new QLineEdit(tab_4);
        Old_pass_line->setObjectName("Old_pass_line");
        Old_pass_line->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_14->addWidget(Old_pass_line);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        email_code_label = new QLabel(tab_4);
        email_code_label->setObjectName("email_code_label");

        horizontalLayout_15->addWidget(email_code_label);

        Code_email_line = new QLineEdit(tab_4);
        Code_email_line->setObjectName("Code_email_line");

        horizontalLayout_15->addWidget(Code_email_line);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_6);

        Aply_btn = new QPushButton(tab_4);
        Aply_btn->setObjectName("Aply_btn");

        horizontalLayout_16->addWidget(Aply_btn);


        verticalLayout_3->addLayout(horizontalLayout_16);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_17->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget_3 = new QListWidget(tab);
        listWidget_3->setObjectName("listWidget_3");

        horizontalLayout_2->addWidget(listWidget_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_5 = new QHBoxLayout(tab_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        listWidget_2 = new QListWidget(tab_3);
        listWidget_2->setObjectName("listWidget_2");

        horizontalLayout_4->addWidget(listWidget_2);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        listWidget = new QListWidget(tab_2);
        listWidget->setObjectName("listWidget");

        horizontalLayout_6->addWidget(listWidget);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_25->addWidget(tabWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        guestRadioButton = new QRadioButton(centralwidget);
        guestRadioButton->setObjectName("guestRadioButton");
        guestRadioButton->setEnabled(false);
        guestRadioButton->setCheckable(true);
        guestRadioButton->setChecked(false);

        horizontalLayout->addWidget(guestRadioButton);

        HostRadioButton = new QRadioButton(centralwidget);
        HostRadioButton->setObjectName("HostRadioButton");
        HostRadioButton->setEnabled(false);

        horizontalLayout->addWidget(HostRadioButton);


        verticalLayout_7->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_24 = new QHBoxLayout(page);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        ipLable = new QLabel(groupBox);
        ipLable->setObjectName("ipLable");

        verticalLayout_5->addWidget(ipLable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout_20->addWidget(label);

        gameModeComboBox = new QComboBox(groupBox);
        gameModeComboBox->addItem(QString());
        gameModeComboBox->addItem(QString());
        gameModeComboBox->addItem(QString());
        gameModeComboBox->setObjectName("gameModeComboBox");

        horizontalLayout_20->addWidget(gameModeComboBox);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_19->addWidget(label_2);

        timeSpinBox = new QSpinBox(groupBox);
        timeSpinBox->setObjectName("timeSpinBox");
        timeSpinBox->setMinimum(1);
        timeSpinBox->setMaximum(5);

        horizontalLayout_19->addWidget(timeSpinBox);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_18->addWidget(label_3);

        colorComboBox = new QComboBox(groupBox);
        colorComboBox->addItem(QString());
        colorComboBox->addItem(QString());
        colorComboBox->setObjectName("colorComboBox");

        horizontalLayout_18->addWidget(colorComboBox);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_2);

        CreatePushButton = new QPushButton(groupBox);
        CreatePushButton->setObjectName("CreatePushButton");

        horizontalLayout_21->addWidget(CreatePushButton);


        verticalLayout->addLayout(horizontalLayout_21);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        createdGamesTableWidget = new QTableWidget(groupBox);
        createdGamesTableWidget->setObjectName("createdGamesTableWidget");

        verticalLayout->addWidget(createdGamesTableWidget);


        verticalLayout_5->addLayout(verticalLayout);


        horizontalLayout_24->addWidget(groupBox);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_28 = new QHBoxLayout(page_2);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");

        verticalLayout_9->addWidget(label_5);

        activeMatchesTableWidget = new QTableWidget(page_2);
        activeMatchesTableWidget->setObjectName("activeMatchesTableWidget");
        activeMatchesTableWidget->setEnabled(true);

        verticalLayout_9->addWidget(activeMatchesTableWidget);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_3);

        JoinPushButton = new QPushButton(page_2);
        JoinPushButton->setObjectName("JoinPushButton");
        JoinPushButton->setEnabled(true);

        horizontalLayout_22->addWidget(JoinPushButton);


        verticalLayout_9->addLayout(horizontalLayout_22);


        horizontalLayout_28->addLayout(verticalLayout_9);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);

        verticalLayout_7->addWidget(stackedWidget);


        horizontalLayout_25->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_25);


        gridLayout->addLayout(verticalLayout_8, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1135, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ExitPushButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        ConnectToHostPushButton->setText(QCoreApplication::translate("MainWindow", "Connect To Host", nullptr));
        Profile_name_label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        Profile_username_label->setText(QCoreApplication::translate("MainWindow", "UserName", nullptr));
        Profile_email_label->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        Profile_phone_label->setText(QCoreApplication::translate("MainWindow", "PhoneNumber", nullptr));
        Profile_pass_label->setText(QCoreApplication::translate("MainWindow", "New Password", nullptr));
        Change_btn->setText(QCoreApplication::translate("MainWindow", "Change Profile", nullptr));
        Old_Pass_label->setText(QCoreApplication::translate("MainWindow", "Old Password :", nullptr));
        email_code_label->setText(QCoreApplication::translate("MainWindow", "Code : ", nullptr));
        Aply_btn->setText(QCoreApplication::translate("MainWindow", "Aply changes", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Profile", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Othello", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Checkers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Connect Four", nullptr));
        guestRadioButton->setText(QCoreApplication::translate("MainWindow", "Guest", nullptr));
        HostRadioButton->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        ipLable->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Game Mode", nullptr));
        gameModeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "othello", nullptr));
        gameModeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "checkers", nullptr));
        gameModeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "connectFour", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Time(in min)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Begginer Color", nullptr));
        colorComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "white", nullptr));
        colorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "black", nullptr));

        CreatePushButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Created Games :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Active Matches :", nullptr));
        JoinPushButton->setText(QCoreApplication::translate("MainWindow", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
