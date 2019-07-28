#ifndef FAILED_H
#define FAILED_H

#include <QDialog>

namespace Ui {
class failed;
}

class failed : public QDialog
{
    Q_OBJECT

public:
    explicit failed(QWidget *parent = nullptr);
    ~failed();

private slots:
    void on_Exit_clicked();

    void on_Back_clicked();

    void displayScore(int score);

signals:
    void closegame();

    void again();
private:
    Ui::failed *ui;
};

#endif // FAILED_H
