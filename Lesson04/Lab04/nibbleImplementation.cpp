#include "nibbleHeader.h"

const char Nibble::tableOfHex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// 0 NibbleDefaultConstructor
Nibble::Nibble()
{
    for (int i = 0; i < 4; ++i) {
        digits[i] = 0;
    }
}

// 1 NibbleCopyConstructor
Nibble::Nibble(const Nibble& right)
{
    for (int i = 0; i < 4; ++i) {
        digits[i] = right.digits[i];
    }
}

// 2 NibbleIntegerArgumentConstructor
Nibble::Nibble(int parm)  // Assume 0 <= parm <= 15
{
    digits[0] = parm / 8;  // high order digit goes in cell 0
    parm      = parm % 8;
    digits[1] = parm / 4;
    parm      = parm % 4;
    digits[2] = parm / 2;
    parm      = parm % 2;
    digits[3] = parm / 1;  // low order digit goes in cell 3
}

// 3 NibbleArrayArgumentConstructor
Nibble::Nibble(
    const int array[])  // Assume array holds 4 cells, all either 0 or 1
{
    for (int i = 0; i < 4; ++i) {
        digits[i] = array[i];
    }
}

// 4 NibbleDestructor
Nibble::~Nibble()
{
    // no work to perform
}

// 5 NibbleGetDecimalValue
int Nibble::getValueAsDecimal() const  // will return an int between 0 and 15
{
    int answer = digits[0] * 8 + digits[1] * 4 + digits[2] * 2 + digits[3] * 1;
    return answer;
}

// 6 NibbleGetBinaryStringObject
string Nibble::getValueAsBinaryString()
    const  // will return a string consisting of 0's and 1's
{
    string answer = "";
    for (int i = 0; i < 4; ++i) {
        answer += digits[i] + '0';
    }
    return answer;
}

// 7 NibbleGetHexCharacter
char Nibble::getValueAsHexCharacter()
    const  // will return a char representing the hex digit
{
    return tableOfHex[getValueAsDecimal()];
}

// 8 NibbleGetCppString
void Nibble::getValueAsCppString(char answer[]) const
{
    for (int i = 0; i < 4; ++i) {
        answer[i] = digits[i] + '0';
    }
    answer[4] = '\0';
}

//  DO NOT WRITE THE CODE FOR THE FOLLOWING IN THIS LAB
//       WILL WRITE THE CODE IN THE NEXT LAB
// 9 NibbleOpertorAssignment
const Nibble& Nibble::operator=(const Nibble& r)
{
    // students leave blank for now

    return *this;
}

// 10 NibbleOperatorInsertion    Friend function
ostream& operator<<(ostream& out, const Nibble& item)  // friend function
{
    // Allows the user to view the data as output
    for (int i = 0; i < NUMBER_DIGITS; i++) out << item.digits[i];
    return out;
}

// 11 NibbleOperatorEqual
bool Nibble::operator==(const Nibble& r) const
{
    // students leave blank for now

    return false;
}

// 12 NibbleOperarotLessThan
bool Nibble::operator<(const Nibble& r) const
{
    // students leave blank for now
    return false;
}
// 13 NibbleOperatorPlus

Nibble Nibble::operator+(const Nibble& r) const  // NOTE:  because of overflow,
                                                 // results > 15 will be wrong
                                                 // NOTE:  work right to left,
                                                 // binary digit by binary digit
                                                 // NEED TO USE A carry bit
                                                 // NOTE:  MUST USE ARRAY
                                                 // PROCESSING WITH A LOOP
                                                 //              CANNOT CONVERT
                                                 //              TO DECIMAL AND
                                                 //              DO THE WORK IN
                                                 //              DECIMAL

{
    Nibble ans;

    // students leave blank for now

    return ans;
}
// 14 NibbleOperatorMultiply
Nibble Nibble::operator*(const Nibble& r)
    const  // NOTE:  because of overflow, results > 15 will be wrong
           // NOTE:  * is repeated addition     2 * 3   is 2 + 2 + 2
           //        use a for loop for repeated addition
{
    Nibble ans;

    // students leave blank for now

    return ans;
}