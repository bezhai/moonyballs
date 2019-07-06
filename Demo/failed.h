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

private:
    Ui::failed *ui;
};

#endif // FAILED_H
