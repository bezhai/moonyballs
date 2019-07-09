/********************************************************************************
** Form generated from reading UI file 'ranking_list.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKING_LIST_H
#define UI_RANKING_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ranking_list
{
public:
    QWidget *centralwidget;
    QPushButton *Back;
    QTableWidget *RankingList;

    void setupUi(QMainWindow *ranking_list)
    {
        if (ranking_list->objectName().isEmpty())
            ranking_list->setObjectName(QString::fromUtf8("ranking_list"));
        ranking_list->resize(1280, 720);
        ranking_list->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/savesbgr);"));
        centralwidget = new QWidget(ranking_list);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Back = new QPushButton(centralwidget);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(0, 0, 93, 91));
        Back->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/back);\n"
"background: transparent"));
        RankingList = new QTableWidget(centralwidget);
        if (RankingList->columnCount() < 4)
            RankingList->setColumnCount(4);
        if (RankingList->rowCount() < 100)
            RankingList->setRowCount(100);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        RankingList->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        RankingList->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        RankingList->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        RankingList->setItem(0, 3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        RankingList->setItem(1, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        RankingList->setItem(1, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        RankingList->setItem(1, 2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        RankingList->setItem(1, 3, __qtablewidgetitem7);
        RankingList->setObjectName(QString::fromUtf8("RankingList"));
        RankingList->setGeometry(QRect(140, 60, 1001, 561));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(17);
        RankingList->setFont(font);
        RankingList->setStyleSheet(QString::fromUtf8("background: transparent"));
        RankingList->setShowGrid(false);
        RankingList->setRowCount(100);
        RankingList->setColumnCount(4);
        ranking_list->setCentralWidget(centralwidget);

        retranslateUi(ranking_list);

        QMetaObject::connectSlotsByName(ranking_list);
    } // setupUi

    void retranslateUi(QMainWindow *ranking_list)
    {
        ranking_list->setWindowTitle(QApplication::translate("ranking_list", "Ranking List", nullptr));
        Back->setText(QString());

        const bool __sortingEnabled = RankingList->isSortingEnabled();
        RankingList->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = RankingList->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("ranking_list", "\347\216\251\345\256\266\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = RankingList->item(0, 1);
        ___qtablewidgetitem1->setText(QApplication::translate("ranking_list", "\351\232\276\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = RankingList->item(0, 2);
        ___qtablewidgetitem2->setText(QApplication::translate("ranking_list", "\345\276\227\345\210\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = RankingList->item(0, 3);
        ___qtablewidgetitem3->setText(QApplication::translate("ranking_list", "\346\216\222\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = RankingList->item(1, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("ranking_list", "Admin", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = RankingList->item(1, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("ranking_list", "Difficult", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = RankingList->item(1, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("ranking_list", "9999999", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = RankingList->item(1, 3);
        ___qtablewidgetitem7->setText(QApplication::translate("ranking_list", "1", nullptr));
        RankingList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ranking_list: public Ui_ranking_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKING_LIST_H
