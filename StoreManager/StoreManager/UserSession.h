#ifndef USERSESSION_H
#define USERSESSION_H

#include "Employee.h"
#include <ctime>
#include <pqxx/pqxx>
class UserSession {

public:
    UserSession(Employee &userLoggedIn, pqxx::connection &conn);

private:
    Employee& activeUser;
    pqxx::connection &C;
    std::time_t sessionStart;
    std::time_t sessionEnd;

    void logSessionEvent();

};



#endif // USERSESSION_H
