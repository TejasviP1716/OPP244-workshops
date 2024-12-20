/***********************************************************************
// OOP244 Project, Menu Module
//
// File	Menu.cpp
// Version 1.1
// Date 2024-9-11
// started by Fardad
// Description
// Implementation of Menu and MenuItem classes
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Nikan Eidi
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>     // For strlen and strcpy
#include <cctype>      // For std::isspace
#include "Utils.h"
#include "Menu.h"


namespace seneca {

	// Private helper function to set the object to a safe empty state
	void MenuItem::safeEmptyState() {
		m_content = nullptr;
		m_indentations_numb = 0;
		m_indentations_ch = 0;
		m_item_obj = -1;
	}

	// Constructor with validation for content, indentation, and row number
	MenuItem::MenuItem(const char* content, unsigned indentations_numb, unsigned indentations_ch, int item_obj) {
		if (content == nullptr || *content == '\0' || indentations_numb > 4 || indentations_ch > 4 ||
			(item_obj > static_cast<int>(MaximumNumberOfMenuItems) && item_obj != -1)) {
			safeEmptyState();  // Invalid parameters, set to safe empty state
		}
		else {
			const char* ptr = content;
			while (*ptr != '\0' && std::isspace(*ptr)) {
				++ptr;
			}

			if (*ptr == '\0') { // Content is only whitespace
				safeEmptyState();
			}
			else {
				// Allocate memory and copy content
				m_content = new char[strlen(content) + 1];
				strcpy(m_content, content);
				m_indentations_numb = indentations_numb;
				m_indentations_ch = indentations_ch;
				m_item_obj = item_obj;
			}
		}
	}

	// Destructor to release dynamically allocated memory
	MenuItem::~MenuItem() {
		delete[] m_content;
	}

	// Bool conversion operator to check if the MenuItem is in a valid state
	MenuItem::operator bool() const {
		return m_content != nullptr;
	}

	// Display function to output the formatted content
	std::ostream& MenuItem::display(std::ostream& ostr) const {
		if (!*this) {
			return ostr; // Do nothing for invalid items
		}
		for (unsigned i = 0; i < m_indentations_numb * m_indentations_ch; ++i) {
			ostr << ' '; // Add indentation
		}
		// Display row number if valid
		if (m_item_obj >= 0) {
			// Align single-digit numbers
			if (m_item_obj < 10) ostr << ' ';
			ostr << m_item_obj << "- ";
		}
		const char* ptr = m_content;
		while (std::isspace(*ptr)) ++ptr; // Skip leading whitespace
		ostr << ptr;
		return ostr;
	}

	// Menu constructor
	Menu::Menu(const char* title, const char* exitOption, unsigned indent, unsigned indentSize)
		: m_indent(indent),
		m_indentSize(indentSize),
		m_numItems(0),
		m_title(title, indent, indentSize, -1),
		m_exitOption(exitOption, indent, indentSize, 0),
		m_entryPrompt("> ", indent, indentSize, -1) {
		for (unsigned i = 0; i < MaximumNumberOfMenuItems; ++i) {
			m_items[i] = nullptr;
		}
	}

	// Menu destructor
	Menu::~Menu() {
		for (unsigned i = 0; i < m_numItems; ++i) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
	}

	// << Operator Overload for Menu
	Menu& Menu::operator<<(const char* content) {
		if (m_numItems < MaximumNumberOfMenuItems) {
			m_items[m_numItems] = new MenuItem(content, m_indent, m_indentSize, m_numItems + 1);
			++m_numItems;
		}
		return *this;
	}

	// Select Method
	size_t Menu::select() const {
		if (m_title) { // Check if title is valid
			m_title.display(std::cout);
			std::cout << std::endl;
		}

		// Display menu items
		for (unsigned i = 0; i < m_numItems; ++i) {
			if (m_items[i]) {
				m_items[i]->display(std::cout);
				std::cout << std::endl;
			}
		}

		// Display exit option
		m_exitOption.display(std::cout);
		std::cout << std::endl;

		// Display the selection prompt
		m_entryPrompt.display(std::cout);

		// Get and return the validated selection
		int selection = ut.getInt(0, m_numItems);
		return static_cast<size_t>(selection);
	}

	// Insertion Operator Overload f
	size_t operator<<(std::ostream& ostr, const Menu& m) {
		// If the stream is std::cout
		if (&ostr == &std::cout) {
			return m.select();
		}
		else {
			// Display the menu without 
			if (m.m_title) {
				m.m_title.display(ostr);
				ostr << std::endl;
			}

			for (unsigned i = 0; i < m.m_numItems; ++i) {
				if (m.m_items[i]) {
					m.m_items[i]->display(ostr);
					ostr << std::endl;
				}
			}

			if (m.m_exitOption) {
				m.m_exitOption.display(ostr);
				ostr << std::endl;
			}

			return 0; // Return 0 for non-std::cout streams
		}
	}

} // namespace seneca

