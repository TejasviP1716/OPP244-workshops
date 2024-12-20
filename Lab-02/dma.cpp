/***************************************
Name - Tejasvi Parmar

section - ZAA

******************************************/

#include <iostream>
#include "dma.h"

using namespace std;
namespace seneca
{

    void reverse() 
    {
        int size;
        cout << "Enter the number of double values:\n";
        cout << "> ";
        cin >> size;

        double* values = new double[size];   // array of doubles allocate dynamically.....

        // Get the input values from here
        for (int i = 0; i < size; i++) 
        {
            cout << (i + 1) << "> ";
            cin >> values[i];
        }
      
        for (int i = size - 1; i >= 0; i--)  //values will be printing in  reverse order
        {
            cout << values[i] << endl;
        }

        delete[] values;  // dynamically allocated array
    }

    Contact* getContact()
    {

        Contact* newContact = new Contact;

        cout << "Name: ";
        cin >> newContact->m_name;
        cout << "Last name: ";
        cin >> newContact->m_lastname;
        cout << "Phone number: ";
        cin >> newContact->m_phoneNumber;

        return newContact;
    }

    void display(const Contact& C) 
    {
        cout << C.m_name << " " << C.m_lastname << ", +" << C.m_phoneNumber << endl;
    }

    void deallocate(Contact* C) 
    {

        delete C;
    }

    void setEmpty(Contact& C) 
    {

        C.m_name[0] = '\0';
        C.m_lastname[0] = '\0';
        C.m_phoneNumber = 0;
    }

}

