
/*
*****************************************************************************
<Milestone - #4>
	Full Name : Tejasvi Parmar
	Student ID# : 151236239

Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>     // For strlen and strcpy
#include <cctype>      // For std::isspace
#include "Utils.h"
#include "Menu.h"


namespace seneca {


	void MenuItem::safeEmptyState() {
		m_content = nullptr;
		m_indentations_numb = 0;
		m_indentations_ch = 0;
		m_item_obj = -1;
	}

	
	MenuItem::MenuItem(const char* content, unsigned indentations_numb, unsigned indentations_ch, int item_obj) {
		if (content == nullptr || *content == '\0' || indentations_numb > 4 || indentations_ch > 4 ||
			(item_obj > static_cast<int>(MaximumNumberOfMenuItems) && item_obj != -1)) {
			safeEmptyState();  
		}
		else {
			const char* ptr = content;
			while (*ptr != '\0' && std::isspace(*ptr)) {
				++ptr;
			}

			if (*ptr == '\0') { 
				safeEmptyState();
			}
			else {
				
				m_content = new char[strlen(content) + 1];
				strcpy(m_content, content);
				m_indentations_numb = indentations_numb;
				m_indentations_ch = indentations_ch;
				m_item_obj = item_obj;
			}
		}
	}

	
	MenuItem::~MenuItem() {
		delete[] m_content;
	}

	
	MenuItem::operator bool() const {
		return m_content != nullptr;
	}

	
	std::ostream& MenuItem::display(std::ostream& ostr) const {
		if (!*this) {
			return ostr; 
		}
		for (unsigned i = 0; i < m_indentations_numb * m_indentations_ch; ++i) {
			ostr << ' '; 
		}
		
		if (m_item_obj >= 0) {
			
			if (m_item_obj < 10) ostr << ' ';
			ostr << m_item_obj << "- ";
		}
		const char* ptr = m_content;
		while (std::isspace(*ptr)) ++ptr; 
		ostr << ptr;
		return ostr;
	}

	
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

	
	Menu::~Menu() {
		for (unsigned i = 0; i < m_numItems; ++i) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
	}

	
	Menu& Menu::operator<<(const char* content) {
		if (m_numItems < MaximumNumberOfMenuItems) {
			m_items[m_numItems] = new MenuItem(content, m_indent, m_indentSize, m_numItems + 1);
			++m_numItems;
		}
		return *this;
	}

	
	size_t Menu::select() const {
		if (m_title) { 
			m_title.display(std::cout);
			std::cout << std::endl;
		}

	
		for (unsigned i = 0; i < m_numItems; ++i) {
			if (m_items[i]) {
				m_items[i]->display(std::cout);
				std::cout << std::endl;
			}
		}

		
		m_exitOption.display(std::cout);
		std::cout << std::endl;

		
		m_entryPrompt.display(std::cout);

		
		int selection = ut.getInt(0, m_numItems);
		return static_cast<size_t>(selection);
	}

	
	size_t operator<<(std::ostream& ostr, const Menu& m) {
		
		if (&ostr == &std::cout) {
			return m.select();
		}
		else {
		
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

			return 0; 
		}
	}

} 
