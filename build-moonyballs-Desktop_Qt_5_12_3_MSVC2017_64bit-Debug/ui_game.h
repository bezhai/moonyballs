/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QPushButton *TestFailure;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *Coin;
    QLabel *Score;
    QLabel *BigNum;
    QLabel *SmallNum;
    QPushButton *pause;
    QPushButton *pushButton_5;
    QPushButton *Buy;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1280, 780);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TestFailure = new QPushButton(centralwidget);
        TestFailure->setObjectName(QString::fromUtf8("TestFailure"));
        TestFailure->setGeometry(QRect(710, 730, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 80, 72, 72));
        pushButton->setStyleSheet(QString::fromUtf8("background: transparent"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/shtr"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(72, 72));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 100, 201, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 300, 591, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(680, 210, 411, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 660, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(820, 660, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(940, 670, 93, 28));
        Coin = new QLabel(centralwidget);
        Coin->setObjectName(QString::fromUtf8("Coin"));
        Coin->setGeometry(QRect(100, 70, 71, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        Coin->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        Coin->setFont(font);
        Score = new QLabel(centralwidget);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(100, 100, 71, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        Score->setPalette(palette1);
        Score->setFont(font);
        BigNum = new QLabel(centralwidget);
        BigNum->setObjectName(QString::fromUtf8("BigNum"));
        BigNum->setGeometry(QRect(520, 100, 31, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        BigNum->setPalette(palette2);
        BigNum->setFont(font);
        SmallNum = new QLabel(centralwidget);
        SmallNum->setObjectName(QString::fromUtf8("SmallNum"));
        SmallNum->setGeometry(QRect(520, 70, 31, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        SmallNum->setPalette(palette3);
        SmallNum->setFont(font);
        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(1200, 0, 71, 71));
        pause->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/pause);\n"
"background: transparent;"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(860, 720, 93, 28));
        Buy = new QPushButton(centralwidget);
        Buy->setObjectName(QString::fromUtf8("Buy"));
        Buy->setGeometry(QRect(700, 470, 93, 28));
        Game->setCentralWidget(centralwidget);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Game", nullptr));
        TestFailure->setText(QApplication::translate("Game", "Fail", nullptr));
        pushButton->setText(QString());
        label->setText(QApplication::translate("Game", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("Game", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("Game", "TextLabel", nullptr));
        pushButton_2->setText(QApplication::translate("Game", "newball", nullptr));
        pushButton_3->setText(QApplication::translate("Game", "newbar", nullptr));
        pushButton_4->setText(QApplication::translate("Game", "newprop", nullptr));
        Coin->setText(QApplication::translate("Game", "0", nullptr));
        Score->setText(QApplication::translate("Game", "0", nullptr));
        BigNum->setText(QApplication::translate("Game", "0", nullptr));
        SmallNum->setText(QApplication::translate("Game", "0", nullptr));
        pause->setText(QString());
        pushButton_5->setText(QApplication::translate("Game", "UpTest", nullptr));
        Buy->setText(QApplication::translate("Game", "Buyball", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
