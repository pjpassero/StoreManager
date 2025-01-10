#include "Employee.h"
#include "UID.h"
#include <fstream>
#include <string>

using namespace std;

Employee::Employee() {
    salary = 0.0;
    name = "Employee NULL";
    employeeUID = "Employee NULL";
    username = "NULL";
    password = "NULL";
}


Employee::Employee(string nName, double nSalary, string pLevel, string uName, string pWord, string nAddress) {
    salary = nSalary;
    name = nName;
    accessLevel = pLevel;
    employeeUID = createNewID(6, name, false);
    username = uName;
    password = pWord;
    address = nAddress;
}


string Employee::getUID() {
    return employeeUID;
}

string Employee::getName() {
    return name;
}


double Employee::getSalary() {
    return salary;
}

void Employee::SetEmployeeLoginCredentials(string uid, string u, string p) {
    username = u;
    password = p;
    string storeData = "LumberCo";
    //SaveNewEmployeeDriver(*(this), storeData);
}

bool Employee::SearchEmployeeFileByUID(string searchUID) {
    //cout << "UID: " << searchUID << endl;
    ifstream employeeFile;
    bool found = false;
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/employee/employee.txt";
    string line;

    try {
        employeeFile.open(filePath);

        if (!employeeFile.is_open()) {
            throw runtime_error("Unable to open file: " + filePath);
        }

        while (getline(employeeFile, line)) {
            if (line.size() >= 10) {
                string fileUID = line.substr(2, 6);
                if (searchUID == fileUID) {
                    found = true;
                    break;
                }
            }
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    employeeFile.close();
    return found;
}


/*
void Employee::ReadEmployeeData(string UID) {
    
    ofstream employeeFile;
    string filePath = "/Users/pjpassero/Documents/StoreManager/StoreManager/StoreDataFiles/" + storePath + "/employee/employee.txt";
    
    try {
        employeeFile.open(filePath);
        
        if(!employeeFile.is_open()) {
            throw runtime_error("Error unable to open the file:" + filePath);
        }
        
        
        
        
        
    } catch(exception &e) {
        cout << "Error:" << e.what();
    }
    
    
    
}
*/

void Employee::SaveEmployeeData(Employee &employee) {
    ofstream employeeFile;
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/employee/employee.txt";
    
    \
    try {
        employeeFile.open(filePath, ios_base::app);


        if(employeeFile.is_open()) {

            throw runtime_error("File not opened!");
        }



    } catch (exception &e) {
        cerr << "Error " << e.what();
    }

        
    
}


void Employee::AddNewEmployeeDriver(Employee &employee, string &storePath) {
    
    employee.isActive = 1;
    
    ofstream employeeFile;
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/" + storePath + "/employee/employee.txt";
    
    try  {
        employeeFile.open(filePath, ios_base::app);
        if (!employeeFile.is_open()) {
            throw runtime_error("Error: Unable to open file " + filePath);
        }
        
        if(SearchEmployeeFileByUID(employee.employeeUID)) {
            cout << "Employee Already in the data store!" << endl;
        } else {
            employeeFile << employee.isActive << "," << employee.employeeUID<<","<< employee.name << "," << employee.salary << ","<< employee.accessLevel << "," <<employee.username <<","<< employee.password<< ","<<employee.address<<endl;
            cout << "New employee added successfully!" << endl;

        }
        
    } catch (exception &e) {
        cerr << "Error " << e.what() << endl;
    }
    
    
};
