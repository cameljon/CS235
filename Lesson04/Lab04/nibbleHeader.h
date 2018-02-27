#ifndef NIBBLE_H
#define NIBBLE_H

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace::std;

//   Assume there is NO invalid data
const int NUMBER_DIGITS = 4;
class Nibble
{

friend ostream & operator<<(ostream & out, const Nibble & item);       // overloaded operator <<

public:
	Nibble();                         // Default Constructor
	Nibble(const Nibble &);           // Copy Constructor
	Nibble(int parm);                 // Assume 0 <= parm <= 15  Store parm as binary number in digits   13 ==> 1101
	Nibble(const int array[]);        // Assume array holds 4 cells, all either 0 or 1

	~Nibble();                        // Destructor

	int    getValueAsDecimal()      const;         // will return an int between 0 and 15
	string getValueAsBinaryString() const;         // will return a string object consisting of 0's and 1's
	char   getValueAsHexCharacter() const;         // will return a char representing the hex digit
	void   getValueAsCppString( char answer[]) const;  // will place in the parameter four char 0's and 1's followed by the '\0' char

	//   OPERATORS - Do Not Write for this Lab, will write in the next lab
	// Assignment opertor
	const Nibble & operator=(const Nibble & r) ;

	// Relational opertors
	bool operator==(const Nibble & r) const;    
	bool operator<(const Nibble & r) const;     

	// Arithmetic operators
	Nibble operator+(const Nibble & r) const;    // NOTE:  because of overflow, results > 15 will be wrong
	        // NOTE:  work right to left, binary digit by binary digit NEED TO USE A carry bit
	        // NOTE:  MUST USE ARRAY PROCESSING WITH A LOOP
	        //              CANNOT CONVERT TO DECIMAL AND DO THE WORK IN DECIMAL
	
	Nibble operator*(const Nibble & r) const;     // NOTE:  because of overflow, results > 15 will be wrong
	        // NOTE:  * is repeated addition     2 * 3   is 2 + 2 + 2
	        //        use a for loop for repeated addition



private:
	int digits[NUMBER_DIGITS];   // 4 1's or 0's, high order digit (left most digit) in cell 0, low order digit (right most digit) in cell 3
	const static char tableOfHex[16];   // holds the character for the first 16 hex numbers 0 - F

};

#endif
