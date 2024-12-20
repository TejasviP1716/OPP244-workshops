
/***********************************************************************
// OOP244 workshop 10, Name module
//
// File	Name.h
// Version 1.0
// Date 2024-11-22
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Tejasvi Parmar           Date  29/11/24          Reason ZAA
/////////////////////////////////////////////////////////////////
***********************************************************************/


#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

#include <iostream>
namespace seneca {

    template <typename T>
    void prnArray(const T* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }


    template <typename T>
    T* dynaCopy(const T* src, size_t size) {
        T* dest = new T[size];
        for (size_t i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }

    template <typename T>
    T* dynaCopy(T*& dest, const T* src, size_t size) {
        delete[] dest;
        dest = new T[size];
        for (size_t i = 0; i < size; ++i) {
            dest[i] = src[i];
        }
        return dest;
    }
}

#endif // !SENECA_DYNACOPY_H

