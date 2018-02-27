//   CS 236   Lecture 5
#ifndef SSN_H
#define SSN_H

#include <cstring>
#include <iostream>
using namespace std;

class Ssn {
   public:
    Ssn(void);           // Default constructor
    Ssn(int, int, int);  // 3 Argument constructor
    Ssn(const Ssn &);    // Copy constructor
    Ssn(const char[]);   // pass a string as the parameter
    Ssn(int);            // pass an int of the form 456921245
    ~Ssn(void);          // One and only destructor
    void setSsn(int, int, int);
    void setSsn(int);
    void setSsn(const char[]);
    int  getSsn(void) const;
    void getSsn(char *) const;          //  form a string in caller's memory
    void print(ostream &w) const;       //   will print   ddd-dd-dddd
    void inputN(void);                  //   user types an integer
    void inputS(void);                  //   user types a string
    void copyTo(Ssn &) const;           //   copy invoking instance to parameter
    bool isSmaller(const Ssn &) const;  // return true if invoking instance
    void setFirst(char, char, char);    // Set the first 3 ssn numbers
    static char getSEPARATOR(void);  // static function to return separator char

   private:
    static const char SEPARATOR;  // Class data, not member data
    int first, middle, last;
};
#endif