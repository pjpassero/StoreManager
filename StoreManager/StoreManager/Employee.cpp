/*
 * Philip J. Passero IV
 * Employee.cpp
 *
 * Employee class implementation file
 *
 * Implements the constructors, destructor, and various functions of the employee class
 *
 */

#include "Employee.h"
#include "UID.h"
#include <fstream>
#include <string>

using namespace std;


/*
 * Default constructor with connection
 * @param conn: reference to the connection to application database
 *
 * Everything will be set to NULL or a varaition of it except the connection reference
 */

Employee::Employee( pqxx::connection &conn):C(conn) {
    salary = 0.0;
    name = "Employee NULL";
    employeeUID = "Employee NULL";
    username = "NULL";
    password = "NULL";
}

/*
 * Constructor that initalizes all the fields based on user inputs
 * @param nName: the name of the employee
 * @param nSalary: the salary of the employee
 * @param pEmail: the email of the employee
 * @param pN: the phonenumber of the employee
 * @param aL: the active level of the employee (is the employee current or old)
 * @param pLevel: the permission level of the employee
 * @param uName: the username of the employee to access the application
 * @pram pWord: the password of the employee to access the application
 * @param nAddress: the address of the employee
 * @param conn: the connection class details to access the database
 *
 * Intializes all the fields based on what the user gives.
 */

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
/*
 * Constructor that create employee class with username and password
 * @param uName: username of the employee to access the application
 * @param pWord: password of the employee to access the application
 * @param conn: the connection details to access the database
 *
 * Initalizes the username and password fields to the user given values, sets eveything else to empty until fields can be filled.
 *
 */

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


/*
 * Return the UID of the employee
 */

string Employee::getUID() {
    return employeeUID;
}

/*
 * Return the name of the employee
 */

string Employee::getName() {
    return name;
}

/*
 * Return the permission level of the employee
 */

string Employee::getPermissionLevel() {
    return accessLevel;
}


/*
 * Return the salary of the employee
 */
double Employee::getSalary() {
    return salary;
}

/*
 * @param workString: the string that has the extra characters
 *
 * This function is defined to only return the digits of a string that is stored in the database.
 * Since PSQL stores the salary in the "money" format, when queried, it cannot be placed directly in a double
 * So, the string is traversed and only digits are kept and then converted to a double and returned
 *
 * @return double representing the salary of the employee
 */

double removeExtraCharactersAndDouble(string workString) {

    string finalString = "";

    for(int i = 0; i < workString.length(); i++) {
        if(isdigit(workString[i])) {
            finalString += workString[i];
        }
    }

    return stod(finalString);

}

/*
 * Will set the employee details based on the username and password.
 * To be mainly used with the constructor that is defined to take in username, password, and connection
 * Database is queried to return the entire relation that represents the employee based on username and password
 *
 */

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
/*
 * @param employee: the employee that is going to be added to the database
 *
 * Adds a new employee to the company. It is called by the employee object that needs to be added.
 *
 */
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
