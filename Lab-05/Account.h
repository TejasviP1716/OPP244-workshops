/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 11/10/2024

***************************************************/

#pragma once
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();

    public:

        Account();
        Account(int number, double balance);

        operator bool() const;
        operator double() const;
        operator int() const;



        bool operator~() const;

        Account& operator=(int digit);
        Account& operator+=(double value);
        Account& operator-=(double value);
        Account& operator=(Account& rest);
        Account& operator<<(Account& rest);
        Account& operator>>(Account& rest);

        std::ostream& display()const;

        friend double operator+(const Account& firstAccount, const Account& secondAccount);
        friend double operator+=(double& totalAmount, const Account& account);

    };


}
#endif // SENECA_ACCOUNT_H_