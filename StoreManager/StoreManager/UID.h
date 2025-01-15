#pragma once
#ifndef UID_h
#define UID_h
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include <iostream>
#include <string>

using namespace std;

class UID {
public:
    virtual string operator()(int length, string offSetName, bool justInteger) {
        string myUID = "";
        int hashValue = hashFunction(offSetName);
        
        if(justInteger) {
            for(int i = 0; i < length; i++) {
                int randomValue = rand() % 10;
                myUID += to_string(randomValue);
            }
        } else {
            for(int i = 0; i < length; i++) {
                int randomIndex = (hashValue + i) % 62;
                myUID += chars[randomIndex];
            }
        }
        
       
        return myUID;
    }


    string genericId() {
        return "generic id";
    }

private:
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    int hashFunction(string str) {
        int hash = 0;
        for(char ch : str) {
            hash += static_cast<int>(ch);
        }
        return hash % 1000;
    }
};







#endif
