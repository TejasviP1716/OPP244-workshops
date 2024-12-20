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



#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"
#include <iostream>
#include <fstream>

namespace seneca {
	class Drink : public Billable {
		char m_size;
	public:
		Drink(const char* name = "", double price = 0.0, char size = '\0');
		std::ostream& print(std::ostream& ostr = std::cout) const override;
		bool order() override;
		bool ordered() const override;
		std::ifstream& read(std::ifstream& file) override;
		double price() const override;
	};
}
#endif //