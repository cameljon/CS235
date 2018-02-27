#include <iostream>
#include "nibbleHeader.h"
#include "testNibbleHeader.h"
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
int menu();
void visualTest();

int main() {
    visualTest();
    NibbleTest test(cout);
    int choice = 0;
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

int menu() {
    cout << endl << endl;
    cout << "Select for the following = use -1 to quit" << endl;
    for (int i = 0; i < NUMBER_NAMES; i++) cout << i << ' ' << names[i] << endl;
    int choice;
    cin >> choice;
    return choice;
}

void visualTest() {
    // visually check your code
    cout << "Starting Visual Test\n" << endl;

    // 0 NibbleDefaultConstructor
    {
        // students write the visual test
        cout << left << setw(40) << "Default constructor:";
        cout << setw(30) << "Nibble a" << endl;
        Nibble a;  // Should be 0000
        cout << left << setw(40) << "a.getValueAsDecimal:";
        cout << setw(30) << a.getValueAsDecimal() << endl << endl;
    }

    // 1 NibbleCopyConstructor
    {
        // students write the visual test
        cout << left << setw(40) << "Copy constructor Nibble a(10) to b:";
        cout << setw(30) << "Nibble b(a)" << endl;
        Nibble a(10);
        Nibble b(a);
        cout << left << setw(40) << "b.getValueAsDecimal:";
        cout << setw(30) << b.getValueAsDecimal() << endl << endl;
    }

    // 2 NibbleIntegerArgumentConstructor
    {  // new scope, can use any names
        cout << left << setw(40) << "Integer argument constructor:";
        cout << setw(30) << "Nibble a(14)" << endl;
        Nibble a(14);
        cout << left << setw(40) << "a.getValueAsDecimal():";
        cout << setw(30) << a.getValueAsDecimal() << endl <<  endl;
    }

    // 3 NibbleArrayArgumentConstructor
    {
        // students write the visual test
        cout << left << setw(40) << "Array constructor:";
        cout << setw(30) << "Using int array[4] = {1,0,1,0}" << endl;
        int b[4] = {1, 0, 1, 0};
        Nibble a(b);
        cout << left << setw(40) << "a.getValueAsBinaryString();";
        cout << setw(30) << a.getValueAsBinaryString() << endl << endl;
    }

    // 4 NibbleDestructor
    // Destructor will be called when work goes out of scope, do any errors show
    // up?
    { 
        cout << left << setw(40) << "Test of destructor:";
        Nibble work; 
        cout << setw(30) << "passed" << endl << endl;
    }

    // 5 NibbleGetDecimalValue
    {  // new scope, can use any names
        cout << left << setw(40) << "Test getValueAsDecimal():";
        cout << setw(30) << "Nibble b(14)" << endl;
        Nibble b(14);
        cout << left << setw(40) << "b.getValueAsDecimal():";
        cout << setw(30) << b.getValueAsDecimal() << endl << endl;
    }

    // 6 NibbleGetBinaryStringObject
    {
        // students write the visual test
        cout << left << setw(40) << "Testing getValueAsBinaryString():";
        cout << setw(30) << "Nibble a(10)" << endl;
        Nibble a(10);
        cout << left << setw(40) << "a.getValueAsBinaryString():";
        cout << setw(30) << a.getValueAsBinaryString() << endl << endl;
    }

    // 7 NibbleGetHexCharacter
    {
        // students write the visual test
        cout << left << setw(40) << "Test getValueAsHexCharacter():";
        cout << setw(30) << "Nibble a(11)" << endl;
        Nibble a(11);
        cout << left << setw(40) << "a.getValueAsHexCharacter():";
        cout << setw(30) << a.getValueAsHexCharacter() << endl << endl;
    }

    // 8 NibbleGetCppString

    {
        // students write the visual test
        cout << left << setw(40) << "Test getValueAsCppString():";
        cout << setw(30) << "Nibble a(9)" << endl;
        Nibble a(9);
        char answer[5];
        cout << left << setw(40) << "a.getValueAsCppString:";
        a.getValueAsCppString(answer);
        cout << setw(30) << answer << endl << endl;
    }

    // 9 NibbleOpertorAssignment

    // students leave blank for now

    // 10 NibbleOperatorInsertion
    {  // new scope, can use any names
        cout << "test of insertion operator" << endl;
        Nibble a(0), b(15);
        cout << "a is " << a << " b is " << b << endl;
    }

    // 11 NibbleOperatorEqual

    // students leave blank for now

    // 12 NibbleOperatorLessThan

    // students leave blank for now

    // 13 NibbleOperatorPlus

    // students leave blank for now

    // 14 NibbleOperatorMultiply

    // students leave blank for now
}
