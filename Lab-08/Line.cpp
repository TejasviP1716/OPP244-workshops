/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/
#include <iomanip>
#include "Line.h"
#include "Utils.h"
#include<cstring>
using namespace std;
namespace seneca {

    Line::Line() : m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {
        if (m_length < static_cast<int>(strlen(label))) {
            m_length = static_cast<int>(strlen(label));
        }
    }

    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }

    void Line::draw(ostream& os) const {
        if (m_length > 0 && label()) {
            os << label() << endl;
            os.fill('=');
            os.width(m_length);
            os << "=";
        }
    }
}
