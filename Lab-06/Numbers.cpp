/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 01/11/2024

***************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string> 
#include "Numbers.h"
using namespace std;
namespace seneca {


	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}

	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			delete[] m_numbers;
			delete[] m_filename;
			setEmpty();
			m_isOriginal = false;
		}
		else {
			sort();
		}
	}

	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}

	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}
	void Numbers::setFilename(const char* filename) {
		delete[] m_filename;
		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}
	void Numbers::sort() {
		int i, j;
		double temp;
		for (i = m_numCount - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (m_numbers[j] > m_numbers[j + 1]) {
					temp = m_numbers[j];
					m_numbers[j] = m_numbers[j + 1];
					m_numbers[j + 1] = temp;
				}
			}
		}
	}

	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}
	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}

	void Numbers::save() const {
		if (m_isOriginal && !isEmpty()) {
			std::ofstream file(m_filename);
			if (file) {
				for (int i = 0; i < m_numCount; ++i) {
					file << m_numbers[i] << std::endl;
				}
			}
		}
	}

	Numbers::Numbers(const Numbers& src) {
		setEmpty();
		m_isOriginal = false;

		if (!src.isEmpty()) {
			m_numCount = src.m_numCount;
			m_numbers = new double[m_numCount];
			for (int i = 0; i < m_numCount; ++i) {
				m_numbers[i] = src.m_numbers[i];
			}
		}
	}

	Numbers& Numbers::operator=(const Numbers& src) {
		if (this != &src) {
			delete[] m_numbers;

			m_numCount = src.m_numCount;
			if (src.m_numbers != nullptr) {
				m_numbers = new double[m_numCount];
				for (int i = 0; i < m_numCount; ++i) {
					m_numbers[i] = src.m_numbers[i];
				}
			}
			else {
				m_numbers = nullptr;
			}
		}
		return *this;
	}

	Numbers& Numbers::operator+=(double value) {
		if (!isEmpty()) {
			double* temp = new double[m_numCount + 1];


			for (int i = 0; i < m_numCount; ++i) {
				temp[i] = m_numbers[i];
			}


			temp[m_numCount] = value;
			++m_numCount;

			delete[] m_numbers;
			m_numbers = temp;
			sort();
		}
		return *this;
	}

	bool Numbers::load() {
		if (m_numCount > 0) {
			m_numbers = new double[m_numCount];
			std::ifstream file(m_filename);
			int i = 0;
			while (file && i < m_numCount) {
				file >> m_numbers[i++];
			}
			if (i != m_numCount) {
				delete[] m_numbers;
				setEmpty();
				return false;
			}
			return true;
		}
		return false;
	}

	int Numbers::numberCount() const {
		int count = 0;
		std::ifstream file(m_filename);
		std::string line;
		while (std::getline(file, line)) {
			count++;
		}
		return count;
	}

	std::ostream& operator<<(std::ostream& os, const Numbers& N) {
		return N.display(os);
	}

	std::istream& operator>>(std::istream& istr, Numbers& N) {
		double value;
		if (istr >> value) {
			N += value;
		}
		return istr;
	}

	std::ostream& Numbers::display(std::ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Empty list";
		}
		else {
			ostr.setf(std::ios::fixed);
			ostr.precision(2);

			ostr << "=========================" << std::endl;
			ostr << (m_isOriginal ? m_filename : "*** COPY ***") << std::endl;

			for (int i = 0; i < m_numCount; ++i) {
				ostr << m_numbers[i];
				if (i < m_numCount - 1) ostr << ", ";
			}

			ostr << std::endl << "-------------------------" << std::endl;
			ostr << "Total of " << m_numCount << " number(s)" << std::endl;
			ostr << "Largest number:  " << max() << std::endl;
			ostr << "Smallest number: " << min() << std::endl;
			ostr << "Average:         " << average() << std::endl;
			ostr << "=========================";
		}
		return ostr;
	}

	Numbers::~Numbers() {
		if (m_isOriginal && !isEmpty()) {
			save();
		}
		delete[] m_numbers;
		delete[] m_filename;
	}

}
