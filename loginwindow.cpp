#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Store Manager Pro: Login");



    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWindow::LoginToProgram);



}

LoginWindow::~LoginWindow()
{
    delete ui;

}


void LoginWindow::LoginToProgram() {
    QString username = ui->user->toPlainText();
    QString password = ui->password->toPlainText();

    ui->datLine->setText(username + " " + password);
}


bool LoginWindow::FindUserInDatastore() {



    return false;
}
