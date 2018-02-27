#include <iostream>
#include "Number.h"
using namespace ::std;

int main()
{
    {
        Number a(456), b(782), c, d, e;
        c = a * b;
        d = a * 983;
        e = 1234 * b;
        cout << "c is " << c << endl;
        cout << "d is " << d << endl;
        cout << "e is " << e << endl;
    }
    Number a, b, c;

    // example of function chaining using setValue and print setValue returns a
    // reference ( i.e. an alias ) to the invoking instance a and that reference
    // becomes the invoking instance for the print method
    a.setValue(1344).print(cout);
    cout << endl;

    a.setValue(1034560005);
    b.setValue(900789123);
    c = a + b;
    cout << a << endl
         << " plus" << endl
         << b << endl
         << " is" << endl
         << c << endl;

    // study operator and function notation
    // a + b + c;  // + works left to right a.operator+(b).operator+(c);
    // function chaining the return value for the first a.operator+(b) method
    // call becomes the invoking instance for the second
    // operator+(c) method call

    // a + (b + c); //  inside the (   ) executed first
    // a.operator+(b.operator+(c));

    // a = b = c;  //  = works right to left

    // a.operator=(b.operator=(c));  // function chaining the return value for
    // the
    //                               // first executed b.operator=(c) inside the
    //                               (
    //                               // ) becomes the parameter for the
    //                               a.operator+
    //                               // method call

    // a + b < c + a;  // order of operations 1. leftmost +; 2. rightmost + 3. <
    //                 // NOTE the left and right operands for < are the return
    //                 // values for the + operators

    // a.operator+(b).operator<(c.operator+(a));
    // // NOTE:  the return value for a + b becomes the invoking
    // //        instance for < and the parameter for < is the
    // //        return value for c + a

    // test some large numbers
    // Number test;
    // test.setValue(1234567890);
    // cout << test.getInteger() << " " << test.getString() << endl;
    // test.setValue(1100200000);
    // cout << test.getInteger() << " " << test.getString() << endl;
    // test.setValue(1000000002);
    // cout << test.getInteger() << " " << test.getString() << endl;
    // test.setValue(1002003004);
    // cout << test.getInteger() << " " << test.getString() << endl;
    // test.setValue(1000000100);
    // cout << test.getInteger() << " " << test.getString() << endl;

    // test all values between 0 and 2,000,000,000
    // recall that an integer takes 32 bits and the
    // largest signed integer is 2147483647
    // char x;
    // for (int i = 0; i <= 2000000000; i++) {
    //     test.setValue(i);
    //     cout << test.getInteger() << "  " << test.getString() << endl;
    //     if ((i + 1) % 50 == 0) cin.get(x);
    // }
    // return 0;
}