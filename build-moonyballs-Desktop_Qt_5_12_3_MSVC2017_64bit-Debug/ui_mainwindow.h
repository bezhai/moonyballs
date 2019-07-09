/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionExit;
    QAction *ActionAbout;
    QWidget *centralWidget;
    QLabel *Ball;
    QPushButton *StartGame;
    QPushButton *Sound;
    QPushButton *About;
    QPushButton *ResumeGame;
    QPushButton *Exit;
    QPushButton *Rank;
    QPushButton *Guide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(false);
        MainWindow->resize(1280, 720);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bgr);"));
        ActionExit = new QAction(MainWindow);
        ActionExit->setObjectName(QString::fromUtf8("ActionExit"));
        ActionAbout = new QAction(MainWindow);
        ActionAbout->setObjectName(QString::fromUtf8("ActionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Ball = new QLabel(centralWidget);
        Ball->setObjectName(QString::fromUtf8("Ball"));
        Ball->setGeometry(QRect(1080, 230, 131, 121));
        Ball->setStyleSheet(QString::fromUtf8("image: url(:/pic/ball);\n"
"background: transparent"));
        StartGame = new QPushButton(centralWidget);
        StartGame->setObjectName(QString::fromUtf8("StartGame"));
        StartGame->setGeometry(QRect(460, 460, 301, 71));
        StartGame->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/startbtn);\n"
"background: transparent"));
        Sound = new QPushButton(centralWidget);
        Sound->setObjectName(QString::fromUtf8("Sound"));
        Sound->setGeometry(QRect(0, 0, 71, 71));
        Sound->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/sdbtn);\n"
"background: transparent"));
        About = new QPushButton(centralWidget);
        About->setObjectName(QString::fromUtf8("About"));
        About->setGeometry(QRect(1210, 0, 71, 71));
        About->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/abt);\n"
"background: transparent"));
        ResumeGame = new QPushButton(centralWidget);
        ResumeGame->setObjectName(QString::fromUtf8("ResumeGame"));
        ResumeGame->setGeometry(QRect(460, 540, 301, 71));
        ResumeGame->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/rsmbtn);\n"
"background: transparent"));
        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(460, 620, 301, 71));
        QPalette palette;
        QBrush brush(QColor(4, 44, 115, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(4, 44, 115, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(4, 44, 115, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(4, 44, 115, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        Exit->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223_GB2312"));
        font.setPointSize(26);
        Exit->setFont(font);
        Exit->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent;\n"
"color: rgb(4, 44, 115);"));
        Rank = new QPushButton(centralWidget);
        Rank->setObjectName(QString::fromUtf8("Rank"));
        Rank->setGeometry(QRect(830, 630, 161, 61));
        Rank->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/lstbtn);\n"
"background: transparent"));
        Guide = new QPushButton(centralWidget);
        Guide->setObjectName(QString::fromUtf8("Guide"));
        Guide->setGeometry(QRect(1210, 70, 71, 71));
        Guide->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/gd);\n"
"background: transparent"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MoonyBalls", nullptr));
        ActionExit->setText(QApplication::translate("MainWindow", "\351\200\200\346\270\270", nullptr));
#ifndef QT_NO_TOOLTIP
        ActionExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\346\270\270", nullptr));
#endif // QT_NO_TOOLTIP
        ActionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        Ball->setText(QString());
        StartGame->setText(QString());
        Sound->setText(QString());
        About->setText(QString());
        ResumeGame->setText(QString());
        Exit->setText(QApplication::translate("MainWindow", "\351\200\200 \345\207\272 \346\270\270 \346\210\217", nullptr));
        Rank->setText(QString());
        Guide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
