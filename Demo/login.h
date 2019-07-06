#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_Exit_clicked();

    void on_GuestLogin_clicked();

    void on_Login_clicked();

    void on_Register_clicked();

signals:
    void sendAcct();

    void closeGame();

    void logged(QString acct);
private:
    Ui::login *ui;
};

#endif // LOGIN_H
