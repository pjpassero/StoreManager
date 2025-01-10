#include <string>
#include <iostream>
#include "Employee.h"
#include <map>
using namespace std;

class Store {
public:
    
    Store();
    Store(string storename, Employee &owner);
    Store(string fileName);
    void setStoreName(string name);
    void setStoreOwner(Employee &newOwner);
    void addNewEmployee(Employee &newEmployee);
    void saveStoreToFile();
    void storeName();
    void ownerName();
    void ConvertInventoryFileToCSVFormat();
    void ReadInventoryFile();
    friend class Employee;
private:
    Employee StoreOwner;
    string StoreName;
    string storeAddress;
    string storeDataFile;
    int customerCount;
    int employeeCount;
    map<string,string> parseString(string pString);
    map<string, map<string,string>> employees;
    
    
};
