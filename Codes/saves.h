#ifndef SAVES_H
#define SAVES_H

#include <QWidget>
#include <QThread>
#include <QDebug>
#include <QKeyEvent>
namespace Ui {
class saves;
}

class saves : public QWidget
{
    Q_OBJECT

public:
    explicit saves(QWidget *parent = nullptr);
    ~saves();

private slots:
    void on_Back_clicked();

    void getSaves();

    bool getSlot(int index);

    QString getInfo(int index);

protected:

    void keyPressEvent(QKeyEvent *);

signals:

    void sendsignal();

private:
    Ui::saves *ui;
};

#endif // SAVES_H
