#include "UserSession.h"
#include <ctime>
#include "Employee.h"



UserSession::UserSession(Employee &userLoggedIn, pqxx::connection &conn):activeUser(userLoggedIn), C(conn){

    sessionStart = std::time(nullptr); //start time




}


void UserSession::logSessionEvent(std::string type) {

    string employeeId = activeUser.getUID();

    pqxx::work txn(C);


    std::string logEventInsert = "INSERT INTO accessLog (userId, timeAccessed, eventType) " "VALUES ($1, $2, $3)";
    pqxx::result result = txn.exec_params(logEventInsert, employeeId, sessionStart, type);


    txn.commit();
}
