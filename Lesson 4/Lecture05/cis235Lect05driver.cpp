//    CS 235    Lecture 05
//    Another example of classes
//       work with strings in this example
//    NOTE:  Leading 0's will not print - can be fixed
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#include "Ssn.h"

// **************************************************************
//  user written functions for main

void sort(Ssn info[], int count);
void print(ostream &, const Ssn info[], int, const char *message);

// Main program
// **************************************************************

const int ENTRIES = 3;

int main() {
    //   test a few functions
    cout << "The separator for a social security number is the character "
         << Ssn::getSEPARATOR() << endl;  // static functions can be
                                          // called with only scoping

    Ssn a("345-98-3245");
    cout << "The separator for a social security number is the character "
         << a.getSEPARATOR()
         << endl;  // static functions can ALSO be
                   // called using an object, but scoping is preferred

    cout << "a is ";
    a.print(cout);
    cout << endl << endl;
    int  w1 = a.getSsn();
    char w2[12];
    a.getSsn(w2);
    cout << "Test of conversion to integer and conversion to string" << endl;
    cout << w1 << ' ' << w2 << endl << endl << endl;

    Ssn b(0, 0, 0);  // default values all set to 0
    b.setFirst('5', '3', '6');
    cout << b.getSsn() << endl << endl;  // should output 536000000

    //  bring in the data in each of the 3 forms and sort the data
    Ssn one[ENTRIES], two[ENTRIES], three[ENTRIES];

    cout << "Enter " << ENTRIES
         << " Social Security Numbers as 9 digit integers\n";
    int i;

    for (i = 0; i < ENTRIES; i++) one[i].inputN();

    cout << "Enter " << ENTRIES
         << " Social Security Numbers as 9 digit strings, no -\n";

    for (i = 0; i < ENTRIES; i++) two[i].inputS();

    cout << "Enter " << ENTRIES
         << " Social Security Numbers as 9 digit strings with -\n";

    for (i = 0; i < ENTRIES; i++) three[i].inputS();

    print(cout, one, ENTRIES, "First array before sorting");
    print(cout, two, ENTRIES, "Second array before sorting");
    print(cout, three, ENTRIES, "Third array before sorting");

    sort(one, ENTRIES);
    sort(two, ENTRIES);
    sort(three, ENTRIES);

    print(cout, one, ENTRIES, "First array after sorting");
    print(cout, two, ENTRIES, "Second array after sorting");
    print(cout, three, ENTRIES, "Third array after sorting");
    return 0;  // end of main
}

//  **********************  User written functions  *****************

void swapValues(Ssn &, Ssn &);  //  used in sort

int indexSmallest(const Ssn data[], int start, int count);  // used in sort

void sort(Ssn info[], int count) {
    //  Selection sort
    int smallIndex;
    for (int i = 0; i < count - 1; i++) {
        smallIndex = indexSmallest(info, i, count);
        if (i != smallIndex) swapValues(info[i], info[smallIndex]);
    }
}

void swapValues(Ssn &left, Ssn &right) {
    Ssn work;
    left.copyTo(work);
    right.copyTo(left);
    work.copyTo(right);
}

int indexSmallest(const Ssn data[], int start, int numberUsed) {
    int indexMin = start;
    Ssn min(data[start]);
    for (int i = start + 1; i < numberUsed; i++) {
        if (data[i].isSmaller(min)) {
            indexMin = i;
            data[i].copyTo(min);
        }
    }
    return indexMin;
}

void print(ostream &w, const Ssn info[], int count, const char *message) {
    w << message << endl;
    for (int i = 0; i < count; i++) {
        info[i].print(w);
        w << endl;
    }
}

/*
The separator for a social security number is the character -
The separator for a social security number is the character -
a is 345-98-3245

Test of conversion to integer and conversion to string
345983245 345983245


Enter 3 Social Security Numbers as 9 digit integers
Enter a 9 digit social security number: 555443333
Enter a 9 digit social security number: 123456789
Enter a 9 digit social security number: 314896543
Enter 3 Social Security Numbers as 9 digit strings, no -
Enter a 9 digit social security number, with or without dashes 789765432
Enter a 9 digit social security number, with or without dashes 888776666
Enter a 9 digit social security number, with or without dashes 456999999
Enter 3 Social Security Numbers as 9 digit strings with -
Enter a 9 digit social security number, with or without dashes 123-45-6789
Enter a 9 digit social security number, with or without dashes 987-34-3345
Enter a 9 digit social security number, with or without dashes 654-99-9876
First array before sorting
555-44-3333
123-45-6789
314-89-6543
Second array before sorting
789-76-5432
888-77-6666
456-99-9999
Third array before sorting
123-45-6789
987-34-3345
654-99-9876
First array after sorting
123-45-6789
314-89-6543
555-44-3333
Second array after sorting
456-99-9999
789-76-5432
888-77-6666
Third array after sorting
123-45-6789
654-99-9876
987-34-3345
Press any key to continue
*/
