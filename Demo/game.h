#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>
#include <QBitmap>
#include <QMouseEvent>
#include <QtMath>
#include <QPainter>
#include <QMovie>
#include "failed.h"
#include <QThread>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;

    failed *fail;

    QPoint m_PointStart;

    QPoint m_PointEnd;
protected:
    void mouseMoveEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);

    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void getDifficulty(char difficulty);

    void setDifficulty(char difficulty);

    void gamePlay();

    void on_TestFailure_clicked();

    void closeself();

    void chooseagain();

    void generateNewBall();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

signals:
    void tryagain();
};

#endif // GAME_H
