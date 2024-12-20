/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/

#include "Shape.h"
using namespace std;
namespace seneca {
    ostream& operator<<(ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }

    istream& operator>>(istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}