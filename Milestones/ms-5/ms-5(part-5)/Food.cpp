/*
*****************************************************************************
<Milestone - #5>
	
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Food.h"
#include <cstring>
#include <iomanip>
#include "Utils.h"
using namespace std;
namespace seneca {
	Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {
	}
	Food::~Food() {
		delete[] m_customize;
		m_customize = nullptr;
	}
	Food::Food(const Food& F) : Billable(F), m_ordered(F.m_ordered), m_child(F.m_child) {
		if (F.m_customize) {
			m_customize = new char[std::strlen(F.m_customize) + 1];
			std::strcpy(m_customize, F.m_customize);
		}
		else {
			m_customize = nullptr;
		}
	}
	Food& Food::operator=(const Food& F) {
		if (this != &F) {
			Billable::operator=(F);

			m_ordered = F.m_ordered;
			m_child = F.m_child;


			delete[] m_customize;
			if (F.m_customize) {
				m_customize = new char[std::strlen(F.m_customize) + 1];
				std::strcpy(m_customize, F.m_customize);
			}
			else {
				m_customize = nullptr;
			}
		}
		return *this;
	}

	std::ostream& Food::print(std::ostream& ostr) const {

		ostr << std::left << std::setw(28) << std::setfill('.') << (const char*)(*this);

		if (ordered()) {
			ostr << (m_child ? "Child" : "Adult");
		}
		else {
			ostr << ".....";
		}

		ostr << std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();

		if (&ostr == &std::cout && m_customize && std::strlen(m_customize) > 0) {
			ostr << " >> ";

			ostr.write(m_customize, std::min((size_t)30, std::strlen(m_customize)));
		}

		return ostr;
	}

	bool Food::order() {
		int selection = -1;

		std::cout << "         Food Size Selection\n"
			<< "          1- Adult\n"
			<< "          2- Child\n"
			<< "          0- Back\n"
			<< "         > ";
		std::cin >> selection;
		std::cin.ignore(1000, '\n');

		switch (selection) {
		case 1:
			m_child = false;
			m_ordered = true;
			break;
		case 2:
			m_child = true;
			m_ordered = true;
			break;
		case 0:
			m_ordered = false;
			delete[] m_customize;
			m_customize = nullptr;
			return false;
		default:
			std::cout << "Invalid selection. Please try again.\n";
			return false;
		}
		std::cout << "Special instructions\n> ";
		char temp[256];
		std::cin.getline(temp, 256);
		delete[] m_customize;
		m_customize = new char[strlen(temp) + 1];
		strcpy(m_customize, temp);

		return true;
	}
	bool Food::ordered()const {
		return m_ordered;
	}

	std::ifstream& Food::read(std::ifstream& file) {
		char name[100];
		double price;


		file.getline(name, 100, ',');
		file >> price;
		file.ignore(1000, '\n');
		if (file) {

			Billable::name(name);
			Billable::price(price);

			m_child = false;
			m_ordered = false;
			delete[] m_customize;
			m_customize = nullptr;
		}

		return file;
	}

	double Food::price()const {

		if (m_ordered && m_child) {
			return Billable::price() * 0.5;
		}

		return Billable::price();
	}
}


