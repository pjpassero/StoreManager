#include "loginwindow.h"
#include "QtWidgets/qlineedit.h"
#include "ui_loginwindow.h"
#include "pointofsaleview.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "StoreManager/StoreManager/UserSession.h"
#include <QTimer>
LoginWindow::LoginWindow(QWidget *parent, pqxx::connection& conn, LOGINTYPE login)
    : QMainWindow(parent), C(conn),logInAs(login), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Store Manager Pro: Login");
    ui->password->setEchoMode(QLineEdit::Password);


    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWindow::LoginToProgram);



}

LoginWindow::~LoginWindow()
{
    delete ui;

}

bool LoginWindow::FindUserInDatabase(std::string &eUsername, std::string &ePassword) {
    try {
        pqxx::work txn(C);
        std::string query = "SELECT * FROM employee WHERE username = $1 AND password = $2";
        pqxx::result result = txn.exec_params(query, eUsername, ePassword);

        if (!result.empty()) {
            ui->status->setText("Proper Credentials Entered! Logging in...");
            ui->status->setStyleSheet("color:green;");
            return true;
        } else {
            ui->status->setText("Please check Credentials!");
            ui->status->setStyleSheet("color:red");
            return false;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}


void LoginWindow::LoginToProgram() {
    std::string username = ui->user->toPlainText().toStdString();
    std::string password = ui->password->text().toStdString();

    //ui->datLine->setText(username + " " + password);

    //add login validation

    if(FindUserInDatabase(username, password)) {

        Employee currentEmployee(username, password, C);
        currentEmployee.setEmployeeDetails();

        UserSession newSession(currentEmployee, C);
        std::cout << logInAs;
        if(logInAs == MAINWINDOW) {
            LaunchHomeView(newSession);
        } else if(logInAs == POINT_OF_SALE) {
            LauchPointOfSaleView(newSession);
        }

    } else {
        std::cout << "Error, check username or password" << std::endl;
    }

}

void LoginWindow::LauchPointOfSaleView(UserSession &us) {
    us.logSessionEvent("login");
    PointOfSaleView* parentWin = qobject_cast<PointOfSaleView*>(parent());
    parentWin->setSession(&us);
    parentWin->updateWinData();
    this->close();
}

void LoginWindow::LaunchHomeView(UserSession &us) {

    us.logSessionEvent("login");
    home = new HomePageView(nullptr, C, us);
    home->activateWindow();
    home->raise();
    home->show();

    this->close();
}

