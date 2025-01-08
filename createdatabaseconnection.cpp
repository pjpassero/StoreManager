#include "createdatabaseconnection.h"
#include "ui_createdatabaseconnection.h"
#include "pqxx/pqxx"
#include <iostream>
#include <string>
#include <fstream>

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
        std::cout << "Host is empty" << std::endl;
        host = "localhost";
    }

    if(port.empty()) {
        std::cout << "Port is empty" << std::endl;
        port="5432";
    }
    std::string connectiontString = "dbname=" + databaseName + " user=" + username + " password=" + password + " host=" + host + " port=" + port;

    try {
        pqxx::connection C(connectiontString);

        if(C.is_open()) {
            std::cout << "Database successfully connected!" << std::endl;
            ui->connectionStatus->setText("Connected to Database successfully!");
            ui->connectionStatus->setStyleSheet("color:green;");
            CreateDatabaseConnection::CreateStoreDatabaseCredentialFile(databaseName,username, password, host, port);
        } else {
            std::cout << "Database was unable to connect!" << std::endl;
            ui->connectionStatus->setText("Unable to connect to Database!");
            ui->connectionStatus->setStyleSheet("color:red;");

        }


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        ui->ErrorMessage->setText(e.what());

    }



};



void CreateDatabaseConnection::CreateStoreDatabaseCredentialFile(const std::string& db, const std::string& uname, const std::string& password, const std::string& host, const std::string& port){

    std::string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/database.txt";

    std::ofstream myFile;

    myFile.open(filePath);

    if(myFile.is_open()) {
        std::cout << "File is open!" << std::endl;
        myFile << db << "," << uname << "," << password << "," << host << "," << port;
    } else  {
        std::cout << "Error in opening the file!" << std::endl;
    }


    myFile.close();



};


