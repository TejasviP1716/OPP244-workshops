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
#define _CRT_SECURE_NO_WARNINGS

#include "Drink.h"
#include "Food.h"
#include "Billable.h"
#include "Menu.h"
#include "Ordering.h"
#include "constants.h"
#include "Utils.h"
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

namespace seneca {

	Ordering::Ordering(const char* drinksFile, const char* foodsFile)
		: m_FoodCounter(0), m_DrinkCounter(0), m_BillableCounter(0), m_BillSerialNumber(1),
		m_FoodArr(nullptr), m_DrinkArr(nullptr), m_BillItems(nullptr) {

		size_t numDrinks = countRecords(drinksFile);
		size_t numFoods = countRecords(foodsFile);
		m_DrinkArr = new Drink[numDrinks];
		m_FoodArr = new Food[numFoods];
		m_BillItems = new Billable * [MaximumNumberOfBillItems]();

		std::ifstream drinksStream(drinksFile);
		std::ifstream foodsStream(foodsFile);

		if (drinksStream) {
			std::string line;
			size_t index = 0;

			while (std::getline(drinksStream, line) && index < numDrinks) {
				size_t commaPos = line.find(',');  // Find the comma separating the name and price
				if (commaPos != std::string::npos) {
					std::string drinkName = line.substr(0, commaPos);         // Extract the drink name
					double price = std::stod(line.substr(commaPos + 1));      // Convert the price to double

					m_DrinkArr[index] = Drink(drinkName.c_str(), price);      // Initialize with constructor
					index++;
					m_DrinkCounter++;
				}
				else {
					std::cerr << "Bad data in drinks file: " << line << std::endl;
				}
			}
		}
		

		if (foodsStream) {
			for (size_t i = 0; i < numFoods; ++i) {
				if (!m_FoodArr[i].read(foodsStream)) {
					break;
				}
				m_FoodCounter++;
			}
		}

		drinksStream.close();
		foodsStream.close();

		if (m_DrinkCounter != numDrinks) {
			delete[] m_DrinkArr;
			m_DrinkArr = nullptr;
		}

		if (m_FoodCounter != numFoods) {
			delete[] m_FoodArr;
			m_FoodArr = nullptr;
		}
	}

	Ordering::~Ordering() {
		delete[] m_FoodArr;
		delete[] m_DrinkArr;

		for (unsigned int i = 0; i < m_BillableCounter; i++) {
			delete m_BillItems[i];
		}
		delete[] m_BillItems;
	}

	unsigned int Ordering::getBillSerialNumber() const {
		return m_BillSerialNumber;
	}

	Ordering::operator bool() const {
		return m_FoodArr != nullptr && m_DrinkArr != nullptr && m_FoodCounter > 0 && m_DrinkCounter > 0;
	}

	unsigned int Ordering::noOfBillItems() const {
		return m_BillableCounter;
	}

	bool Ordering::hasUnsavedBill() const {
		return m_BillableCounter > 0;
	}

	void Ordering::listFoods(std::ostream&) const {
		std::cout << "List Of Avaiable Meals" << std::endl;
		std::cout << "========================================" << std::endl;

		for (unsigned int i = 0; i < m_FoodCounter; i++) {
			m_FoodArr[i].print();
			std::cout << std::endl;
		}

		std::cout << "========================================" << std::endl;
	}

	void Ordering::listDrinks(std::ostream&) const {
		std::cout << "List Of Avaiable Drinks" << std::endl;
		std::cout << "========================================" << std::endl;

		for (unsigned int i = 0; i < m_DrinkCounter; i++) {
			m_DrinkArr[i].print();
			std::cout << std::endl;
		}

		std::cout << "========================================" << std::endl;
	}

	void Ordering::orderFood() {
		Menu foodMenu("Food Menu", "Back to Order", 2);

		for (unsigned int i = 0; i < m_FoodCounter; ++i) {
			foodMenu << (const char*)m_FoodArr[i];
		}

		size_t selection = foodMenu.select();
		if (selection != 0) {
			--selection;
			Billable* selectedFood = new Food(m_FoodArr[selection]);
			if (selectedFood->order()) {
				m_BillItems[m_BillableCounter++] = selectedFood;
			}
			else {
				delete selectedFood;
			}
		}
	}

	void Ordering::orderDrink() {
		Menu drinkMenu("Drink Menu", "Back to Order", 2);

		for (unsigned int i = 0; i < m_DrinkCounter; ++i) {
			drinkMenu << (const char*)m_DrinkArr[i];
		}

		size_t selection = drinkMenu.select();
		if (selection != 0) {
			--selection;
			Billable* selectedDrink = new Drink(m_DrinkArr[selection]);

			if (selectedDrink->order()) {
				m_BillItems[m_BillableCounter++] = selectedDrink;
			}
			else {
				delete selectedDrink;
			}
		}
	}

	void Ordering::printBill(std::ostream& ostr) const {
		double total = 0.0;

		ostr << "Bill # " << std::setw(3) << std::setfill('0') << m_BillSerialNumber << " =============================\n";

		for (unsigned int i = 0; i < m_BillableCounter; ++i) {
			if (m_BillItems[i]) {
				m_BillItems[i]->print(ostr);
				ostr << '\n';
				total += m_BillItems[i]->price();
			}
		}

		printTotals(ostr, total);
	}

	void Ordering::resetBill() {
		char fileName[256];
		ut.makeBillFileName(fileName, m_BillSerialNumber);

		std::ofstream billFile(fileName);

		if (billFile.is_open()) {
			printBill(billFile);
			billFile.close();

			std::cout << "Saved bill number " << m_BillSerialNumber << std::endl;
			std::cout << "Starting bill number " << (m_BillSerialNumber + 1) << std::endl;
		}

		for (unsigned int i = 0; i < m_BillableCounter; ++i) {
			delete m_BillItems[i];
			m_BillItems[i] = nullptr;
		}

		m_BillableCounter = 0;
		++m_BillSerialNumber;
	}

	void Ordering::printTotals(std::ostream& ostr, double total) const {
		const double tax = total * Tax;
		ostr << "                     Total:" << std::setw(13) << std::setfill(' ') << total << '\n'
			<< "                     Tax:" << std::setw(15) << std::setfill(' ') << tax << '\n'
			<< "                     Total+Tax:" << std::setw(9) << std::setfill(' ') << (total + tax) << '\n'
			<< "========================================\n";
	}

	size_t Ordering::countRecords(const char* filen) const {
		std::ifstream file(filen);
		size_t records = 0;
		char ch;
		while (file.get(ch)) {
			if (ch == '\n') {
				records++;
			}
		}
		return records;
	}

}
