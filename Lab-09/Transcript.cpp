/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.coo
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Tejasvi Parmar           Date  29/11/24          Reason ZAA
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {
    // Constructor
    Transcript::Transcript(const char* name, size_t studentNumber)
        : m_studentName(nullptr), m_studentNumber(studentNumber) {
        ut.alocpy(m_studentName, name); 
    }

    // Copy Constructor
    Transcript::Transcript(const Transcript& other)
        : Marks(other), m_studentNumber(other.m_studentNumber) {
        ut.alocpy(m_studentName, other.m_studentName); 
    }

    // Assignment Operator
    Transcript& Transcript::operator=(const Transcript& other) {
        if (this != &other) { 
            Marks::operator=(other);                
            m_studentNumber = other.m_studentNumber;
            ut.alocpy(m_studentName, other.m_studentName); 
        }
        return *this;
    }

    // Destructor
    Transcript::~Transcript() {
        delete[] m_studentName; 
    }

   
    std::ostream& Transcript::display(std::ostream& ostr) const {
        ostr << m_studentName << " (" << m_studentNumber << ")\n";
        ostr << "--------------------------------------------------------------------------\n";
        Marks::display(ostr); 
        return ostr;
    }

}