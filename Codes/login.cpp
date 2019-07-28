#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint|Qt::WindowStaysOnTopHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

login::~login()
{
    delete ui;
}

void login::on_Exit_clicked()
{
    emit closeGame();
    this->close();
}

void login::on_GuestLogin_clicked()
{
    emit logged("Guest");
    this->close();
}

void login::on_Login_clicked()
{
    if (ui->Acct->text().isEmpty())
    {
        QMessageBox::warning(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("用户名不能为空！"));
    }
    else
    {
        // QMessageBox::critical(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("密码错误！请检查你的输入！"));
        emit logged(ui->Acct->text());
        this->close();
    }
}

void login::on_Register_clicked()
{
    QMessageBox::critical(this,QString::fromLocal8Bit("没做好"),QString::fromLocal8Bit("功能暂无！"));
}
