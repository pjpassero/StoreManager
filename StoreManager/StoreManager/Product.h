#pragma once
#ifndef Product_h
#define Product_h
#include <pqxx/pqxx>
#include "UID.h"
#include <string>

using namespace std;

class Product {
private:
    UID createUID;

    string name;
    int lastSupplier; // convert this to a supplier class
    string storeSKU;
    double factoryCost;
    double price;
    int quantity;
    long long int UPC;
    int generateSKU();
    int activationLevel;


    pqxx::connection &C;

public:
    Product(pqxx::connection &conn);
    Product(string n, double fCost, double pPrice, int qQuantity, int sSupplier, long long int uUPC, int activeLevel, pqxx::connection &conn);
    
    void getProductName();
    void getProductPrice();
    void SaveToInventoryFile(Product &product);
    void ConvertInventoryFileToCSVFormat();
    
    
    void GenerateProductListFromFile(string filename);
    
    
    
};


#endif
