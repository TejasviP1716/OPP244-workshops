/*/*
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
