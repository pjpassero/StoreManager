#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "StoreManager/StoreManager/UserSession.h"
#include <QTimer>
LoginWindow::LoginWindow(QWidget *parent, pqxx::connection& conn)
    : QMainWindow(parent), C(conn), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Store Manager Pro: Login");



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
    std::string password = ui->password->toPlainText().toStdString();

    //ui->datLine->setText(username + " " + password);

    //add login validation

    if(FindUserInDatabase(username, password)) {

        Employee currentEmployee(username, password, C);
        currentEmployee.setEmployeeDetails();

        UserSession newSession(currentEmployee, C);

        LaunchHomeView(newSession);

    } else {
        std::cout << "Error, check username or password" << std::endl;
    }

}


void LoginWindow::LaunchHomeView(UserSession &us) {

    us.logSessionEvent("login");
    home = new HomePageView(nullptr, C, us);
    home->activateWindow();
    home->raise();
    home->show();

    this->close();
}

bool LoginWindow::FindUserInDatastore() {



    return false;
}
