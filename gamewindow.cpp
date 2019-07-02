#include "gamewindow.h"
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QKeyEvent>
#include <QLabel>

GameWindow::GameWindow()
{
    isRunning = false;
    game = new Game( this );
    setCentralWidget( game );

    createMenu();
    createToolBar();

    connect( game, SIGNAL( finished() ), this, SLOT( on_finished() ) );
    connect( game, SIGNAL( scoreChanged( int ) ), this, SLOT( on_changeScore( int ) ) );

    resize( 600, 480 );
    setWindowTitle( tr( "The Game" ) );
}

void GameWindow::createMenu()
{
    newGame = new QAction( QIcon( ":/images/newgame.png" ), tr( "New Game" ), this );
    exitGame = new QAction( QIcon( ":/images/exit.png" ), tr( "Exit" ), this );
    startGame = new QAction( QIcon( ":/images/start.png" ), tr( "Start" ), this );
    stopGame = new QAction( QIcon( ":/images/stop.png" ), tr( "Stop" ), this );
    changeColor = new QAction( QIcon( ":/images/changecolor.png" ), tr( "Change Color" ), this );
    aboutAction = new QAction( QIcon( ":/images/about.png" ), tr( "about" ), this );
    gameOne = new QAction( QIcon( ":/images/game.png" ), tr( "Game One" ), this );
    gameTwo = new QAction( QIcon( ":/images/game.png" ), tr( "Game Two" ), this );
    gameThree = new QAction( QIcon( ":/images/game.png" ), tr( "Game Three" ), this );

    QMenu *optionMenu = menuBar()->addMenu( tr( "Option" ) );
    QMenu *controlMenu = menuBar()->addMenu( tr( "Control" ) );
    QMenu *setMenu = menuBar()->addMenu( tr( "Set" ) );
    QMenu *gameMenu = menuBar()->addMenu( tr( "Game" ) );
    QMenu *helpMenu = menuBar()->addMenu( tr( "Help" ) );

    optionMenu->addAction( newGame );
    optionMenu->addAction( exitGame );
    controlMenu->addAction( startGame );
    controlMenu->addAction( stopGame );
    setMenu->addAction( changeColor );
    gameMenu->addAction( gameOne );
    gameMenu->addAction( gameTwo );
    gameMenu->addAction( gameThree );
    helpMenu->addAction( aboutAction );

    connect( startGame, SIGNAL( triggered() ), this, SLOT( on_startGame() ) );
    connect( exitGame, SIGNAL( triggered() ), this, SLOT( close() ) );
    connect( changeColor, SIGNAL( triggered() ), this, SLOT( on_changeColor() ) );
    connect( stopGame, SIGNAL( triggered() ), this, SLOT( on_stopGame() ) );
    connect( newGame, SIGNAL( triggered() ), this, SLOT( on_newGame() ) );
    connect( aboutAction, SIGNAL( triggered() ), this, SLOT( on_about() ) );
    connect( gameOne, SIGNAL( triggered() ), this, SLOT( on_gameOne() ) );
    connect( gameTwo, SIGNAL( triggered() ), this, SLOT( on_gameTwo() ) );
    connect( gameThree, SIGNAL( triggered() ), this, SLOT( on_gameThree() ) );

    updateActions();
}

void GameWindow::createToolBar()
{
    QToolBar *controlToolBar = addToolBar( tr( "Control" ) );
    controlToolBar->addAction( newGame );
    controlToolBar->addAction( startGame );
    controlToolBar->addAction( stopGame );
    controlToolBar->addAction( changeColor );
    controlToolBar->addSeparator();

    gameLabel = new QLabel( tr( "<h3><font color=blue>Game One</font></h3>" ), this );
    scoreLabel = new QLabel( tr( "<h3><font color=green>Score: 0</font></h3>" ), this );
    controlToolBar->addWidget( gameLabel );
    controlToolBar->addSeparator();
    controlToolBar->addWidget( scoreLabel );
}

void GameWindow::on_finished()
{
    stopGame->setEnabled( false );
    startGame->setEnabled( false );
    changeColor->setEnabled( false );
}
void GameWindow::on_changeScore( int score )
{
    scoreLabel->setText( tr( "<h3><font color=blue>Score: %1</font></h3>" ).arg( score ) );
}
void GameWindow::on_newGame()
{
    createNewGame( 1 );
}

void GameWindow::createNewGame( int gameNum )
{
    if( gameNum == 1 )
    gameLabel->setText( tr( "<h3><font color=blue>Game One</font></h3>" ) );
    else if( gameNum == 2 )
    gameLabel->setText( tr( "<h3><font color=blue>Game Two</font></h3>" ) );
    else if( gameNum == 3 )
    gameLabel->setText( tr( "<h3><font color=blue>Game Three</font></h3>" ) );
    on_changeScore( 0 );

    game->deleteLater();
    game = new Game( this );
    setCentralWidget( game );
    game->setBallSpeed( gameNum );
    game->setPaddleStep( gameNum * 10.0 );
    connect( game, SIGNAL( finished() ), this, SLOT( on_finished() ) );
    connect( game, SIGNAL( scoreChanged( int ) ), this, SLOT( on_changeScore( int ) ) );
    isRunning = false;
    changeColor->setEnabled( true );
    updateActions();
}
void GameWindow::on_gameTwo()
{
    createNewGame( 2 );
}


void GameWindow::on_gameThree()
{
    createNewGame( 3 );
}
void GameWindow::on_about()
{
    QMessageBox::about( this, tr( "About" ), tr( "This is a small game developed by SenLin." ) );
}

void GameWindow::updateActions()
{
    startGame->setEnabled( !isRunning );
    stopGame->setEnabled( isRunning );
}

void GameWindow::on_startGame()
{
    game->startGame();
    isRunning = true;
    updateActions();
}

void GameWindow::on_stopGame()
{
    game->stopGame();
    isRunning = false;
    updateActions();
}
void GameWindow::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
        case Qt::Key_Left:
        game->movePaddleLeft();
        break;

        case Qt::Key_Right:
        game->movePaddleRight();
        break;
    }
}
