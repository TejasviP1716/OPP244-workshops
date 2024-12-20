/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.5
// Date 2024-11-13
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name  Tejasvi Parmar          Date 30/11/24           Reason ZAA
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Drink.h"
#include <iomanip>
#include <iostream>
#include <cstring>

namespace seneca {
	Drink::Drink(const char* name, double price, char size)
		: Billable() {
		Billable::name(name);
		Billable::price(price);
		if (size == 'S' || size == 'M' || size == 'L' || size == 'X') {
			m_size = size;
		}
		else {
			m_size = '\0';
		}
	}

	std::ostream& Drink::print(std::ostream& ostr) const {
		ostr << std::left << std::setw(28) << std::setfill('.') << (const char*)(*this);

		if (m_size == 'S') {
			ostr << "SML..";
		}
		else if (m_size == 'M') {
			ostr << "MID..";
		}
		else if (m_size == 'L') {
			ostr << "LRG..";
		}
		else if (m_size == 'X') {
			ostr << "XLR..";
		}
		else {
			ostr << ".....";
		}

		ostr << std::right << std::setw(7) << std::setfill(' ')
			<< std::fixed << std::setprecision(2) << price();

		return ostr;
	}

	bool Drink::order() {
		int selection = -1;
		std::cout << "         Drink Size Selection\n"
			<< "          1- Small\n"
			<< "          2- Medium\n"
			<< "          3- Larg\n"
			<< "          4- Extra Large\n"
			<< "          0- Back\n"
			<< "         > ";
		std::cin >> selection;

		switch (selection) {
		case 1: m_size = 'S'; return true;
		case 2: m_size = 'M'; return true;
		case 3: m_size = 'L'; return true;
		case 4: m_size = 'X'; return true;
		case 0:
		default: m_size = '\0'; return false;
		}
	}

	bool Drink::ordered() const {
		return m_size != '\0';
	}

	std::ifstream& Drink::read(std::ifstream& file) {
		char name[26];
		double price;
		std::string originalName = m_name ? std::string(m_name) : "";
		double originalPrice = Billable::price();
		char originalSize = m_size;
		file.getline(name, 26, ',');
		file >> price;
		file.ignore(1000, '\n');

		if (file) {
			Billable::name(name);
			Billable::price(price);
			m_size = '\0';
		}
		else {
			Billable::name(originalName.c_str());
			Billable::price(originalPrice);
			m_size = originalSize;
		}

		return file;
	}

	double Drink::price() const {
		if (!ordered() || m_size == 'L') {
			return Billable::price();
		}
		switch (m_size) {
		case 'S':
			return Billable::price() * 0.5;
		case 'M':
			return Billable::price() * 0.75;
		case 'X':
			return Billable::price() * 1.5;
		default:
			return Billable::price();
		}
	}
}