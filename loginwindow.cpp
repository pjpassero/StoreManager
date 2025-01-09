#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <QTimer>
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

bool LoginWindow::FindUserInDatabase(std::string &eUsername, std::string &ePassword) {

    std::ifstream myFile;

    std::string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/database.txt";

    myFile.open(filePath);

    if(myFile.is_open()) {
        std::string line;
        std::string db, uname, password, host, port;
        std::cout << "File Found!" << std::endl;
        while (std::getline(myFile, line)) {
            std::istringstream ss(line);

            // Parse the line
            if (std::getline(ss, db, ',') &&
                std::getline(ss, uname, ',') &&
                std::getline(ss, password, ',') &&
                std::getline(ss, host, ',') &&
                std::getline(ss, port, ',')) {

                // Print parsed data
                std::cout << "Database: " << db << std::endl;
                std::cout << "Username: " << uname << std::endl;
                std::cout << "Password: " << password << std::endl;
                std::cout << "Host: " << host << std::endl;
                std::cout << "Port: " << port << std::endl;
            } else {
                std::cerr << "Error parsing the line: " << line << std::endl;
            }


            std::string connectiontString = "dbname=" + db + " user=" + uname + " password=" + password + " host=" + host + " port=" + port;

            pqxx::connection C(connectiontString);

            if(C.is_open()) {
                pqxx::work txn(C);
                std::string query = "SELECT * FROM employee WHERE username = $1 AND password = $2";
                pqxx::result result = txn.exec_params(query, eUsername, ePassword);
                if (!result.empty()) {
                    std::cout << "Credentials are valid!" << std::endl;
                    ui->status->setText("Proper Credentials Entered! Logging in...");
                    ui->status->setStyleSheet("color:green;");
                    return true;
                } else {
                    std::cout << "Invalid credentials!" << std::endl;
                    ui->status->setText("Please check Credentials; Username or Password is incorrect!");
                    ui->status->setStyleSheet("color:red");

                    return false;
                }
            } else {
                std::cout << "Error connecting to the database" << std::endl;
                return false;
            }

    }

    } else {
        return false;
    }
    return false;
}

void LoginWindow::LoginToProgram() {
    std::string username = ui->user->toPlainText().toStdString();
    std::string password = ui->password->toPlainText().toStdString();

    //ui->datLine->setText(username + " " + password);

    //add login validation

    if(FindUserInDatabase(username, password)) {
        LaunchHomeView();

    } else {
        std::cout << "Error, check username or password" << std::endl;
    }

}


void LoginWindow::LaunchHomeView() {

    home = new HomePageView();
    home->activateWindow();
    home->raise();
    home->show();

    this->close();
}

bool LoginWindow::FindUserInDatastore() {



    return false;
}
