/********************************************************************************
** Form generated from reading UI file 'saves.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVES_H
#define UI_SAVES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saves
{
public:
    QPushButton *Back;
    QLabel *label;
    QPushButton *Slot_2;
    QPushButton *Slot_3;
    QPushButton *Slot_4;
    QPushButton *Slot_1;

    void setupUi(QWidget *saves)
    {
        if (saves->objectName().isEmpty())
            saves->setObjectName(QString::fromUtf8("saves"));
        saves->resize(1280, 720);
        saves->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/savesbgr);"));
        Back = new QPushButton(saves);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 93, 91));
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/back);\n"
"background: transparent"));
        label = new QLabel(saves);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 0, 361, 121));
        QFont font;
        font.setFamily(QString::fromUtf8("DFPNewChuan-B5"));
        font.setPointSize(52);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background: transparent"));
        Slot_2 = new QPushButton(saves);
        Slot_2->setObjectName(QString::fromUtf8("Slot_2"));
        Slot_2->setEnabled(false);
        Slot_2->setGeometry(QRect(770, 280, 361, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(21);
        Slot_2->setFont(font1);
        Slot_2->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/unbtn);\n"
"background: transparent"));
        Slot_3 = new QPushButton(saves);
        Slot_3->setObjectName(QString::fromUtf8("Slot_3"));
        Slot_3->setEnabled(false);
        Slot_3->setGeometry(QRect(770, 410, 361, 71));
        Slot_3->setFont(font1);
        Slot_3->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/unbtn);\n"
"background: transparent"));
        Slot_4 = new QPushButton(saves);
        Slot_4->setObjectName(QString::fromUtf8("Slot_4"));
        Slot_4->setEnabled(false);
        Slot_4->setGeometry(QRect(770, 530, 361, 71));
        Slot_4->setFont(font1);
        Slot_4->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/unbtn);\n"
"background: transparent"));
        Slot_1 = new QPushButton(saves);
        Slot_1->setObjectName(QString::fromUtf8("Slot_1"));
        Slot_1->setEnabled(false);
        Slot_1->setGeometry(QRect(770, 150, 361, 71));
        Slot_1->setFont(font1);
        Slot_1->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/unbtn);\n"
"background: transparent"));

        retranslateUi(saves);

        QMetaObject::connectSlotsByName(saves);
    } // setupUi

    void retranslateUi(QWidget *saves)
    {
        saves->setWindowTitle(QApplication::translate("saves", "Saves", nullptr));
        Back->setText(QString());
        label->setText(QApplication::translate("saves", "\351\201\270\346\223\207\345\255\230\346\252\224", nullptr));
        Slot_2->setText(QApplication::translate("saves", "Empty Slot 2", nullptr));
        Slot_3->setText(QApplication::translate("saves", "Empty Slot 3", nullptr));
        Slot_4->setText(QApplication::translate("saves", "Empty Slot 4", nullptr));
        Slot_1->setText(QApplication::translate("saves", "Empty Slot 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saves: public Ui_saves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVES_H
