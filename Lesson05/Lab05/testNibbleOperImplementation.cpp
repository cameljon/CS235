#include "testnibbleOperHeader.h"

NibbleTest::NibbleTest(ostream& w) : out(w) {}
// 0
int NibbleTest::nibbleDefaultConstructor() const
{
    Nibble work;
    if (work.getValueAsDecimal() == 0) return TEST_VALUE;
    return 0;
}
// 1
int NibbleTest::nibbleCopyConstructor() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble original(i);
        Nibble copy(original);
        if (copy.getValueAsDecimal() != i) {
            result = 0;
            out << "Error in Copy Constructor for the value of " << i << endl;
        }
    }
    return result;
}
// 2
int NibbleTest::nibbleIntegerArgumentConstructor() const
{
    // test integer argument constructor
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble t(i);
        if (t.getValueAsDecimal() != i) {
            out << "Constructor failure for " << i << endl;
            result = 0;
        }
    }
    return result;
}
// 3
int NibbleTest::nibbleArrayArgumentConstructor() const
{
    int result = TEST_VALUE;
    int work[4];
    for (int i1 = 0; i1 < 2; i1++) {
        work[0] = i1;
        for (int i2 = 0; i2 < 2; i2++) {
            work[1] = i2;
            for (int i3 = 0; i3 < 2; i3++) {
                work[2] = i3;
                for (int i4 = 0; i4 < 2; i4++) {
                    work[3]             = i4;
                    int    decimalValue = i1 * 8 + i2 * 4 + i3 * 2 + i4;
                    Nibble test(work);
                    if (test.getValueAsDecimal() != decimalValue) {
                        result = 0;
                        out << "Error in array argument constructor for "
                            << decimalValue << endl;
                    }  // end if
                }      // end i4
            }          // end i3
        }              // end i2
    }                  // end i1
    return result;
}
// 4
int NibbleTest::nibbleDestructor() const { return TEST_VALUE; }
// 5
int NibbleTest::nibbleGetDecimalValue() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble work(i);
        if (work.getValueAsDecimal() != i) {
            result = 0;
            out << "Error in get decimal value for " << i << endl;
        }
    }
    return result;
}
// 6
int NibbleTest::nibbleGetBinaryStringObject() const
{
    int                 result                         = TEST_VALUE;
    static const string tableOfBinaryStringObjects[16] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for (int i = 0; i <= 15; i++) {
        Nibble work(i);
        if (work.getValueAsBinaryString() != tableOfBinaryStringObjects[i]) {
            result = 0;
            out << "String object error for " << i << endl;
        }
    }

    return result;
}
// 7
int NibbleTest::nibbleGetHexCharacter() const
{
    int               result         = TEST_VALUE;
    static const char tableOfHex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i <= 15; i++) {
        Nibble work(i);
        if (work.getValueAsHexCharacter() != tableOfHex[i]) {
            result = 0;
            out << "hex digit error for " << i << endl;
        }
    }

    return result;
}
// 8

int NibbleTest::nibbleGetCppString() const
{
    int                 result                         = TEST_VALUE;
    static const string tableOfBinaryStringObjects[16] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for (int i = 0; i <= 15; i++) {
        Nibble work(i);
        char   cppString[5];
        work.getValueAsCppString(cppString);
        if (strcmp(cppString, tableOfBinaryStringObjects[i].c_str()) != 0) {
            result = 0;
            out << "cpp string error for " << i << endl;
        }
    }

    return result;
}

// 9
int NibbleTest::nibbleOpertorAssignment() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble original(i);
        Nibble copy;
        copy = original;
        if (copy.getValueAsDecimal() != i) {
            result = 0;
            out << "Error in Assignment Operator for the value of " << i
                << endl;
        }
    }
    return result;
}
// 10
int NibbleTest::nibbleOperatorInsertion() const { return TEST_VALUE; }
// 11
int NibbleTest::nibbleOperatorEqual() const
{
    // test isEqual
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble tI(i);
        for (int j = 0; j <= 15; j++) {
            Nibble sJ(j);
            if (i == j) {
                if ((tI == sJ) == false) {
                    out << "== failure for " << i << " and " << j << endl;
                    result = 0;
                }
            }
            else {
                if ((tI == sJ) == true) {
                    out << "== failure for " << i << " and " << j << endl;
                    result = 0;
                }
            }  // end else
        }      // end inner for
    }          // end outer for
    return result;
}
// 12
int NibbleTest::nibbleOperarotLessThan() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble tI(i);
        for (int j = 0; j <= 15; j++) {
            Nibble sJ(j);
            if (i < j) {
                if ((tI < sJ) == false) {
                    out << "< failure for " << i << " and " << j << endl;
                    result = 0;
                }
            }
            else {
                if ((tI < sJ) == true) {
                    out << "< failure for " << i << " and " << j << endl;
                    result = 0;
                }
            }  // end else
        }      // end inner for
    }          // end outer for
    return result;
}
// 13
int NibbleTest::nibbleOperatorPlus() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble a(i);
        for (int j = 0; j <= 15; j++) {
            if (i + j <= 15)  // no overflow
            {
                Nibble b(j);
                Nibble c;
                c = a + b;
                if (c.getValueAsDecimal() != (i + j)) {
                    result = 0;
                    out << "Error adding " << i << " + " << j << endl;
                }  // end inner if
            }      // end outer if
        }          // end inner for
    }              // end outer for
    return result;
}

// 14
int NibbleTest::nibbleOperatorMultiply() const
{
    int result = TEST_VALUE;
    for (int i = 0; i <= 15; i++) {
        Nibble a(i);
        for (int j = 0; j <= 15; j++) {
            if (i * j <= 15)  // no overflow
            {
                Nibble b(j);
                Nibble c;
                c = a * b;
                if (c.getValueAsDecimal() != (i * j)) {
                    result = 0;
                    out << "Error multiplying " << i << " * " << j << endl;
                }  // end inner if
            }      // end outer if
        }          // end inner for
    }              // end outer for
    return result;
}
// 15
int NibbleTest::nibbleTestAll() const
{
    NibbleTest test(cout);
    const int  NUMBER_NAMES = 16;
    int        total        = 0;
    for (int choice = 0; choice < NUMBER_NAMES - 1; choice++) {
        switch (choice) {
            case 0:
                total += test.nibbleDefaultConstructor();
                break;
            case 1:
                total += test.nibbleCopyConstructor();
                break;
            case 2:
                total += test.nibbleIntegerArgumentConstructor();
                break;
            case 3:
                total += test.nibbleArrayArgumentConstructor();
                break;
            case 4:
                total += test.nibbleDestructor();
                break;
            case 5:
                total += test.nibbleGetDecimalValue();
                break;
            case 6:
                total += test.nibbleGetBinaryStringObject();
                break;
            case 7:
                total += test.nibbleGetCppString();
                break;
            case 8:
                total += test.nibbleGetCppString();
                break;
            case 9:
                total += test.nibbleOpertorAssignment();
                break;
            case 10:
                total += test.nibbleOperatorInsertion();
                break;
            case 11:
                total += test.nibbleOperatorEqual();
                break;
            case 12:
                total += test.nibbleOperarotLessThan();
                break;
            case 13:
                total += test.nibbleOperatorPlus();
                break;
            case 14:
                total += test.nibbleOperatorMultiply();
                break;
            default:
                break;
        };  // end switch
    }       // end for
    return total;
}
