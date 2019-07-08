#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QDialog>

namespace Ui {
class PauseMenu;
}

class PauseMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PauseMenu(QWidget *parent = nullptr);
    ~PauseMenu();

signals:
    void resume();

    void closegame();
private slots:
    void on_Exit_clicked();

    void on_Back_clicked();

private:
    Ui::PauseMenu *ui;
};

#endif // PAUSEMENU_H
