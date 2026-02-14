/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_15;
    QTabWidget *tabWidget;
    QWidget *LoginTab;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *userNameLableLogin;
    QLineEdit *userNameLineEditLogin;
    QHBoxLayout *horizontalLayout_8;
    QLabel *passwordLableLogin;
    QLineEdit *passwordLineEditLogin;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Forgot_pass_btn;
    QWidget *SignUpTab;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLabel;
    QLineEdit *nameLineEditSignup;
    QHBoxLayout *horizontalLayout_5;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEditSignup;
    QHBoxLayout *horizontalLayout_3;
    QLabel *phoneNumberLabel;
    QLineEdit *PhoneNumberLineEditSignup;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLabel;
    QLineEdit *emailLineEditSignup;
    QHBoxLayout *horizontalLayout;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEditSignup;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QPushButton *signupButton;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *Validation_label;
    QLineEdit *Validation_line;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Validation_btn;
    QSpacerItem *verticalSpacer;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *backToLoginButton;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *username_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *username_line;
    QHBoxLayout *horizontalLayout_17;
    QLabel *email_label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *email_line;
    QHBoxLayout *horizontalLayout_18;
    QLabel *New_pass_label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *New_pass_line;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *Recover_btn;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_19;
    QLabel *Forgot_code_label;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *Forgot_code_line;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Change_pass_btn;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(900, 500);
        LoginWindow->setMinimumSize(QSize(400, 450));
        LoginWindow->setMaximumSize(QSize(900, 500));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_15 = new QHBoxLayout(centralwidget);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        LoginTab = new QWidget();
        LoginTab->setObjectName("LoginTab");
        horizontalLayout_10 = new QHBoxLayout(LoginTab);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, -1, 100, -1);
        userNameLableLogin = new QLabel(LoginTab);
        userNameLableLogin->setObjectName("userNameLableLogin");

        horizontalLayout_7->addWidget(userNameLableLogin);

        userNameLineEditLogin = new QLineEdit(LoginTab);
        userNameLineEditLogin->setObjectName("userNameLineEditLogin");

        horizontalLayout_7->addWidget(userNameLineEditLogin);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(-1, -1, 30, -1);
        passwordLableLogin = new QLabel(LoginTab);
        passwordLableLogin->setObjectName("passwordLableLogin");

        horizontalLayout_8->addWidget(passwordLableLogin);

        passwordLineEditLogin = new QLineEdit(LoginTab);
        passwordLineEditLogin->setObjectName("passwordLineEditLogin");

        horizontalLayout_8->addWidget(passwordLineEditLogin);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_7->addLayout(verticalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(-1, -1, 14, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        loginButton = new QPushButton(LoginTab);
        loginButton->setObjectName("loginButton");

        verticalLayout_6->addWidget(loginButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout_9->addLayout(verticalLayout_6);

        Forgot_pass_btn = new QPushButton(LoginTab);
        Forgot_pass_btn->setObjectName("Forgot_pass_btn");

        horizontalLayout_9->addWidget(Forgot_pass_btn);


        verticalLayout_7->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_7);

        tabWidget->addTab(LoginTab, QString());
        SignUpTab = new QWidget();
        SignUpTab->setObjectName("SignUpTab");
        horizontalLayout_11 = new QHBoxLayout(SignUpTab);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 200, -1);
        nameLabel = new QLabel(SignUpTab);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout_4->addWidget(nameLabel);

        nameLineEditSignup = new QLineEdit(SignUpTab);
        nameLineEditSignup->setObjectName("nameLineEditSignup");

        horizontalLayout_4->addWidget(nameLineEditSignup);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, -1, 130, -1);
        userNameLabel = new QLabel(SignUpTab);
        userNameLabel->setObjectName("userNameLabel");

        horizontalLayout_5->addWidget(userNameLabel);

        userNameLineEditSignup = new QLineEdit(SignUpTab);
        userNameLineEditSignup->setObjectName("userNameLineEditSignup");

        horizontalLayout_5->addWidget(userNameLineEditSignup);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, 30, -1);
        phoneNumberLabel = new QLabel(SignUpTab);
        phoneNumberLabel->setObjectName("phoneNumberLabel");

        horizontalLayout_3->addWidget(phoneNumberLabel);

        PhoneNumberLineEditSignup = new QLineEdit(SignUpTab);
        PhoneNumberLineEditSignup->setObjectName("PhoneNumberLineEditSignup");

        horizontalLayout_3->addWidget(PhoneNumberLineEditSignup);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        emailLabel = new QLabel(SignUpTab);
        emailLabel->setObjectName("emailLabel");

        horizontalLayout_2->addWidget(emailLabel);

        emailLineEditSignup = new QLineEdit(SignUpTab);
        emailLineEditSignup->setObjectName("emailLineEditSignup");

        horizontalLayout_2->addWidget(emailLineEditSignup);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, 100, -1);
        passwordLabel = new QLabel(SignUpTab);
        passwordLabel->setObjectName("passwordLabel");

        horizontalLayout->addWidget(passwordLabel);

        passwordLineEditSignup = new QLineEdit(SignUpTab);
        passwordLineEditSignup->setObjectName("passwordLineEditSignup");

        horizontalLayout->addWidget(passwordLineEditSignup);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_9->addLayout(verticalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, -1, 14, -1);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        signupButton = new QPushButton(SignUpTab);
        signupButton->setObjectName("signupButton");

        horizontalLayout_14->addWidget(signupButton);


        verticalLayout_5->addLayout(horizontalLayout_14);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        Validation_label = new QLabel(SignUpTab);
        Validation_label->setObjectName("Validation_label");
        Validation_label->setEnabled(true);

        horizontalLayout_12->addWidget(Validation_label);

        Validation_line = new QLineEdit(SignUpTab);
        Validation_line->setObjectName("Validation_line");
        Validation_line->setEnabled(true);

        horizontalLayout_12->addWidget(Validation_line);


        verticalLayout_8->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        Validation_btn = new QPushButton(SignUpTab);
        Validation_btn->setObjectName("Validation_btn");

        horizontalLayout_13->addWidget(Validation_btn);


        verticalLayout_8->addLayout(horizontalLayout_13);


        verticalLayout_5->addLayout(verticalLayout_8);

        verticalSpacer = new QSpacerItem(20, 107, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_9->addLayout(horizontalLayout_6);


        horizontalLayout_11->addLayout(verticalLayout_9);

        tabWidget->addTab(SignUpTab, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_23 = new QHBoxLayout(tab);
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_10);

        backToLoginButton = new QPushButton(tab);
        backToLoginButton->setObjectName("backToLoginButton");

        horizontalLayout_22->addWidget(backToLoginButton);


        verticalLayout_14->addLayout(horizontalLayout_22);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        username_label = new QLabel(tab);
        username_label->setObjectName("username_label");

        horizontalLayout_16->addWidget(username_label);

        horizontalSpacer_4 = new QSpacerItem(25, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_4);

        username_line = new QLineEdit(tab);
        username_line->setObjectName("username_line");

        horizontalLayout_16->addWidget(username_line);


        verticalLayout_11->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        email_label = new QLabel(tab);
        email_label->setObjectName("email_label");

        horizontalLayout_17->addWidget(email_label);

        horizontalSpacer_5 = new QSpacerItem(58, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_5);

        email_line = new QLineEdit(tab);
        email_line->setObjectName("email_line");

        horizontalLayout_17->addWidget(email_line);


        verticalLayout_11->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        New_pass_label = new QLabel(tab);
        New_pass_label->setObjectName("New_pass_label");
        New_pass_label->setMargin(0);

        horizontalLayout_18->addWidget(New_pass_label);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_6);

        New_pass_line = new QLineEdit(tab);
        New_pass_line->setObjectName("New_pass_line");
        New_pass_line->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_18->addWidget(New_pass_line);


        verticalLayout_11->addLayout(horizontalLayout_18);


        verticalLayout_12->addLayout(verticalLayout_11);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_9);

        Recover_btn = new QPushButton(tab);
        Recover_btn->setObjectName("Recover_btn");

        horizontalLayout_21->addWidget(Recover_btn);


        verticalLayout_12->addLayout(horizontalLayout_21);


        verticalLayout_13->addLayout(verticalLayout_12);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_5);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        Forgot_code_label = new QLabel(tab);
        Forgot_code_label->setObjectName("Forgot_code_label");

        horizontalLayout_19->addWidget(Forgot_code_label);

        horizontalSpacer_7 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_7);

        Forgot_code_line = new QLineEdit(tab);
        Forgot_code_line->setObjectName("Forgot_code_line");

        horizontalLayout_19->addWidget(Forgot_code_line);


        verticalLayout_10->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_8);

        Change_pass_btn = new QPushButton(tab);
        Change_pass_btn->setObjectName("Change_pass_btn");

        horizontalLayout_20->addWidget(Change_pass_btn);


        verticalLayout_10->addLayout(horizontalLayout_20);


        verticalLayout_13->addLayout(verticalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_4);


        verticalLayout_14->addLayout(verticalLayout_13);


        horizontalLayout_23->addLayout(verticalLayout_14);

        tabWidget->addTab(tab, QString());

        horizontalLayout_15->addWidget(tabWidget);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 25));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        tabWidget->setCurrentIndex(0);
        loginButton->setDefault(true);
        signupButton->setDefault(true);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        userNameLableLogin->setText(QCoreApplication::translate("LoginWindow", "UserName", nullptr));
        passwordLableLogin->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        Forgot_pass_btn->setText(QCoreApplication::translate("LoginWindow", "Forgot Password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(LoginTab), QCoreApplication::translate("LoginWindow", "Login", nullptr));
        nameLabel->setText(QCoreApplication::translate("LoginWindow", "Name", nullptr));
        userNameLabel->setText(QCoreApplication::translate("LoginWindow", "User Name", nullptr));
        phoneNumberLabel->setText(QCoreApplication::translate("LoginWindow", "Phone Number", nullptr));
        emailLabel->setText(QCoreApplication::translate("LoginWindow", "Email", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginWindow", "Sign Up", nullptr));
        Validation_label->setText(QCoreApplication::translate("LoginWindow", "Validation Code : ", nullptr));
        Validation_btn->setText(QCoreApplication::translate("LoginWindow", "finish", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SignUpTab), QCoreApplication::translate("LoginWindow", "Sign up", nullptr));
        backToLoginButton->setText(QCoreApplication::translate("LoginWindow", "Back To Login", nullptr));
        username_label->setText(QCoreApplication::translate("LoginWindow", "Username : ", nullptr));
        email_label->setText(QCoreApplication::translate("LoginWindow", "Email :", nullptr));
        New_pass_label->setText(QCoreApplication::translate("LoginWindow", "New Password :", nullptr));
        Recover_btn->setText(QCoreApplication::translate("LoginWindow", "Recover Password", nullptr));
        Forgot_code_label->setText(QCoreApplication::translate("LoginWindow", "Validation Code :", nullptr));
        Change_pass_btn->setText(QCoreApplication::translate("LoginWindow", "Change Password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
