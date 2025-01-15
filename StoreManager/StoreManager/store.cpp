/*
#include "store.h"
#include <fstream>
#include <map>
using namespace std;


Store::Store() {
    StoreName = "Unnamed!";
    
    
    
}


Store::Store(string storename, Employee &owner) {
    StoreName = storename;
    StoreOwner = owner;
}



Store::Store(string filename) {
    
    ifstream companyFile;
    
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/" + filename + "/" + filename + ".txt";
    
    companyFile.open(filePath);
    string line;
    if(!companyFile.is_open()) {
        cout << "Error, file not open" << endl;
        cout << "Cannot open " << filename << endl;
    } else {
        getline(companyFile, line);
    }
    
    map<string,string> myCompany = parseString(line);
    
    StoreName = myCompany["CompanyName"];
    Employee owner(myCompany["OwnerName"], 100000.0, "Owner", "admin", "password","addresHere");
    employeeCount = stoi(myCompany.at("EmployeeCount"));
    customerCount = stoi(myCompany.at("CustomerCount"));
    storeAddress = myCompany.at("Address");
    
    StoreOwner = owner;
    
    storeDataFile = filename;
    
    
    companyFile.close();
    
    
    
    
}
map<string,string> Store::parseString(string pString) {
    vector<string> fieldNames = {"CompanyName", "OwnerName", "Address", "EmployeeCount", "CustomerCount"};
    map<string, string> myCompanyStructured;
    string currentSubString;
    int fieldNameCounter = 0;
    for(int i = 0; i < pString.length(); i++) {
        if(pString[i] == ',') {
            myCompanyStructured[fieldNames[fieldNameCounter]] = currentSubString;
            currentSubString = "";
            fieldNameCounter++;
        } else {
            currentSubString += pString[i];
        }
        if (i == pString.length() - 1) {
            myCompanyStructured[fieldNames[fieldNameCounter]] = currentSubString;
        }
    }
    return myCompanyStructured;
}

void Store::addNewEmployee(Employee &newEmployee) {
    employeeCount++;
    
    
    newEmployee.AddNewEmployeeDriver(newEmployee, storeDataFile);
    
}

void Store::saveStoreToFile() {
    
    ofstream companyFile;
    
    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/" + storeDataFile + "/" + storeDataFile + ".txt";
    
    
    companyFile.open(filePath);
    if(!companyFile.is_open()) {
        cout << "Error, file not open" << endl;
        cout << "Cannot open " << filePath << endl;
    } else {
        companyFile << StoreName << "," << StoreOwner.getName() << storeAddress << employeeCount << customerCount;
        cout << "Successfully wrote to the company file!" << endl;
    }
    
    
    companyFile.close();
}


void Store::storeName() {
    cout << StoreName << endl;
}


void Store::ownerName() {
    cout << StoreOwner.getName() << endl;
}


void Store::setStoreName(string name) {
    StoreName = name;
}


void Store::ConvertInventoryFileToCSVFormat() {
    
    ifstream mainInventoryFile;
    ofstream outputCSVFile;
    
    string line;
    
    string mainInventoryFilePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.txt";
    string outputCSVFilePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.csv";
    
    try {
        mainInventoryFile.open(mainInventoryFilePath);
        outputCSVFile.open(outputCSVFilePath, ios_base::app);
        
        if(!mainInventoryFile.is_open() && !outputCSVFile.is_open()) {
            throw runtime_error("Cannot open inventory file and base CSV file!");
        }
        if(!mainInventoryFile.is_open()) {
            throw runtime_error("Cannot open inventory file!");

        }
        if(!mainInventoryFile.is_open()) {
            throw runtime_error("Cannot open CSV file!");

        }
        
        while(getline(mainInventoryFile, line)) {
            outputCSVFile << line << endl;
        }
        
        
    }catch(exception &e) {
        cerr << "Error: " << e.what();
    }
    
    cout << "File generated successfully!" << endl;
    
    mainInventoryFile.close();
    outputCSVFile.close();
    
    
}


void Store::ReadInventoryFile() {
    ifstream companyInventoryFile;
    

    string filePath = "/Users/pjpassero/Documents/StoreApplication/StoreManager/StoreManager/StoreDataFiles/LumberCo/inventory/inventory.txt";

    string currentFileLine;
    try {
        companyInventoryFile.open(filePath);
        
        if(!companyInventoryFile.is_open()) {
            throw runtime_error("Cannot open the file");
        }
        
        while(getline(companyInventoryFile, currentFileLine)) {

            cout << currentFileLine << endl;
        }
        
        
        
    }catch(exception &e) {
        cerr << "Error" << e.what();
    }
    
    
    companyInventoryFile.close();

}
*/
