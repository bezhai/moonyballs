#include "gamewindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char **argv )
{
    QApplication app( argc, argv );

    QTranslator translator;
    translator.load( ":language/game_zh_CN.qm" );
    app.installTranslator( &translator );

    GameWindow window;
    window.show();

    return app.exec();
}
