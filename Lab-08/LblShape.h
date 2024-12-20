
/**************************************************

  Name- Tejasvi Nitinkumar Parmar
  student id- 151236239
  Email- tnparmar2@myseneca.ca
  section- ZAA
  Date- 22/11/2024

***************************************************/




#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include "Shape.h"
using namespace std;
namespace seneca {

    class LblShape : public Shape {
        // Dynamically allocated label for the shape
        char* m_label = nullptr;
    protected:
        // Returns the label string for derived classes to access
        const char* label() const;
    public:
        // Default constructor
        LblShape();

        // Constructor with label initialization
        LblShape(const char* label);

        // Copy constructor and assignment operator are deleted to prevent copying
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;


        // Reads label specifications from input stream
        void getSpecs(istream& is) override;

        // Destructor to release dynamically allocated memory
        virtual~LblShape();
    };
}

#endif // !SENECA_LABELEDSHAPE_H
