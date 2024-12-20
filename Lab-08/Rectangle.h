/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/




#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"
using namespace std;
namespace seneca {

    class Rectangle : public LblShape {
        // Width of the rectangle
        int m_width;
        // Height of the rectangle
        int m_height;
    public:
        // Default constructor
        Rectangle();

        // Constructor that initializes label, width, and height
        Rectangle(const char* label, int width, int height);

        // Draws the rectangle using the label, width, and height
        void draw(ostream& os) const override;

        // Gets specifications of the rectangle (label, width, height) from input
        void getSpecs(istream& is) override;
    };

}

#endif // !SENECA_RECTANGLE_H
