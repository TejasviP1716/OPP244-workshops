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
#define _CRT_SECURE_NO_WARNINGS
#include "Billable.h"
#include "Utils.h"
#include <cstring>

namespace seneca {
	Billable::Billable() : m_name(nullptr), m_price(0.0) {
	}

	Billable::~Billable() {
		delete[] m_name;
		m_name = nullptr;
	}

	Billable::Billable(const Billable& B) : m_name(nullptr), m_price(B.m_price) {
		ut.alocpy(m_name, B.m_name);
	}

	Billable& Billable::operator=(const Billable& B) {
		if (this != &B) {
			ut.alocpy(m_name, B.m_name);
			m_price = B.m_price;
		}
		return *this;
	}
	double Billable::price()const {
		return m_price;
	}
	double operator+(double money, const Billable& B) {
		return money + B.price();
	}

	double& operator+=(double& money, const Billable& B) {
		money += B.price();
		return money;
	}
	seneca::Billable::operator const char* () const {
		return m_name;
	}
	void Billable::price(double value) {
		if (value >= 0) {
			m_price = value;
		}
		else {
			m_price = 0.0;
		}
	}
	void Billable::name(const char* name) {
		delete[] m_name;
		if (name) {
			m_name = new char[std::strlen(name) + 1];
			std::strcpy(m_name, name);
		}
		else {
			m_name = nullptr;
		}
	}
}