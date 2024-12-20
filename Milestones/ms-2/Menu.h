/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  
  section- ZAA
  Date- 21/11/2024

***************************************************/


#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"

namespace seneca {
    class Menu; 

    class MenuItem {
        friend class Menu;
        char* m_content;
        unsigned m_indentSize;
        unsigned m_indent;
        unsigned m_row;

        MenuItem(const char* content, unsigned indent, unsigned indentSize, unsigned row);
        // Prevent copying by making private
        MenuItem(const MenuItem&);
        MenuItem& operator=(const MenuItem&);
        ~MenuItem();
        std::ostream& display(std::ostream& os) const;
    };

    class Menu {
        unsigned m_indentNum;
        unsigned m_indentSize;
        unsigned m_numItems;
        MenuItem* m_menuItems[MaximumNumberOfMenuItems];
        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_selectionPrompt;

    public:
        Menu(const char* title, const char* exit = "Exit",
            unsigned indent = 0, unsigned indentSize = 3);

        // Prevent copying by making private
        Menu(const Menu&);
        Menu& operator=(const Menu&);
        ~Menu();

        Menu& operator<<(const char* content);
        size_t select() const;
    };

 
    size_t operator<<(std::ostream& os, const Menu& menu);
}
#endif // !SENECA_MENU_H
