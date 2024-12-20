/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 15/11/2024

***************************************************/





#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"

namespace seneca {
	class Professor : public Employee {
		char* m_subjectName{};
		int m_sections{};

		double devPay() const;

	public:
		Professor();
		Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary);
		~Professor();

		std::ostream& title(std::ostream& ostr = std::cout) const;
		std::ostream& write(std::ostream& ostr = std::cout) const;
		std::istream& read(std::istream& istr = std::cin);
	};

	std::ostream& operator<<(std::ostream& ostr, const Professor& P);
	std::istream& operator>>(std::istream& istr, Professor& P);
}
#endif