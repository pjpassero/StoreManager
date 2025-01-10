#pragma once
#include "UID.h"
#include "store.h"
#include <string>
#ifndef BalanceSheet_h
#define BalanceSheet_h

using namespace std;

class BalanceSheet {
    
private:
    Store store;
    double cashBalance;
    double inventoryBalance;
    int inventoryAmount;
    double stateTaxRate;
    
    
public:
    BalanceSheet();
    BalanceSheet(double initalFunds);
    void newSale(double amount, int quantity, string productUID);
    void lossOfProduct(string productUID, int quantity);
    void calculateProfitLossRatio();
    
};





#endif
