#pragma once

/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// Date 2024-9-11
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name Tejasvi Parmar           Date  16/11/2024          Reason ZAA
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src)const;
        char* alocpy(char*& des, const char* src)const;
        char* strcpy(char* des, const char* src)const;
        int strlen(const char* str)const;
        bool isspace(char ch)const;
        bool isspace(const char* cstring)const;
    };
    extern Utils ut;   // makes the ut object available where Utils.h is included
    // to call a Utils function call it as follows
    // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
