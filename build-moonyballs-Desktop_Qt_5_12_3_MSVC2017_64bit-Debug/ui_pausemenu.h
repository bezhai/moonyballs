/********************************************************************************
** Form generated from reading UI file 'pausemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEMENU_H
#define UI_PAUSEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PauseMenu
{
public:
    QPushButton *Exit;
    QPushButton *Back;
    QLabel *label;

    void setupUi(QDialog *PauseMenu)
    {
        if (PauseMenu->objectName().isEmpty())
            PauseMenu->setObjectName(QString::fromUtf8("PauseMenu"));
        PauseMenu->resize(521, 521);
        Exit = new QPushButton(PauseMenu);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(110, 400, 301, 71));
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
        Back = new QPushButton(PauseMenu);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(110, 310, 301, 71));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(4, 44, 115, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush6(QColor(4, 44, 115, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush7(QColor(4, 44, 115, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        Back->setPalette(palette1);
        Back->setFont(font);
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent;\n"
"color: rgb(4, 44, 115);"));
        label = new QLabel(PauseMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 521, 521));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/failbgr);"));
        label->raise();
        Exit->raise();
        Back->raise();

        retranslateUi(PauseMenu);

        QMetaObject::connectSlotsByName(PauseMenu);
    } // setupUi

    void retranslateUi(QDialog *PauseMenu)
    {
        PauseMenu->setWindowTitle(QApplication::translate("PauseMenu", "GamePause", nullptr));
        Exit->setText(QApplication::translate("PauseMenu", "\351\200\200 \345\207\272 \346\270\270 \346\210\217", nullptr));
        Back->setText(QApplication::translate("PauseMenu", "\350\277\224 \345\233\236 \346\270\270 \346\210\217", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseMenu: public Ui_PauseMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEMENU_H
