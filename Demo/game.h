#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>
#include <QBitmap>
#include <QMouseEvent>
#include <QtMath>
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

protected:
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void getDifficulty(char difficulty);

    void setDifficulty(char difficulty);

};

#endif // GAME_H
