#ifndef RANKING_LIST_H
#define RANKING_LIST_H

#include <QMainWindow>
#include <QThread>
#include <QHeaderView>
#include <QDebug>
#include <QKeyEvent>
namespace Ui {
class ranking_list;
}

class ranking_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit ranking_list(QWidget *parent = nullptr);
    ~ranking_list();

signals:
    void sendsignal();

protected:
    void keyPressEvent(QKeyEvent *);

private slots:
    void on_Back_clicked();

private:
    Ui::ranking_list *ui;
};

#endif // RANKING_LIST_H
