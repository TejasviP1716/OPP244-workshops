/**************************************************

  Name- Tejasvi Nitinkumar Parmar
 
  section- ZAA
  Date- 04/10/2024

***************************************************/

#include <iostream>
#include "cstr.h"  
#include "Canister.h"

using namespace std;

namespace seneca
{
	const double PI = 3.14159265;

	bool Canister::isEmpty() const 
	{
		return m_contentVolume < 0.00001;
	}
	Canister::Canister() 
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
	}

	Canister::Canister(const char* contentName)
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;

		if (contentName != nullptr)
		{
			alocpy(m_contentName, contentName);
		}
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		m_contentName = nullptr;
		m_height = height;
		m_diameter = diameter;
		m_contentVolume = 0.0;

		if (contentName != nullptr)
		{
			alocpy(m_contentName, contentName);
		}
	}

	Canister& Canister::setContent(const char* contentName)
	{
		bool sameContent = m_contentName && strcmp(m_contentName, contentName) == 0;

		if (sameContent)
		{
			return *this;
		}
		else if (usable() && contentName != nullptr)
		{

			if (m_contentName == nullptr || isEmpty())
			{
				alocpy(m_contentName, contentName);
			}
		}


		return *this;
	}


	bool Canister::usable() const
	{
		return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
	}

	void Canister::setToUnusable() 
	{
		freeMem(m_contentName);
		m_diameter = m_height = -1.0;
	}

	double Canister::capacity() const 
	{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	bool Canister::hasSameContent(const Canister& C)const
	{
		return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
	}

	double Canister::volume() const 
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (";
		cout.width(4);
		cout << m_height << "x";
		cout.width(4);
		cout << m_diameter << ") Canister";
		if (!usable())
		{
			cout << " is  Unusable   recycle!";
		}
		else {
			cout << " of ";
			cout.width(7);
			cout << volume() << "cc   " << (m_contentName ? m_contentName : "Sanetized and Empty");
		}
		return cout;
	}
	Canister& Canister::pour(double qty)
	{
		if (usable())
		{
			double availableSpace = capacity() - volume();
			if (qty > 0 && qty <= availableSpace)
			{
				m_contentVolume += qty;
			}
			else 
			{
				setToUnusable();
			}
		}
		else
		{
			setToUnusable();
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		if (usable())
		{
			double availableSpace = capacity() - volume();

			if (C.volume() > availableSpace)
			{
				C.m_contentVolume -= availableSpace;
				m_contentVolume = capacity();
			}
			else
			{
				pour(C.volume());
				C.m_contentVolume = 0.0;
			}

			if (m_contentName && !hasSameContent(C))
			{
				setToUnusable();
			}
			else
			{
				setContent(C.m_contentName);
			}
		}
		else {
			setToUnusable();
		}
		return *this;
	}

	Canister& Canister::clear()
	{
		freeMem(m_contentName);
		m_contentVolume = 0.0;

		return *this;
	}

	Canister::~Canister()
	{
		freeMem(m_contentName);
	}
}
