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

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"
#include "Utils.h"
#include <iomanip>
#include <cstring>

namespace seneca {
	class Food : public Billable {
		bool m_ordered;
		bool m_child;
		char* m_customize;
	public:
		Food();
		~Food();
		Food(const Food& F);
		Food& operator=(const Food& F);
		std::ostream& print(std::ostream& ostr = std::cout) const override;
		bool order() override;
		bool ordered() const override;
		std::ifstream& read(std::ifstream& file) override;
		double price() const override;
	};
}
#endif // !SENECA_FOOD