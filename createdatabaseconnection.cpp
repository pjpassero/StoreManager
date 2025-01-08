#include "createdatabaseconnection.h"
#include "ui_createdatabaseconnection.h"
#include "pqxx/pqxx"
#include <iostream>
#include <string>

CreateDatabaseConnection::CreateDatabaseConnection(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateDatabaseConnection)
{
    ui->setupUi(this);

    connect(ui->connectBtn, &QPushButton::clicked, this, &CreateDatabaseConnection::CreateConn);


}

CreateDatabaseConnection::~CreateDatabaseConnection()
{
    delete ui;
}


void CreateDatabaseConnection::CreateConn() {


    std::string databaseName = ui->databaseName->toPlainText().toStdString();
    std::string username = ui->userName->toPlainText().toStdString();
    std::string password = ui->password->toPlainText().toStdString();
    std::string host = ui->host->toPlainText().toStdString();
    std::string port = ui->port->toPlainText().toStdString();



    if(host.empty()) {
        std::cout << "Host is empty";
        host = "localhost";
    }

    if(port.empty()) {
        std::cout << "Port is empty";
        port="5432";
    }
    std::cout << databaseName << " " << username << " " << password << " " << host << " " << port << " ";
    std::string connectiontString = "dbname=" + databaseName + " user=" + username + " password=" + password + " host=" + host + " port=" + port;

    try {
        pqxx::connection C(connectiontString);

        if(C.is_open()) {
            std::cout << "Database successfully connected!" << std::endl;
        } else {
            std::cout << "Database was unable to connect!" << std::endl;
        }


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;

    }



};
