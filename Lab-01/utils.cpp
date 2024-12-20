/***************************************
Name - Tejasvi Parmar
student id - 151236239
email - tnparmar2@myseneca.ca
section - ZAA

******************************************/



#include <iostream>
#include "utils.h"
namespace seneca 
{
    using namespace std;
    // flushes the keyboard
    void flushkeys() 
    {
        while (cin.get() != '\n');
    }

    // returns true if user enter y or Y
    bool yes() {
        char ch = cin.get();
        flushkeys();
        return ch == 'y' || ch == 'Y';
    }

    // copies src Cstring to des and converts all characters to lowercase
    // at the same time.
    void toLowerCase(char* des, const char* src) 
    {
        int i = 0;
        while (src[i]) {
            des[i] = src[i];
            if (des[i] >= 'A' && des[i] <= 'Z') 
            {
                des[i] += ('a' - 'A');
            }
            i++;
        }
        des[i] = 0;
    }
}