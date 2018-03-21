//    CS 235 Recursion Lab - write and test the following functions
//        - function names ending in I - use loops
//        - function names ending in R - use recursion, NO LOOPS

#include <cstring>
#include <iostream>
using namespace ::std;

// NOTE: const char * p    denotes a C++ string
// which is an array of characters ending in the NULL character '\0'

// Number Calculations
// assume exponent > 0  raiseToPower(2,4) returns 2*2*2*2 ==> 16
int raiseToPowerI(int base, int exponent);
// assume exponent > 0 use the exponent parameter for the recursion
int raiseToPowerR(int base, int exponent);

// Group Calculations
int productI(const int data[], int cellsUsed);
int productR(const int data[], int cellsUsed);

// count the number of times lookFor appears in a C++ string using iteration
int countCharI(const char* p, char lookFor);

// count the number of times lookFor appears in a C++ string using recursion
int countCharR(const char* p, char lookFor);

bool equalI(const char* left, const char* right);  // are the 2 C++ strings equal or not

bool equalR(const char* left, const char* right);  // are the 2 C++ strings equal or not

char largestI(const char* p);  // find the largest char in a C++ string using iteration

char largestR(const char* p);  // find the largest char in a C++ string using iteration

int main()
{
    int info[5] = {4, 8, 2, 9, 6};
    cout << "Testing product" << endl << productI(info, 5) << endl << productR(info, 5) << endl;

    cout << "Testing countChar" << endl
         << countCharI("mississippi", 'i') << endl
         << countCharR("mississippi", 'i') << endl;

    cout << "Testing raiseToPower" << endl
         << raiseToPowerI(5, 4) << endl
         << raiseToPowerR(5, 4) << endl;

    cout << "Testing equalI" << endl
         << equalI("abcde", "abcde") << endl
         << equalI("abxde", "abcde") << endl
         << equalI("abc", "abcde") << endl
         << equalI("abcde", "abc") << endl
         << equalI("abcde", "abcdg") << endl;

    cout << "Testing equalR" << endl
         << equalR("abcde", "abcde") << endl
         << equalR("abxde", "abcde") << endl
         << equalR("abc", "abcde") << endl
         << equalR("abcde", "abc") << endl
         << equalR("abcde", "abcdg") << endl;

    cout << "Testing largestI" << endl
         << largestI("xabcde") << endl
         << largestI("abxcde") << endl
         << largestI("abcdex") << endl;

    cout << "Testing largestR" << endl
         << largestR("xabcde") << endl
         << largestR("abxcde") << endl
         << largestR("abcdex") << endl;

    return 0;
}

// ******************************************************************

int productI(const int data[], int cellsUsed)
{
    int prod = 1;
    for (int i = 0; i < cellsUsed; ++i) {
        prod *= data[i];
    }
    return prod;
}

int productR(const int data[], int cellsUsed)
{
    if (cellsUsed == 0) {
        return 1;
    }
    else {
        return data[cellsUsed - 1] * productR(data, cellsUsed - 1);
    }
}

int countCharI(const char* p, char lookFor)
{
    int count = 0;
    for (unsigned int i = 0; i < strlen(p); ++i) {
        if (p[i] == lookFor) count++;
    }
    return count;
}

int countCharR(const char* p, char lookFor)
{
    if (*p == '\0') return 0;
    if (*p == lookFor) return 1 + countCharR(p + 1, lookFor);
    return countCharR(p + 1, lookFor);
}

int raiseToPowerI(int base, int exponent)  // assume exponent > 0
{
    int power = 1;
    for (int i = 0; i < exponent; ++i) {
        power *= base;
    }
    return power;
}

int raiseToPowerR(int base, int exponent)  // assume exponent > 0
{
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * raiseToPowerR(base, exponent - 1);
    }
}

bool equalI(const char* left, const char* right)
{
    if (strlen(left) != strlen(right)) return false;
    for (unsigned int i = 0; i < strlen(left); ++i) {
        if (left[i] != right[i]) return false;
    }
    return true;
}

bool equalR(const char* left, const char* right)
{
    // right is longer
    if (*left == '\0' && *right != '\0') return false;
    // left is longer
    if (*right == '\0' && *left != '\0') return false;
    // same length
    if (*left == '\0' && *right == '\0') return true;
    // chars are equal
    if (*left == *right) return equalR(left + 1, right + 1);
    // chars are not equal
    return false;
}

char largestI(const char* p)
{
    char largest = 'a';
    for (unsigned int i = 0; i < strlen(p) + 1; ++i) {
        if (p[i] > largest) {
            largest = p[i];
        }
    }
    return largest;
}

char largestR(const char* p)
{
    if (*p == '\0') return 0;
    return max(*p, largestR(p + 1));
}