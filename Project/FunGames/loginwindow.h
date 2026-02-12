#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    static QString hashPassword(const QString &password);
    void createAdminIfNotExists(const QString &username);

private slots:
    void on_loginButton_clicked();

    void on_signupButton_clicked();

    void on_Validation_btn_clicked();

    void on_Forgot_pass_btn_clicked();

    void on_Recover_btn_clicked();

    void on_Change_pass_btn_clicked();

    void on_backToLoginButton_clicked();

private:
    Ui::LoginWindow *ui;
    int generatedCode;
    void sendVerificationEmail(QString userEmail);
};

#endif // LOGINWINDOW_H۲
