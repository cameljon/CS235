#include "nibbleOperHeader.h"

const char Nibble::tableOfHex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// 0 NibbleDefaultConstructor
Nibble::Nibble()
{
    // students copy your code from the Nibble Lab
    for (int i = 0; i < 4; ++i) {
        digits[i] = 0;
    }
}

// 1 NibbleCopyConstructor
Nibble::Nibble(const Nibble& right)
{
    // students copy your code from the Nibble Lab
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
Nibble::Nibble(const int array[])
{
    for (int i = 0; i < 4; ++i) {
        digits[i] = array[i];
    }
}

// 4 NibbleDestructor
Nibble::~Nibble() {}

// 5 NibbleGetDecimalValue
int Nibble::getValueAsDecimal() const
{
    int answer = digits[0] * 8 + digits[1] * 4 + digits[2] * 2 + digits[3] * 1;
    return answer;
}

// 6 NibbleGetBinaryStringObject
string Nibble::getValueAsBinaryString() const
{
    string answer = "";
    for (int i = 0; i < 4; ++i) {
        answer += digits[i] + '0';
    }
    return answer;
}

// 7 NibbleGetHexCharacter
char Nibble::getValueAsHexCharacter() const
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

//  Students - Write the following Member Functions
// 9 NibbleOpertorAssignment
const Nibble& Nibble::operator=(const Nibble& r)
{
    for (int i = 0; i < 4; ++i) {
        digits[i] = r.digits[i];
    }
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
    // students write your code
    for (int i = 0; i < 4; ++i) {
        if (digits[i] != r.digits[i]) return false;
    }
    return true;
}

// 12 NibbleOperarotLessThan
bool Nibble::operator<(const Nibble& r) const
{
    // students write your code
    return this->getValueAsDecimal() < r.getValueAsDecimal();
}

// 13 NibbleOperatorPlus
Nibble Nibble::operator+(const Nibble& r) const
{
    Nibble ans;
    int    carry = 0;  // carry bit
    for (int i = 3; i > -1; --i) {
        ans.digits[i] = digits[i] + r.digits[i] + carry;  // add all bits
        if (ans.digits[i] == 2) {                         // need carry bit
            ans.digits[i] = 0;
            carry         = 1;
        }
        else if (ans.digits[i] == 3) {  // need carry bit
            ans.digits[i] = 1;
            carry         = 1;
        }
        else {  // no carry bit
            carry = 0;
        }
    }
    return ans;
}

// 14 NibbleOperatorMultiply
Nibble Nibble::operator*(const Nibble& r) const
{
    Nibble ans;
    if (r < 1) {
        return ans;
    }
    else if (r == 1) {
        return *this;
    }
    else {
        for (int i = 0; i < r.getValueAsDecimal(); ++i) {
            ans = ans + *this;
        }
        return ans;
    }
}