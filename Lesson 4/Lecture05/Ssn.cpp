//  CS 236     Lecture 5

#include "Ssn.h"
#pragma warning(disable : 4996)
//    IMPLEMENTATION OF CLASS MEMBER FUNCTIONS

const char Ssn::SEPARATOR = '-';  //  give out the memory for static class data

char Ssn::getSEPARATOR(void)
{
    return SEPARATOR;  // static functions CAN NOT access member data
                       // static function ONLY access static data
}

Ssn::Ssn(void) { setSsn(111, 22, 3333); }

Ssn::Ssn(int f, int s, int t) { setSsn(f, s, t); }

Ssn::Ssn(const Ssn& other) { setSsn(other.getSsn()); }

Ssn::Ssn(const char s[]) { setSsn(s); }

Ssn::Ssn(int n) { setSsn(n); }

Ssn::~Ssn(void) {}  // since no dynamic data, no code needs to be executed

void Ssn::setSsn(int f, int m, int ls)
{
    first  = f;
    middle = m;
    last   = ls;
}

void Ssn::setSsn(int n)
{
    //  initially work with a number with 6 zeroes
    first = n / 1000000;  // 456921245 / 1000000 gives 456, the left 3 digits
    n = n % 1000000;     // 456921245 % 1000000 gives 921245, the right 6 digits
                         //  n is now 921245
                         //     now work with a number with 4 zeroes
    middle = n / 10000;  //  921245 / 10000 gives 92, the left 2 digits
    last   = n % 10000;  //  921245 % 10000 gives 1245, the right 4 digits
}

// void Ssn::setSsn(const char sn[])
// {
//     char s[12];
//     strncpy(s, sn, 12);
//     s[11] = '\0';
//     if (strlen(s) == 11)  //  need to remove the SEPARATOR's
//     {
//         strncpy(s + 3, s + 4, 2);  //  can use relative addresses
//         strncpy(s + 5, s + 7, 4);
//         s[9] = '\0';  // add the Null character to get a C++ string
//     }
//     int work = atoi(s);  //  call the library ASCII to Integer function
//                          //        to convert from a string to an integer
//     setSsn(work);
// }

void Ssn::setSsn(const char sn[])
{
    char s[12];
    strncpy(s, sn, 12);
    s[11] = '\0';
    if (strlen(s) == 11)  //  need to remove the SEPARATOR's
    {
        strncpy(s + 3, s + 4, 2);  //  can use relative addresses
        strncpy(s + 5, s + 7, 4);
        s[9] = '\0';  // add the Null character to get a C++ string
    }
    // The statement below only works for integers with 9 or fewer digits
    int work = atoi(s);  //  call the library ASCII to Integer function
                         //        to convert from a string to an integer
    setSsn(work);
    // For integers that are more than 9 digits, atoi() does not work, because
    // integers are stored in 32 bits Here is a more general way to pull out
    // multiple groups of integers from a single string of digits Work from
    // right to left Isolate the right most 4 digits
    last = atoi(s + 5);
    s[5] = '\0';  // place null character after the first 5 digits for the next
                  // atoi() to work
    // Isolate the right most 2 digits of the 5 remaining digits
    middle = atoi(s + 3);
    s[3] = '\0';  // place null character after the first 3 digits for the next
                  // atoi() to work
    // Isolate the remaining 3 digits
    first = atoi(s);
}

int Ssn::getSsn(void) const { return last + 10000 * middle + 1000000 * first; }

void Ssn::getSsn(char* s) const
{
    s[0] = '0' + first / 100;  // 456 / 100 gives the integer 4
                               //   add the ASCII value of the char zero
                               //   to get the character 4
                               //   the char 0 has ASCII value of 30 base 16
                               //   the char 4 has ASCII value of 34 base 16
    s[1] = '0' + first % 100 / 10;
    s[2] = '0' + first % 10;

    s[3] = '0' + middle / 10;
    s[4] = '0' + middle % 10;

    s[5] = '0' + last / 1000;
    s[6] = '0' + last % 1000 / 100;
    s[7] = '0' + last % 100 / 10;
    s[8] = '0' + last % 10;
    s[9] = '\0';
}

void Ssn::print(ostream& w) const
{
    w << first << SEPARATOR << middle << SEPARATOR << last;
    // since there are go get functions for first, middle or last
    //      need to directly access the member data
}

void Ssn::inputN(void)
{
    cout << "Enter a 9 digit social security number: ";
    int work;
    cin >> work;
    setSsn(work);
}

void Ssn::inputS(void)
{
    cout << "Enter a 9 digit social security number,"
         << " with or without dashes ";
    char work[12];
    cin >> work;
    setSsn(work);
}

void Ssn::copyTo(Ssn& r) const { r.setSsn(getSsn()); }

bool Ssn::isSmaller(const Ssn& r) const
{
    if (first < r.first)
        return true;
    else if (first > r.first)
        return false;
    else if (middle < r.middle)
        return true;
    else if (middle > r.middle)
        return false;
    else if (last < r.last)
        return true;
    else
        return false;
}

void Ssn::setFirst(char left, char middle, char right)
{
    int m_left   = left - '0';
    int m_middle = middle - '0';
    int m_right  = right - '0';
    first        = m_left * 100 + m_middle * 10 + m_right * 1;
}