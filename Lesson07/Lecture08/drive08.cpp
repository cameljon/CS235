// CS 235 Class Example on Composition of Classes  Lecture 8
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "PointB.h"
#include "window.h"
//  Client Functions
Point   makePoint(int xV, int yV);
Window  makeWindow(int xLeft, int yLeft, int xRight, int yRight);
Window  makeWindow(const Point &left, const Point &right);
Point & inputPoint(Point &);
Window &inputWindow(Window &);
void    testArea();
void    testValidData();

int main()
{
    Window a(1, 4, 3, 2);
    a.print(cout);
    cout << endl;
    a.moveHor(5).moveVer(7).print(cout);
    cout << endl << "Perimeter is " << a.perimeter() << endl;
    Point b;
    b = makePoint(50, 75);
    cout << "The point b is ";
    b.print(cout);
    cout << endl;

    //  Example of function chaining
    makeWindow(Point(4, 10), Point(12, 18)).moveVer(6).moveHor(-3).print(cout);
    cout << endl;

    // Test area
    testArea();
    testValidData();
    return 0;
}  //   end of main

Point makePoint(int a, int b) { return Point(a, b); }

Window makeWindow(int xLeft, int yLeft, int xRight, int yRight)
{
    return Window(xLeft, yLeft, xRight, yRight);
}

Window makeWindow(const Point &left, const Point &right) { return Window(left, right); }

Point &inputPoint(Point &p)
{
    cout << "Enter row and column for a point ";
    int workX, workY;
    cin >> workX >> workY;
    p.setRow(workX).setColumn(workY);
    return p;
}

Window &inputWindow(Window &b)
{
    Point workUleft, workLright;
    cout << "Enter upper left corner ";
    inputPoint(workUleft);
    b.setLeft(workUleft);
    cout << "Enter lower right corner ";
    inputPoint(workLright);
    b.setRight(workLright);
    return b;
}

void testArea()
{
    Window a(1, 1, 5, 5);
    a.print(cout);
    cout << endl;
    cout << "Area of window: " << a.area() << endl;
}

void testValidData()
{
    // test points < 0
    Window a(-1, 0, 3, 3);
    a.print(cout);
    cout << endl;
    cout << "This point is valid: " << a.validData() << endl;
    Window b(1, 0, 3, 3);
    b.print(cout);
    cout << endl;
    cout << "This point is valid: " << b.validData() << endl;
    // test points > MAX_ROWS
    Window c(1000, 1000, 1024, 1100);
    c.print(cout);
    cout << endl;
    cout << "This point is valid: " << c.validData() << endl;
    Window d(1000, 1000, 1023, 1100);
    d.print(cout);
    cout << endl;
    cout << "This point is valid: " << d.validData() << endl;
    // test points > MAX_COLS
    Window e(1000, 1000, 1023, 1280);
    e.print(cout);
    cout << endl;
    cout << "This point is valid: " << e.validData() << endl;
    Window f(1000, 1000, 1023, 1279);
    f.print(cout);
    cout << endl;
    cout << "This point is valid: " << f.validData() << endl;
    // test uLeft column > lRight column
    Window g(0, 2, 1, 1);
    g.print(cout);
    cout << endl;
    cout << "This point is valid: " << g.validData() << endl;
    Window h(1, 1, 2, 2);
    h.print(cout);
    cout << endl;
    cout << "This point is valid: " << h.validData() << endl;
    // test uLeft row > lRight row
    Window i(2, 0, 1, 1);
    i.print(cout);
    cout << endl;
    cout << "This point is valid: " << i.validData() << endl;
    Window j(0, 0, 2, 2);
    j.print(cout);
    cout << endl;
    cout << "This point is valid: " << j.validData() << endl;
}

// Upper Left [1,4]  Lower Right [3,2]
// Upper Left [8,9]  Lower Right [10,7]
// Perimeter is 8
// The point b is [50,75]
// Upper Left [10,7]  Lower Right [18,15]
// Upper Left [1,1]  Lower Right [5,5]
// Area of window: 16
// Upper Left [-1,0]  Lower Right [3,3]
// This point is valid: 0
// Upper Left [1,0]  Lower Right [3,3]
// This point is valid: 1
// Upper Left [1000,1000]  Lower Right [1024,1100]
// This point is valid: 0
// Upper Left [1000,1000]  Lower Right [1023,1100]
// This point is valid: 1
// Upper Left [1000,1000]  Lower Right [1023,1280]
// This point is valid: 0
// Upper Left [1000,1000]  Lower Right [1023,1279]
// This point is valid: 1
// Upper Left [0,2]  Lower Right [1,1]
// This point is valid: 0
// Upper Left [1,1]  Lower Right [2,2]
// This point is valid: 1
// Upper Left [2,0]  Lower Right [1,1]
// This point is valid: 0
// Upper Left [0,0]  Lower Right [2,2]
// This point is valid: 1
