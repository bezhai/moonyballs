#ifndef GUIDEPAGE_H
#define GUIDEPAGE_H

#include <QWidget>
#include <QThread>
#include <QKeyEvent>
namespace Ui {
class guidepage;
}

class guidepage : public QWidget
{
    Q_OBJECT

public:
    explicit guidepage(QWidget *parent = nullptr);
    ~guidepage();

private slots:
    void on_Back_clicked();

protected:
    void keyPressEvent(QKeyEvent *);
signals:

    void sendsignal();
private:
    Ui::guidepage *ui;
};

#endif // GUIDEPAGE_H
