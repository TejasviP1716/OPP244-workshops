/*

*****************************************************************************
<Milestone - #4>
	Full Name : Tejasvi Parmar
	Student ID# :

Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
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

#endif // SENECA_DRINK_H
