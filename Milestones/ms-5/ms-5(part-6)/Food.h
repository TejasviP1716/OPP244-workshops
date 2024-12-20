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
#endif // !SENECA_FOOD_H


