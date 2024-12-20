/**************************************************

  Name- Tejasvi Nitinkumar Parmar

  section- ZAA
  Date- 22/11/2024

***************************************************/

#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"
#include "LblShape.h"
#include <cstring>

using namespace std;
namespace seneca {
    Rectangle::Rectangle() : m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, int width, int height)
        : LblShape(label), m_width(width), m_height(height) {
        if (m_height < 3) m_height = 3;
        if (m_width < static_cast<int>(strlen(label)) + 2) m_width = static_cast<int>(strlen(label)) + 2;
    }

    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
    }

    void Rectangle::draw(ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << '+' << string(m_width - 2, '-') << '+' << endl;
            os << '|';
            os << label();
            os << string(m_width - 2 - strlen(label()), ' ');
            os << '|' << endl;
            for (int i = 0; i < static_cast<int>(m_height) - 3; ++i) {
                os << '|';
                os << string(m_width - 2, ' ');
                os << '|' << endl;
            }
            os << '+' << string(m_width - 2, '-') << '+';
        }
    }

}
