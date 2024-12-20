/***************************************
Name - Tejasvi Parmar
student id - 151236239
email - tnparmar2@myseneca.ca
section - ZAA

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include "cstr.h"
#include "CC.h"

using namespace std;

namespace seneca {

    void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const {
        char lname[31]{};
        strcpy(lname, name, 30);
        cout << "| ";
        cout.width(30);
        cout.fill(' ');
        cout.setf(ios::left);
        cout << lname << " | ";
        prnNumber(number);
        cout << " | " << cvv << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(2);
        cout << expMon << "/" << expYear << " |" << endl;
        cout.unsetf(ios::right);
    }

    bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
        return name != nullptr && seneca::strlen(name) > 2 &&
            cardNo >= 4000000000000000ull && cardNo <= 4099999999999999ull &&
            cvv >= 100 && cvv <= 999 &&
            expMon >= 1 && expMon <= 12 &&
            expYear >= 24 && expYear <= 32;
    }

    void CC::prnNumber(unsigned long long CCnum) const {

        std::string cardStr = std::to_string(CCnum);
        while (cardStr.length() < 16)
        {
            cardStr.insert(0, "0");
        }

        for (size_t i = 0; i < cardStr.length(); i += 4)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << cardStr.substr(i, 4);
        }
    }

    // Public Methods
    void CC::set() {
        m_name = nullptr;
        m_cardNo = 0;
        m_cvv = 0;
        m_expMon = 0;
        m_expYear = 0;
    }

    void CC::cleanUp() {
        freeMem(m_name);  // Use cstr freeMem function to deallocate memory
        set();            // Reset to safe empty state
    }

    bool CC::isEmpty() const {
        return m_name == nullptr;
    }

    void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear) {
        cleanUp();
        if (validate(cc_name, cc_no, m_cvv, m_expMon, m_expYear)) {
            alocpy(m_name, cc_name); // Dynamically allocate name using cstr's alocpy
            m_cardNo = cc_no;
            this->m_cvv = m_cvv;
            this->m_expMon = m_expMon;
            this->m_expYear = m_expYear;
        }
    }

    void CC::display() const {
        if (isEmpty()) {
            cout << "Invalid Credit Card Record" << endl;
        }
        else {
            display(m_name, m_cardNo, m_expYear, m_expMon, m_cvv);
        }
    }
    void CC::set(const char* cc_name, unsigned long long cc_no, short m_cvv) {
        set(cc_name, cc_no, m_cvv, 12, 24);
    }
}
