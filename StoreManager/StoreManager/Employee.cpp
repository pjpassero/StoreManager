#include "Employee.h"
#include "UID.h"
#include <fstream>
#include <string>

using namespace std;

Employee::Employee( pqxx::connection &conn):C(conn) {
    salary = 0.0;
    name = "Employee NULL";
    employeeUID = "Employee NULL";
    username = "NULL";
    password = "NULL";
}


Employee::Employee(string nName, double nSalary, string pLevel, string uName, string pWord, string nAddress, pqxx::connection &conn):C(conn) {
    salary = nSalary;
    name = nName;
    accessLevel = pLevel;
    employeeUID = createNewID(6, name, false);
    username = uName;
    password = pWord;
    address = nAddress;
}


Employee::Employee(string uName, string pWord, pqxx::connection &conn):C(conn) {

    salary = 0.0;
    name = "";
    accessLevel = "";
    employeeUID = createNewID.genericId();
    username = uName;
    password = pWord;
    address = "";
    isActive = "N";

}


string Employee::getUID() {
    return employeeUID;
}

string Employee::getName() {
    return name;
}

string Employee::getPermissionLevel() {
    return accessLevel;
}

double removeExtraCharactersAndDouble(string workString) {

    string finalString = "";

    for(int i = 0; i < workString.length(); i++) {
        if(isdigit(workString[i])) {
            finalString += workString[i];
        }
    }

    return stod(finalString);

}

void Employee::setEmployeeDetails() {

    pqxx::work txn(C);
    std::string queryDetails = "SELECT * FROM employee WHERE username = $1 AND password = $2";
    pqxx::result result = txn.exec_params(queryDetails, username, password);


    if(!result.empty()) {
        string employeeID = result[0]["employeeId"].c_str();
        string dName = result[0]["fullname"].c_str();
        string personalEmail = result[0]["personalemail"].c_str();
        string permissionLevel = result[0]["permissionlevel"].c_str();
        string homeAddress = result[0]["address"].c_str();
        string activeLevel = result[0]["isactive"].c_str();
        double dSalary = removeExtraCharactersAndDouble(result[0]["salary"].c_str());



        employeeUID = employeeID;
        address = homeAddress;
        salary = dSalary;
        name = dName;
        accessLevel = permissionLevel;
        isActive = activeLevel;
        email = personalEmail;
    } else {
        cout << "Error" << endl;
    }



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
    /*

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

*/

