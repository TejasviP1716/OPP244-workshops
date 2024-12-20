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
#include <iostream>
#include "Menu.h"
#include "Food.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

void appDemo();

int main()
{
	//appDemo();
	const char* drinksFile = "drinks.csv";  // Ensure this file exists and has data
	const char* foodsFile = "foods.csv";    // Ensure this file exists and has data

	// Create an Ordering object with the sample files
	seneca::Ordering order(drinksFile, foodsFile);

	
	std::cout << "Testing Invalid Ordering if bad data is in data file!" << std::endl;
	if (order) {
		std::cout << "Passed!" << std::endl;
	}
	else {
		std::cout << "Failed to load data!" << std::endl;
	}

	
	std::cout << "Testing fool-proofing..." << std::endl;


	seneca::Menu drinkMenu("Drink Menu", "Back to Order", 2);

	
	drinkMenu << "Pepsi" << "Orange Juice" << "Coffee";

	
	size_t selection = drinkMenu.select();  



	return 0;
}


void appDemo() {
	size_t appSel{}, ordSel{};
	Menu appMenu("Seneca Restaurant ", "End Program");
	appMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
	Menu orderMenu("Order Menu", "Back to main menu", 1);
	orderMenu << "Food" << "Drink";
	Ordering ord("drinks.csv", "foods.csv");
	bool exit = false;
	do {
		switch (appSel = appMenu.select()) {
		case 1:
			do {
				switch (ordSel = orderMenu.select()) {
				case 1:
					ord.orderFood();
					break;
				case 2:
					ord.orderDrink();
					break;
				}
			} while (ordSel);
			break;
		case 2:
			ord.printBill(cout);
			break;
		case 3:
			ord.resetBill();
			break;
		case 4:
			ord.listFoods();
			break;
		case 5:
			ord.listDrinks();
			break;
		case 0:
			if (ord.hasUnsavedBill())
			{
				cout << "You have bills that are not saved, are you sue you want to exit?\n";
				cout << " 1- Yes\n";
				cout << " 0- No\n";
				cout << "> ";
				cin >> appSel;
				appSel == 1 ? exit = true : exit = false;
			}
			else {
				exit = true;
			}
			break;
		}
	} while (exit == false);
}