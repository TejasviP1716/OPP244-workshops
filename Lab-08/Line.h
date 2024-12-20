/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/


#pragma once
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"
using namespace std;
namespace seneca {

    class Line : public LblShape {
        // Length of the line
        int m_length;

    public:
        // Default constructor
        Line();

        // Constructor that initializes label and length
        Line(const char* label, int length);

        // Draws the line, using the label and length
        void draw(ostream& os) const override;

        // Gets specifications of the line (label and length) from input
        void getSpecs(istream& is) override;
    };

}

#endif // !SENECA_LINE_H
