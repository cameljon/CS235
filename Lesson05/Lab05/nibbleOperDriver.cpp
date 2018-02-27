#include <iomanip>
#include <iostream>
#include <sstream>
#include "nibbleOperHeader.h"
#include "testNibbleOperHeader.h"
using namespace ::std;

const int NUMBER_NAMES = 16;

const string names[NUMBER_NAMES] = {"NibbleDefaultConstructor",
                                    "NibbleCopyConstructor",
                                    "NibbleIntegerArgumentConstructor",
                                    "NibbleArrayArgumentConstructor",
                                    "NibbleDestructor",
                                    "NibbleGetDecimalValue",
                                    "NibbleGetBinaryStringObject",
                                    "NibbleGetHexCharacter",
                                    "NibbleGetCppString",
                                    "NibbleOpertorAssignment",
                                    "NibbleOperatorInsertion",
                                    "NibbleOperatorEqual",
                                    "NibbleOperarotLessThan",
                                    "NibbleOperatorPlus",
                                    "NibbleOperatorMultiply",
                                    "NibbleTestAll"};
/*
0  NibbleDefaultConstructor
1  NibbleCopyConstructor
2  NibbleIntegerArgumentConstructor
3  NibbleArrayArgumentConstructor
4  NibbleDestructor
5  NibbleGetDecimalValue
6  NibbleGetBinaryStringObject
7  NibbleGetHexCharacter
8  NibbleGetCppString
9  NibbleOpertorAssignment
10 NibbleOperatorInsertion
11 NibbleOperatorEqual
12 NibbleOperarotLessThan
13 NibbleOperatorPlus
14 NibbleOperatorMultiply
15 NibbleTestAll
*/
int  menu();
void visualTest();

int main()
{
    visualTest();
    NibbleTest test(cout);
    int        choice = 0;
    while (choice != -1) {
        choice = menu();
        switch (choice) {
            case 0:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleDefaultConstructor() << endl;
                break;
            case 1:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleCopyConstructor() << endl;
                break;
            case 2:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleIntegerArgumentConstructor() << endl;
                break;
            case 3:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleArrayArgumentConstructor() << endl;
                break;
            case 4:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleDestructor() << endl;
                break;
            case 5:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleGetDecimalValue() << endl;
                break;
            case 6:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleGetBinaryStringObject() << endl;
                break;
            case 7:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleGetHexCharacter() << endl;
                break;
            case 8:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleGetCppString() << endl;
                break;
            case 9:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOpertorAssignment() << endl;
                break;
            case 10:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOperatorInsertion() << endl;
                break;
            case 11:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOperatorEqual() << endl;
                break;
            case 12:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOperarotLessThan() << endl;
                break;
            case 13:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOperatorPlus() << endl;
                break;
            case 14:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleOperatorMultiply() << endl;
                break;
            case 15:
                cout << "score for " << names[choice] << " is "
                     << test.nibbleTestAll() << endl;
                break;
            default:
                break;
        };
    }

    return 0;

}  // end main

int menu()
{
    cout << endl << endl;
    cout << "Select for the following = use -1 to quit" << endl;
    for (int i = 0; i < NUMBER_NAMES; i++) cout << i << ' ' << names[i] << endl;
    int choice;
    cin >> choice;
    return choice;
}

void visualTest()
{
    // visually check your code
    cout << "\nStarting Visual Test for Nibble Operators" << endl << endl;

    // 9 NibbleOpertorAssignment
    {
        // students write the visual test
        cout << left << setw(40) << "Test assignment operator:";
        cout << setw(30) << "Nibble a = b(9)" << endl;
        Nibble a;
        Nibble b(9);
        a = b;
        cout << left << setw(40) << "a.getValueAsDecimal:";
        cout << setw(30) << a.getValueAsDecimal() << endl << endl;
    }

    // 11 NibbleOperatorEqual
    {
        // students write the visual test
        cout << left << setw(40) << "Test equality operator true:";
        cout << setw(30) << "a(9) == b(9)" << endl;
        Nibble a(9);
        Nibble b(9);
        string out1 = (a == b) ? "True" : "False";
        cout << left << setw(40) << "(a == b):";
        cout << setw(30) << out1 << endl << endl;
        cout << left << setw(40) << "Test equality operator false:";
        cout << setw(30) << "a(9) == c(8)" << endl;
        Nibble c(4);
        string out2 = (a == c) ? "True" : "False";
        cout << left << setw(40) << "(a == c):";
        cout << setw(30) << out2 << endl << endl;
    }

    // 12 NibbleOperatorLessThan
    {
        // students write the visual test
        cout << left << setw(40) << "Test less than operator true:";
        cout << setw(30) << "a(4) < b(10)" << endl;
        Nibble a(4);
        Nibble b(10);
        string out1 = (a < b) ? "True" : "False";
        cout << left << setw(40) << "(a < b):";
        cout << setw(30) << out1 << endl << endl;
        cout << left << setw(40) << "Test less than operator false:";
        cout << setw(30) << "b(10) < a(4)" << endl;
        string out2 = (b < a) ? "True" : "False";
        cout << left << setw(40) << "(b < a):";
        cout << setw(30) << out2 << endl << endl;
    }

    // 13 NibbleOperatorPlus
    {
        // students write the visual test
        cout << left << setw(40) << "Test addition operator:";
        cout << setw(30) << "4 through 8" << endl;
        for (int i = 4; i < 9; ++i) {
            for (int j = 4; j < 9; ++j) {
                if ((i + j) < 15) {
                    Nibble        a(i), b(j);
                    Nibble        c = a + b;
                    ostringstream formula;
                    formula << i << " + " << j << " =   ";
                    cout << right << setw(40) << formula.str();
                    cout << left << setw(30) << c.getValueAsDecimal() << endl;
                }
            }
        }
    }

    // 14 NibbleOperatorMultiply

    {
        // students write the visual test
        cout << left << setw(40) << "Test multiplication operator:";
        cout << setw(30) << "0 through 3" << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if ((i + j) < 15) {
                    Nibble        a(i), b(j);
                    Nibble        c = a * b;
                    ostringstream formula;
                    formula << i << " * " << j << " =   ";
                    cout << right << setw(40) << formula.str();
                    cout << left << setw(30) << c.getValueAsDecimal() << endl;
                }
            }
        }
        cout << endl;
    }
    cout << "End of Visual Test for Nibble Operators" << endl;
}