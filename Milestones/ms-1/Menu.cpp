/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  
  section- ZAA
  Date- 16/11/2024

***************************************************/




#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    MenuItem::MenuItem(const char* text, unsigned spaces, unsigned width, int number) {
        bool isValid = true;

        if (!text || ut.isspace(text)) {
            isValid = false;
        }

        if (spaces > 4 || width > 4 ||
            (number >= 0 && static_cast<size_t>(number) > MaximumNumberOfMenuItems)) {
            isValid = false;
        }

        if (isValid) {
            m_itemText = ut.alocpy(text);
            m_spaces = spaces;
            m_spaceWidth = width;
            m_itemNumber = number;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_itemText;
    }

    MenuItem::operator bool() const {
        return m_itemText != nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (!*this) {
            ostr << "??????????";
        }
        else {
            for (unsigned i = 0; i < m_spaces * m_spaceWidth; i++) {
                ostr << " ";
            }

            if (m_itemNumber >= 0) {
                ostr << setw(2) << m_itemNumber << "- ";
            }

            const char* text = m_itemText;
            while (text && ut.isspace(*text)) {
                text++;
            }
            if (text) {
                ostr << text;
            }
        }
        return ostr;
    }
}
