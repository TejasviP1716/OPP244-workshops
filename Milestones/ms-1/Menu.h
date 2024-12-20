/**************************************************

  Name- Tejasvi Nitinkumar Parmar
 
  section- ZAA
  Date- 16/11/2024

***************************************************/




#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"

namespace seneca {
    class MenuItem {
        char* m_itemText{};
        unsigned m_spaces{};
        unsigned m_spaceWidth{};
        int m_itemNumber{};

    public:
        MenuItem(const char* text, unsigned spaces, unsigned width, int number);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}
#endif // !SENECA_MENU_H
