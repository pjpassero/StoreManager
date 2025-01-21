/*
 * Philip J. Passero IV
 * Employee.h
 *
 * Employee Class declaration file. Defines the employee class.
 *
 */

#pragma once
#include <string>
#include "UID.h"
#include <pqxx/pqxx>
using namespace std;

class Employee {

public:
    Employee(pqxx::connection &conn);
    Employee(string nName, double nSalary, string pEmail, string pN, string aL, string pLevel, string uName, string pWord, string nAddress, pqxx::connection &conn);
    Employee(string userName, string password, pqxx::connection &conn);
    string getUID();
    string getName();
    double getSalary();
    
    void deactivateEmployee(string UID);
    void AddNewEmployeeDriver(Employee &employeel);
    void SaveEmployeeData(Employee &employee);
    void SetEmployeeLoginCredentials(string uid, string username, string password);
    void ReadEmployeeData(string UID);
    bool SearchEmployeeFileByUID(string UID);
    void setEmployeeDetails();
    string getPermissionLevel();

    
    friend class Store;
private:
    pqxx::connection &C;
    string employeeUID;
    string address;
    double salary;
    string name;
    UID createNewID;
    string accessLevel;
    string isActive;
    string username;
    string password;
    string email;
    string phonenumber;
    
    
};
