/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  
  section- ZAA
  Date- 15/11/2024

***************************************************/



#include <iostream>
#include <iomanip>
#include "Professor.h"
#include "Utils.h"
using namespace std;

namespace seneca {

	Professor::Professor() : m_subjectName(nullptr), m_sections(0) {}

	Professor::Professor(const char* name, const char* subject, int sections, size_t employeeNo, double salary)
		: Employee(name, employeeNo, salary), m_sections(sections) {
		m_subjectName = ut.alocpy(subject);
	}

	Professor::~Professor() {
		delete[] m_subjectName;
	}

	double Professor::devPay() const {
		return (salary() * 0.01 * m_sections);
	}

	std::ostream& Professor::title(std::ostream& ostr) const {
		Employee::title(ostr) << " Teaching Subject     | Sec # | $Dev Pay |";
		return ostr;
	}

	std::ostream& Professor::write(std::ostream& ostr) const {
		char subjectStr[21]{};
		if (m_subjectName) {
			ut.strcpy(subjectStr, m_subjectName, 20);
		}
		Employee::write(ostr);
		ostr << " ";

		ostr.width(20);
		ostr.setf(ios::left);
		ostr << subjectStr << " | ";
		ostr.unsetf(ios::left);

		ostr.width(5);
		ostr.setf(ios::right);
		ostr << m_sections << " | ";
		ostr.fill(' ');

		ostr.setf(ios::fixed);
		ostr.width(8);
		ostr.precision(2);
		ostr << devPay() << " |";
		ostr.unsetf(ios::right);

		return ostr;
	}

	std::istream& Professor::read(std::istream& istr) {
		char subject[1024];

		Employee::read(istr);
		istr.ignore();

		istr >> std::ws;

		istr.getline(subject, 1024, ',');

		if (istr) {
			m_subjectName = ut.alocpy(m_subjectName, subject);
		}

		istr >> m_sections;

		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
		return P.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Professor& P) {
		return P.read(istr);
	}
}
