/***********************************************************************
// OOP244 ms3
//
// File	Employee.cpp
// Version 1.0
// Date	2024/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  Tejasvi Parmar          Date 30/11/24           Reason ZAA
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {
	class Menu;
	class MenuItem {
		friend class Menu;
		friend size_t operator<<(std::ostream& ostr, const Menu& m);
	private:
		char* m_content;
		unsigned m_indentations_numb;
		unsigned m_indentations_ch;
		int m_item_obj;
		void safeEmptyState();
		MenuItem(const char* content, unsigned indentations_numb, unsigned indentations_ch, int item_obj);
		~MenuItem();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		operator bool() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};

	class Menu {
	private:
		unsigned m_indent;
		unsigned m_indentSize;
		unsigned m_numItems;
		MenuItem m_title;
		MenuItem m_exitOption;
		MenuItem m_entryPrompt;
		MenuItem* m_items[MaximumNumberOfMenuItems];

	public:
		Menu(const char* title, const char* exitOption = "Exit", unsigned indent = 0, unsigned indentSize = 3);
		~Menu();
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
		Menu(Menu&&) = delete;
		Menu& operator=(Menu&&) = delete;
		Menu& operator<<(const char* content);
		size_t select() const;
		friend size_t operator<<(std::ostream& ostr, const Menu& m);
	};
}
#endif // !SENECA_MENU_H