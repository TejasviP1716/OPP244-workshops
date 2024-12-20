/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 01/11/2024

***************************************************/



#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>

namespace seneca {
	class Numbers {
		double* m_numbers;
		char* m_filename;
		bool m_isOriginal;
		int m_numCount;

		bool isEmpty() const;
		void setEmpty();
		void setFilename(const char* filename);
		void sort();
		void save() const;
		int numberCount() const;
		bool load();

		std::ostream& display(std::ostream& ostr) const;

	public:
		Numbers();
		Numbers(const char* filename);
		Numbers(const Numbers& src);
		~Numbers();
		Numbers& operator=(const Numbers& src);
		Numbers& operator+=(double value);

		double average() const;
		double max() const;
		double min() const;

		friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
		friend std::istream& operator>>(std::istream& istr, Numbers& N);
	};
}

#endif // !SENECA_NUMBERS_H_