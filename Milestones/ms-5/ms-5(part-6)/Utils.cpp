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

#include <iostream>
#include <climits>
#include "Utils.h"
#include <cstring>
#include <string>
using namespace std;
namespace seneca {
	Utils ut;
	bool debug = false;
	const size_t AllocationBlockSize = 128;
	// Calls getInt() with no range
	int Utils::getInt(int min, int max) const {
		int value;
		bool valid = false;

		do {
			cin >> value;

			if (cin.fail()) {
				cin.clear(); // Clear error state
				cin.ignore(1000, '\n'); // Ignore invalid input
				cout << "Invalid input. Please enter an integer: ";
			}
			else if (value < min || value > max) {
				cout << "Invalid range. Enter a value between " << min << " and " << max << ": ";
			}
			else {
				valid = true;
			}
		} while (!valid);

		return value;
	}

	// Calls getInt() with no range
	int Utils::getInt() const {
		return getInt(INT_MIN, INT_MAX);
	}

	// Reads input or uses a default value
	int Utils::getint(int defaultValue) const {
		string input;
		cin >> ws; // Skip whitespace
		getline(cin, input);

		if (input.empty()) {
			return defaultValue;
		}
		else {
			return stoi(input);
		}
	}
	char* Utils::alocpy(const char* src) const {
		char* des{};
		return alocpy(des, src);
	}

	char* Utils::alocpy(char*& des, const char* src)const {
		delete[] des;
		des = nullptr;
		if (src) {
			des = new char[strlen(src) + 1];
			strcpy(des, src);
		}
		return des;
	}


	char* Utils::strcpy(char* des, const char* src)const {
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = char(0);
		return des;
	}
	char* Utils::strcpy(char* des, const char* src, int len)const {
		int i;
		for (i = 0; i < len && src[i]; i++) des[i] = src[i];
		des[i] = 0; // unlike strncpy, this function null terminates the des cstring
		return des;
	}
	char* Utils::strncpy(char* des, const char* src, int len)const {
		int i = 0;
		while (i < len - 1 && src[i]) {
			des[i] = src[i];
			i++;
		}
		des[i] = src[i];
		return des;
	}
	char* Utils::makeBillFileName(char* filename, size_t billNo)const {
		char billFileName[21] = "bill_";
		size_t temp = billNo;
		int cnt = 5;
		int length;
		// Calculate the number of digits
		do {
			cnt++;
			temp /= 10;
		} while (temp > 0);
		length = cnt;
		// Convert each digit to character from the end
		while (billNo > 0) {
			billFileName[--cnt] = (billNo % 10) + '0';
			billNo /= 10;
		}
		// Handle the case when billNo is 0
		if (billFileName[cnt - 1] == '\0') {
			billFileName[--cnt] = '0';
		}
		// Attach .txt to the end of the file name
		for (int i = 0; ".txt"[i]; i++) {
			billFileName[length++] = ".txt"[i];
		}
		billFileName[length] = '\0';
		strcpy(filename, billFileName);
		return filename;
	}
	int Utils::strlen(const char* str)const {
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}

	// Dynamically reads a cstring from istream
	char* Utils::read(char*& toRet, istream& istr, char delimiter)const {
		bool done = false;
		char* cstr = new char[AllocationBlockSize];
		toRet = cstr;
		int size = AllocationBlockSize;
		int nullindex = 1;
		do {
			cin.getline(cstr, AllocationBlockSize, delimiter);
			if (cin.fail()) {
				char* temp = new char[size + AllocationBlockSize];
				strcpy(temp, toRet);
				delete[] toRet;
				toRet = temp;
				cstr = &toRet[size - nullindex++];
				size += AllocationBlockSize;
				cin.clear();
			}
			else {
				done = true;
			}
		} while (!done);
		char* temp = new char[strlen(toRet) + 1];
		strcpy(temp, toRet);
		delete[] toRet;
		toRet = temp;
		return toRet;
	}

	bool Utils::isspace(char ch)const {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
	}

	bool Utils::isspace(const char* cstring) const {
		while (cstring && isspace(*cstring)) {
			cstring++;
		}
		return cstring && *cstring == 0;
	}

}
