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
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
#include <fstream>  
#include "Utils.h"

namespace seneca {
	class Billable {
	public:

		Billable();
		virtual ~Billable();

		Billable(const Billable& B);
		Billable& operator=(const Billable&);

		virtual double price() const;


		virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
		virtual bool order() = 0;
		virtual bool ordered() const = 0;
		virtual std::ifstream& read(std::ifstream& file) = 0;
		operator const char* () const;
	protected:

		char* m_name;
		double m_price;
		void price(double value);
		void name(const char* name);
		void setPrice(double value) { m_price = value; }
	};

	double operator+(double money, const Billable& B);
	double& operator+=(double& money, const Billable& B);

}

#endif // !SENECA_BILLABLE_H
