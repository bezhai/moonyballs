/********************************************************************************
** Form generated from reading UI file 'failed.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILED_H
#define UI_FAILED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_failed
{
public:
    QLabel *label;
    QLabel *Score;
    QPushButton *Exit;
    QPushButton *Back;

    void setupUi(QDialog *failed)
    {
        if (failed->objectName().isEmpty())
            failed->setObjectName(QString::fromUtf8("failed"));
        failed->resize(522, 521);
        failed->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(failed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 521, 521));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/failbgr);"));
        Score = new QLabel(failed);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(140, 50, 241, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(17);
        Score->setFont(font);
        Exit = new QPushButton(failed);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(110, 380, 301, 71));
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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223_GB2312"));
        font1.setPointSize(26);
        Exit->setFont(font1);
        Exit->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent;\n"
"color: rgb(4, 44, 115);"));
        Back = new QPushButton(failed);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(110, 300, 301, 71));
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
        Back->setFont(font1);
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/btn);\n"
"background: transparent;\n"
"color: rgb(4, 44, 115);"));

        retranslateUi(failed);

        QMetaObject::connectSlotsByName(failed);
    } // setupUi

    void retranslateUi(QDialog *failed)
    {
        failed->setWindowTitle(QApplication::translate("failed", "GameOver!", nullptr));
        label->setText(QString());
        Score->setText(QApplication::translate("failed", "\344\275\240\347\232\204\345\276\227\345\210\206: ", nullptr));
        Exit->setText(QApplication::translate("failed", "\351\200\200 \345\207\272 \346\270\270 \346\210\217", nullptr));
        Back->setText(QApplication::translate("failed", "\350\277\224 \345\233\236 \351\200\211 \345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class failed: public Ui_failed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILED_H
