/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Login;
    QPushButton *Register;
    QPushButton *GuestLogin;
    QPushButton *Exit;
    QLabel *label;
    QLineEdit *Acct;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(467, 143);
        horizontalLayoutWidget = new QWidget(login);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 90, 461, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Login = new QPushButton(horizontalLayoutWidget);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setEnabled(true);

        horizontalLayout->addWidget(Login);

        Register = new QPushButton(horizontalLayoutWidget);
        Register->setObjectName(QString::fromUtf8("Register"));

        horizontalLayout->addWidget(Register);

        GuestLogin = new QPushButton(horizontalLayoutWidget);
        GuestLogin->setObjectName(QString::fromUtf8("GuestLogin"));

        horizontalLayout->addWidget(GuestLogin);

        Exit = new QPushButton(horizontalLayoutWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));

        horizontalLayout->addWidget(Exit);

        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 51, 16));
        Acct = new QLineEdit(login);
        Acct->setObjectName(QString::fromUtf8("Acct"));
        Acct->setGeometry(QRect(60, 30, 361, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(17);
        Acct->setFont(font);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "\346\254\242\350\277\216", nullptr));
        Login->setText(QApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        Register->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        GuestLogin->setText(QApplication::translate("login", "\346\270\270\345\256\242\347\231\273\351\231\206", nullptr));
        Exit->setText(QApplication::translate("login", "\351\200\200\345\207\272", nullptr));
        label->setText(QApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
