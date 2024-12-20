/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>
#include "Utils.h"
using namespace std;
namespace seneca {
    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        if (label) {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    const char* LblShape::label() const {
        return m_label;
    }

    void LblShape::getSpecs(istream& is) {
        char label[81];
        is.getline(label, 81, ',');
        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
    }
}