#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include "game.h"
#include <QMainWindow>

class QAction;
class QKeyEvent;
class QLabel;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow();

public slots:
    void on_changeColor();
    void on_newGame();
    void on_startGame();
    void on_stopGame();
    void on_about();
    void on_finished();
    void on_gameOne();
    void on_gameTwo();
    void on_gameThree();
    void on_changeScore( int );

protected:
    void keyPressEvent( QKeyEvent * );

private:
    void createMenu();
    void createToolBar();
    void updateActions();
    void createNewGame( int );

    QAction *newGame;
    QAction *aboutAction;
    QAction *startGame;
    QAction *stopGame;
    QAction *exitGame;
    QAction *changeColor;
    QAction *gameOne;
    QAction *gameTwo;
    QAction *gameThree;
    QLabel *gameLabel;
    QLabel *scoreLabel;

    Game *game;
    bool isRunning;
};

#endif
