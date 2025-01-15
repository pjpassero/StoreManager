#ifndef USERSESSION_H
#define USERSESSION_H

#include "Employee.h"
#include <ctime>
#include <pqxx/pqxx>
class UserSession {

public:
    UserSession(Employee &userLoggedIn, pqxx::connection &conn);
    void logSessionEvent(std::string type);
    Employee& getCurentEmployee();

private:
    Employee& activeUser;
    pqxx::connection &C;
    std::time_t sessionStart;
    std::time_t sessionEnd;


};



#endif // USERSESSION_H
