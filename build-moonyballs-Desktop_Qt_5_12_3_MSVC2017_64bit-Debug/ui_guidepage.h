/********************************************************************************
** Form generated from reading UI file 'guidepage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDEPAGE_H
#define UI_GUIDEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guidepage
{
public:
    QPushButton *Back;

    void setupUi(QWidget *guidepage)
    {
        if (guidepage->objectName().isEmpty())
            guidepage->setObjectName(QString::fromUtf8("guidepage"));
        guidepage->resize(1280, 720);
        guidepage->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/gdpg);"));
        Back = new QPushButton(guidepage);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 93, 91));
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/back);\n"
"background: transparent"));

        retranslateUi(guidepage);

        QMetaObject::connectSlotsByName(guidepage);
    } // setupUi

    void retranslateUi(QWidget *guidepage)
    {
        guidepage->setWindowTitle(QApplication::translate("guidepage", "Guide Page", nullptr));
        Back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class guidepage: public Ui_guidepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDEPAGE_H
