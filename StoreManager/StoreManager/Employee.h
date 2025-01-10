#pragma once
#include <string>
#include "UID.h"
using namespace std;

class Employee {

public:
    Employee();
    Employee(string nName, double nSalary, string pLevel, string uName, string pWord, string nAddress);

    string getUID();
    string getName();
    double getSalary();
    
    void deactivateEmployee(string UID);
    void AddNewEmployeeDriver(Employee &employeel, string &storePath);
    void SaveEmployeeData(Employee &employee);
    void SetEmployeeLoginCredentials(string uid, string username, string password);
    void ReadEmployeeData(string UID);
    bool SearchEmployeeFileByUID(string UID);
    
    
    friend class Store;
private:
    string employeeUID;
    string address;
    double salary;
    string name;
    UID createNewID;
    string accessLevel;
    int isActive;
    string username;
    string password;
    
    
};
