/**************************************************

  Name- Tejasvi Nitinkumar Parmar
 
  section- ZAA
  Date- 21/11/2024

***************************************************/





#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include "constants.h"

using namespace std;

namespace seneca {
    MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSize, unsigned row) { //item implementatio
        m_content = nullptr;
        m_indent = indent;
        m_indentSize = indentSize;
        m_row = row;

        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
    }

    MenuItem& MenuItem::operator=(const MenuItem&)
    { 
        return*this;
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (m_content) {
        
            for (unsigned i = 0; i < m_indent * m_indentSize; i++) {
                os << " ";
            }

       
            if (m_row) {
                if (m_row >= 10) {
                    os << m_row << "- ";
                }
                else {
                    os << " " << m_row << "- ";  //space for single digits number
                }
            }

            os << m_content << endl;
        }
        return os;
    }


    Menu::Menu(const char* title, const char* exit, unsigned indent, unsigned indentSize)
        : m_title(title, indent, indentSize, 0)
        , m_exitOption(exit ? exit : "Exit", indent, indentSize, 0)
        , m_selectionPrompt("> ", indent, indentSize, 0) {
        m_indentNum = indent;
        m_indentSize = indentSize;
        m_numItems = 0;
        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++) {
            m_menuItems[i] = nullptr;
        }
    }

    

    Menu& Menu::operator=(const Menu&)
    {
        return*this;
    }

    Menu::~Menu() {
        for (unsigned i = 0; i < m_numItems; i++) {
            delete m_menuItems[i];
            m_menuItems[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* content) {
        if (m_numItems < MaximumNumberOfMenuItems && content) {
            m_menuItems[m_numItems] = new MenuItem(content, m_indentNum, m_indentSize, m_numItems + 1);
            m_numItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
     
        if (m_title.m_content) {
            m_title.display(cout);
        }

        for (unsigned i = 0; i < m_numItems; i++) {
            m_menuItems[i]->display(cout);
        }

        for (unsigned i = 0; i < m_indentNum * m_indentSize; i++) {
            cout << " ";
        }
        cout << " 0- " << m_exitOption.m_content << endl;

        for (unsigned i = 0; i < m_indentNum * m_indentSize; i++) {
            cout << " ";
        }
        cout << "> ";

        return static_cast<size_t>(getInt(0, m_numItems));
    }

    size_t operator<<(std::ostream& os, const Menu& menu) {
        if (&os == &std::cout) {
            return menu.select();
        }
        return 0;
    }
}
