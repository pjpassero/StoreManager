#include "UserSession.h"
#include <ctime>
#include "Employee.h"



UserSession::UserSession(Employee &userLoggedIn, pqxx::connection &conn):activeUser(userLoggedIn), C(conn){

    sessionStart = std::time(0); //start time




}


void UserSession::logSessionEvent() {

    pqxx::work txn(C);
    std::string logEventInsert = "INSERT INTO accessLog (userId, timeAccessed, eventType) " "VALUES (1, '12:30:00', 'Login')";
    //Comment

}
