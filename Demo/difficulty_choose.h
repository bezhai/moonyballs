#ifndef DIFFICULTY_CHOOSE_H
#define DIFFICULTY_CHOOSE_H

#include <QWidget>
#include <QThread>
#include <QKeyEvent>
#include "game.h"

namespace Ui {
class difficulty_choose;
}

class difficulty_choose : public QWidget
{
    Q_OBJECT

public:
    explicit difficulty_choose(QWidget *parent = nullptr);
    ~difficulty_choose();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_Back_clicked();

    void on_Easy_clicked();

    void on_Medium_clicked();

    void on_Hard_clicked();

signals:
    void sendsignal();

    void sendDifficulty(char difficulty);
private:
    Ui::difficulty_choose *ui;

    Game *gm;
};

#endif // DIFFICULTY_CHOOSE_H
