/********************************************************************************
** Form generated from reading UI file 'difficulty_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTY_CHOOSE_H
#define UI_DIFFICULTY_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_difficulty_choose
{
public:
    QPushButton *Back;
    QPushButton *Easy;
    QPushButton *Medium;
    QPushButton *Hard;
    QLabel *label;

    void setupUi(QWidget *difficulty_choose)
    {
        if (difficulty_choose->objectName().isEmpty())
            difficulty_choose->setObjectName(QString::fromUtf8("difficulty_choose"));
        difficulty_choose->resize(1280, 720);
        difficulty_choose->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/dfbgr);"));
        Back = new QPushButton(difficulty_choose);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 93, 91));
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/back);\n"
"background: transparent"));
        Easy = new QPushButton(difficulty_choose);
        Easy->setObjectName(QString::fromUtf8("Easy"));
        Easy->setEnabled(true);
        Easy->setGeometry(QRect(830, 210, 361, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(21);
        Easy->setFont(font);
        Easy->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent"));
        Medium = new QPushButton(difficulty_choose);
        Medium->setObjectName(QString::fromUtf8("Medium"));
        Medium->setEnabled(true);
        Medium->setGeometry(QRect(830, 350, 361, 71));
        Medium->setFont(font);
        Medium->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent"));
        Hard = new QPushButton(difficulty_choose);
        Hard->setObjectName(QString::fromUtf8("Hard"));
        Hard->setEnabled(true);
        Hard->setGeometry(QRect(830, 480, 361, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(22);
        Hard->setFont(font1);
        Hard->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent"));
        label = new QLabel(difficulty_choose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 0, 361, 121));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DFPNewChuan-B5"));
        font2.setPointSize(52);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("background: transparent"));

        retranslateUi(difficulty_choose);

        QMetaObject::connectSlotsByName(difficulty_choose);
    } // setupUi

    void retranslateUi(QWidget *difficulty_choose)
    {
        difficulty_choose->setWindowTitle(QApplication::translate("difficulty_choose", "DifficultyChoose", nullptr));
        Back->setText(QString());
        Easy->setText(QApplication::translate("difficulty_choose", "\347\256\200            \345\215\225", nullptr));
        Medium->setText(QApplication::translate("difficulty_choose", "\344\270\255            \347\255\211", nullptr));
        Hard->setText(QApplication::translate("difficulty_choose", "\345\233\260          \351\232\276", nullptr));
        label->setText(QApplication::translate("difficulty_choose", "\351\201\270\346\223\207\351\233\243\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class difficulty_choose: public Ui_difficulty_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTY_CHOOSE_H
