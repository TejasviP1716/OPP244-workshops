/**************************************************

  Name- Tejasvi Nitinkumar Parmar
 
  section- ZAA
  Date- 11/10/2024

***************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }


    Account::Account(int accountNumber, double accountBalance) {
        setEmpty();
        if (accountNumber >= 10000 && accountNumber <= 99999 && accountBalance > 0) {
            m_number = accountNumber;
            m_balance = accountBalance;
        }
        else {
            m_number = -1;
            m_balance = 0.0;
        }
    }




    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }


    Account::operator bool() const {
        return m_number != -1 && m_number != 0;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }


    bool Account::operator~() const {
        return (m_number == 0);
    }

    Account& Account::operator=(int accountNumber) {
        if (m_number == 0) {
            if (accountNumber >= 10000 && accountNumber <= 99999) {
                m_number = accountNumber;
            }
            else {
                m_number = -1;
                m_balance = 0.0;
            }

        }
        return *this;
    }

    Account& Account::operator=(Account& otherAccount) {
        if (m_number == 0 && otherAccount.m_number != -1) {
            m_number = otherAccount.m_number;
            m_balance = otherAccount.m_balance;
            otherAccount.m_number = 0;
            otherAccount.m_balance = 0.0;
        }
        return *this;
    }


    Account& Account::operator+=(double value) {
        if (m_number != -1 && value > 0) {
            m_balance += value;
        }
        return *this;
    }


    Account& Account:: operator-=(double value) {
        if (m_number != -1 && value > 0 && m_balance >= value) {
            m_balance -= value;
        }
        return *this;
    }


    Account& Account::operator<<(Account& otherAccount) {
        if (m_number != -1 && otherAccount.m_number != -1 && &otherAccount != this) {
            m_balance = otherAccount.m_balance;
            otherAccount.m_balance = 0.0;
        }
        return *this;
    }


    Account& Account::operator>>(Account& otherAccount) {
        if (m_number != -1 && otherAccount.m_number != -1 && &otherAccount != this) {
            otherAccount.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }


    double operator+(const Account& firstAccount, const Account& secondAccount) {
        if (firstAccount.m_number == -1 || secondAccount.m_number == -1) {
            return 0.0;
        }
        else {
            return firstAccount.m_balance + secondAccount.m_balance;
        }
    }


    double operator+=(double& totalAmount, const Account& account) {
        if (account.m_number != -1) {
            totalAmount += account.m_balance;
        }
        return totalAmount;
    }

}
