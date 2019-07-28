#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QMessageBox>
#include "difficulty_choose.h"
#include "saves.h"
#include "login.h"
#include "ranking_list.h"
#include "guidepage.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    difficulty_choose *diff;

    saves *save;

    login *logindlg;

    ranking_list *rank;

    guidepage *guide;
protected:


private slots:

    void BallBounce();

    void reshow();

    void closeself();

    void on_StartGame_clicked();

    bool getSaves();

    void on_About_clicked();

    void on_ResumeGame_clicked();

    void loginSuccessful(QString acct);

    void on_Exit_clicked();

    void on_Rank_clicked();

    void on_Sound_clicked();

    void on_Guide_clicked();
};

#endif // MAINWINDOW_H
