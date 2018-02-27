#ifndef NIBBLE_H
#define NIBBLE_H

#include <iostream>
#include <string>
using namespace ::std;

//   Assume there is NO invalid data
const int NUMBER_DIGITS = 4;
class Nibble {
    friend ostream &operator<<(ostream &out, const Nibble &item);

   public:
    Nibble();                // Default Constructor
    Nibble(const Nibble &);  // Copy Constructor
    Nibble(int parm);  // Assume 0 <= parm <= 15  Store parm as binary number in
                       // digits   13 ==> 1101
    Nibble(const int array[]);  // Assume array holds 4 cells, all either 0 or 1

    ~Nibble();  // Destructor

    // will return an int between 0 and 15
    int getValueAsDecimal() const;
    // will return a string object consisting of 0's and 1's
    string getValueAsBinaryString() const;
    // will return a char representing the hex digit
    char getValueAsHexCharacter() const;
    // will place in the parameter four char 0's and 1's followed by the '\0'
    // char
    void getValueAsCppString(char answer[]) const;

    // Assignment opertor
    const Nibble &operator=(const Nibble &r);

    // Relational opertors
    bool operator==(const Nibble &r) const;
    bool operator<(const Nibble &r) const;

    // Arithmetic operators
    Nibble operator+(const Nibble &r) const;

    Nibble operator*(const Nibble &r) const;

   private:
    int               digits[NUMBER_DIGITS];
    const static char tableOfHex[16];
};

#endif