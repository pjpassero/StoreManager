/*
 * Philip J. Passero IV
 * UID.h
 *
 * UID Class declaration file. Defines and implements the UID (unique id) class.
 *
 */

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

    /*
     * Overload the function operator.
     * @param length: define the length of the UID
     * @param offsetName: the value that is being passed through to generate the UID
     * @param justInteger: if flag is set, just an integer string will be returned, no letters
     * @return string: the UID in std::string format
     *
     */
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

    /*
     * @return: generic id used to fill UID field until actual UID can be generated.
     */

    string genericId() {
        return "generic id";
    }

private:
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";


    /*
     * @param str: string that will be used to hash
     * @return: a number that corresponds to an index in the chars string that can be used to generate a UID
     */
    int hashFunction(string str) {
        int hash = 0;
        for(char ch : str) {
            hash += static_cast<int>(ch);
        }
        return hash % 1000;
    }
};







#endif
