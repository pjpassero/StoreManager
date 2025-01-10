/*
ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <pqxx/pqxx>
#include <string>
#include <fstream>
#include <iostream>

class DatabaseManager {


public:
    static DatabaseManager& getInstance();


    pqxx::connection& getConnection();


private:
    DatabaseManager();
    ~DatabaseManager();
    std::string popualteConnectionDetailsFromFile();
    pqxx::connection* conn;
    std::string connectionString;

};
std::string DatabaseManager::popualteConnectionDetailsFromFile() {
    std::ifstream myFile;
    std::string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/database.txt";
    myFile.open(filePath);
    std::string connectionStr;
    if (myFile.is_open()) {
        std::string line;
        std::string db, uname, password, host, port;
        std::cout << "File Found!" << std::endl;

        if (std::getline(myFile, line)) {
            std::istringstream ss(line);

            if (std::getline(ss, db, ',') &&
                std::getline(ss, uname, ',') &&
                std::getline(ss, password, ',') &&
                std::getline(ss, host, ',') &&
                std::getline(ss, port, ',')) {

                std::cout << "Database: " << db << std::endl;
                std::cout << "Username: " << uname << std::endl;
                std::cout << "Password: " << password << std::endl;
                std::cout << "Host: " << host << std::endl;
                std::cout << "Port: " << port << std::endl;

                connectionStr = "dbname=" + db + " user=" + uname + " password=" + password + " host=" + host + " port=" + port;

                std::cout << "Connection String: " << connectionStr << std::endl;
            } else {
                std::cerr << "Error parsing the line: " << line << std::endl;
            }
        }
    } else {
        std::cerr << "Error opening the file!" << std::endl;
    }
    return connectionStr;

}
DatabaseManager::DatabaseManager()
    : connectionString(), conn(nullptr) {
    try {
        connectionString = popualteConnectionDetailsFromFile();
        conn = new pqxx::connection(connectionString);
        if (conn->is_open()) {
            std::cout << "Connected to database!" << std::endl;
        } else {
            std::cerr << "Connection to database failed!" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error opening connection: " << e.what() << std::endl;
    }
}

DatabaseManager::~DatabaseManager() {
    if (conn && conn->is_open()) {
        conn->close();
        delete conn;
        std::cout << "Database connection closed." << std::endl;
    }
}




pqxx::connection& DatabaseManager::getConnection() {
    return *conn;
}

#endif // DATABASEMANAGER_H
*/
