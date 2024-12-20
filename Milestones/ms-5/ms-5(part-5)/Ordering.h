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
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include "Utils.h"
#include <iostream>
namespace seneca {
	class Ordering {
	private:
		unsigned int m_FoodCounter;
		unsigned int m_DrinkCounter;
		unsigned int m_BillableCounter;
		unsigned int m_BillSerialNumber;
		Food* m_FoodArr;
		Drink* m_DrinkArr;
		Billable** m_BillItems;
		void printBillTile(std::ostream& ostr) const;
		void printTotals(std::ostream& ostr, double total) const;
		size_t countRecords(const char* file) const;
	public:
		Ordering(const char* drinkFile, const char* foodFile);
		~Ordering();
		unsigned int getBillSerialNumber() const;
		operator bool() const;
		unsigned int noOfBillItems() const;
		bool hasUnsavedBill()const;
		void listFoods(std::ostream& ostr = std::cout) const;
		void listDrinks(std::ostream& ostr = std::cout) const;
		void orderFood();
		void orderDrink();
		void printBill(std::ostream& ostr) const;
		void resetBill();
	};
}
#endif // !SENECA_ORDERING_H


