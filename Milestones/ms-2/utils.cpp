/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 21/11/2024

***************************************************/

#include <iostream>
#include <limits>
#include "Utils.h"

using namespace std;

namespace seneca {
    int getInt() {
        int value;
        bool valid = false;
        
        while (!valid) {
            if (cin.peek() == '\n') {
                cin.ignore();
                cout << "You must enter a value: ";
                continue;
            }
            
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid integer: ";
                continue;
            }
            
            if (cin.get() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Only an integer please: ";
                continue;
            }
            
            valid = true;
        }
        
        return value;
    }

    int getInt(int min, int max) {
        int value;
        bool valid = false;
        
        while (!valid) {
            value = getInt();
            
            if (value < min || value > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
                continue;
            }
            
            valid = true;
        }
        
        return value;
    }
}
