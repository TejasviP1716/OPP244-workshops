/***************************************
Name - Tejasvi Parmar

section - ZAA

******************************************/

#ifndef CC_H
#define CC_H
namespace seneca {
    class CC {
        char* m_name;
        unsigned long long m_cardNo;
        short m_cvv;
        short m_expMon;
        short m_expYear;

        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
        bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;
        void prnNumber(unsigned long long CCnum) const;

    public:
        void set();
        void cleanUp();
        bool isEmpty() const;
        void set(const char* cc_name, unsigned long long cc_no, short m_cvv, short m_expMon, short m_expYear);
        void set(const char* cc_name, unsigned long long cc_no, short m_cvv);
        void display() const;
    };

}

#endif // CC_H
