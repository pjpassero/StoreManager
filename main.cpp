
#include "mainwindow.h"
//#include "firstwindow.h"
#include <QApplication>
#include "inventoryview.h"
#include "productview.h"
#include "loginwindow.h"
#include "firstwindow.h"
#include <pqxx/pqxx>
#include <fstream>
#include <iostream>


std::string retrieveDatabaseConnectionString() {

    std::ifstream databaseFile;
    std::string connString;
    std::string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/database.txt";


    databaseFile.open(filePath);

    if(databaseFile.is_open()) {
        std::string line;
        std::string db, uname, password, host, port;
        std::cout << "File Found!" << std::endl;
        while (std::getline(databaseFile, line)) {
            std::istringstream ss(line);

            // Parse the line
            if (std::getline(ss, db, ',') &&
                std::getline(ss, uname, ',') &&
                std::getline(ss, password, ',') &&
                std::getline(ss, host, ',') &&
                std::getline(ss, port, ',')) {

                // Print parsed data - Not really needed unless for debugging
                /*
                std::cout << "Database: " << db << std::endl;
                std::cout << "Username: " << uname << std::endl;
                std::cout << "Password: " << password << std::endl;
                std::cout << "Host: " << host << std::endl;
                std::cout << "Port: " << port << std::endl;
                */
            } else {
                std::cerr << "Error parsing the line: " << line << std::endl;
            }


            connString = "dbname=" + db + " user=" + uname + " password=" + password + " host=" + host + " port=" + port;

        }

    }


    return connString;

}


int main(int argc, char *argv[])
{



    pqxx::connection C(retrieveDatabaseConnectionString());

    if(C.is_open()) {
        std::cout << "Database is connected! " << std::endl;
    } else {
        std::cerr << "Error connection to the database" << std::endl;
    }

    QApplication a(argc, argv);
    LoginWindow login(nullptr, C);

    login.show();


    return a.exec();
}
