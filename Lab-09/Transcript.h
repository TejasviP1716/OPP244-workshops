/***********************************************************************
// OOP244 Workshop 3 lab: tester program
//
// File	Transcript.h
// Version 1.0
// Date	2024/09/27
// Author Tushar Awal
// Description:
// I declare this submission is the result of my own work and has not been
// shared with any other student or 3rd party content provider. This submitted
// piece of work is entirely of my own creation.
//
// Revision History
// -----------------------------------------------------------
// Name Tejasvi Parmar           Date  29/11/24          Reason ZAA
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H

#include <iostream>
#include "Marks.h"

namespace seneca {
    class Transcript : public Marks {
        char* m_studentName{};    
        size_t m_studentNumber{}; 

    public:
        // Constructor
        Transcript(const char* name, size_t studentNumber);

        // Rule of Three
        Transcript(const Transcript& other);           
        Transcript& operator=(const Transcript& other); 
        ~Transcript();                                  

        // Overridden display method
        std::ostream& display(std::ostream& ostr = std::cout) const override;
    };
}
#endif // !SENECA_TRANSCRIPT_H
