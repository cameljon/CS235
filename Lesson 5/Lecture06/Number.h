// CS 235 Lecture 06 - Operator Overloading

#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <string>
using namespace ::std;

class Number {
    friend ostream &operator<<(ostream &, const Number &);
    friend istream &operator>>(istream &, Number &);
    friend Number   operator+(int, const Number &);  // mixed mode, int on left
    friend Number   operator*(int, const Number &);  // mixed mode, int on left

   public:
    Number(void);
    Number(int);
    Number(const Number &);
    ~Number();

    Number &setValue(int);  // return reference for function chaining
    int     getInteger(void) const;
    string  getString(void) const;

    Number operator+(const Number &) const;
    Number operator+(int) const;  // mixed mode on the right
    Number operator*(const Number &)const;
    Number operator*(int)const;  // mixed mode on the right
    bool   operator==(const Number &) const;
    bool   operator!=(const Number &r) const  // inline code
    {
        return !((*this) == r);
    }
    bool operator<(const Number &) const;

    const Number &operator=(const Number &);

    const Number &print(
        ostream &) const;  // return reference for function chaining

   private:
    static const string name1[20];  // names of integers 0 - 19
    static const string name2[10];  // names of 20, 30, ..., 80, 90
    static const string name3[5];   // names of thousand, million, billion

    // the following function converts an integer to a string
    //     1234 converts to one thousand two hundred thirty four
    static string figureString(int toConvert, int counterFuntionCalls);

    int    theNumber;
    string theString;
};

#endif