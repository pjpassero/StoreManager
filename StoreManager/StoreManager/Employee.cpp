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


Employee::Employee(string nName, double nSalary, string pEmail, string pN, string aL, string pLevel, string uName, string pWord, string nAddress, pqxx::connection &conn):C(conn) {
    salary = nSalary;
    name = nName;
    accessLevel = pLevel;
    isActive = aL;
    employeeUID = createNewID(6, name, false);
    username = uName;
    password = pWord;
    address = nAddress;
    email = pEmail;
    phonenumber = pN;
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
void Employee::AddNewEmployeeDriver(Employee &employee) {

    try {
        pqxx::work txn(C);
        std::string query = "INSERT INTO employee (employeeid, fullname, personalemail,phonenumber,permissionlevel,address,isactive,username, password, salary) "
                            "VALUES ($1, $2, $3, $4, $5, $6, $7,$8,$9,$10)";
        pqxx::result result = txn.exec_params(query, employeeUID, name, email, phonenumber, accessLevel, address, isActive, username, password,salary);

        txn.commit();

        std::cout << "Employee Added!" << std::endl;

    } catch (const std::exception &e) {

    std::cerr << "Error saving product to inventory: " << e.what() << std::endl;
}





};


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



*/

