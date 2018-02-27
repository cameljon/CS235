//    CS 235 Lecture 2   Visual Studio 2015
//    point class      - defining classes , writing member functions
#include <iostream>
using namespace::std;

#include "point.h"
// The following is NOT a member function
Point makePoint(double xV, double yV);

int main()
{  
	// Test the 7 cases.
	Point test;
	test.setX(0);
	test.setY(0);
	cout << test.location() << endl;
	test.setX(0);
	test.setY(1);
	cout << test.location() << endl;
	test.setX(1);
	test.setY(0);
	cout << test.location() << endl;
	test.setX(2);
	test.setY(4);
	cout << test.location() << endl;
	test.setX(-3);
	test.setY(5);
	cout << test.location() << endl;
	test.setX(-4);
	test.setY(-7);
	cout << test.location() << endl;
	test.setX(6);
	test.setY(-2);
	cout << test.location() << endl;

	Point a;
	a.input();
	cout << "point a is ";
	a.print(cout);
	cout << endl;
	Point b;
	b = makePoint(4.3,8.2);
	cout << "point b is ";
	b.print(cout);
	cout << endl;
	// change the value in b
	b.setX(10.4);
	b.set(2.1,'y');
	cout << "point b is now ";
	b.print(cout);
	cout << endl;
	Point c;
	c = b.move(-2.6,-8.4);
	cout << "point c is ";
	c.print(cout);
	cout << endl;
	cout << "c is " << c.distance() << " from the origin\n";

	// Function Chaining with Classes
	//    The return value of one method becomes the invoking
	//          instance of the next method
	// Use of function chaining   If I was at 4.5, 3.2 and
			// x changed 3 and y changed 8 where would I be
	cout << "Testing function chaining ";
	makePoint(4.5,3.2).move( 3, 8 ).print(cout);
	//  The invoking instance for move is the return value of makePoint
	//  The invoking instance for print is the return value of move
	cout << endl;

	//  Determine if point a or point b is farther from the origin
	if ( a.distance() > b.distance())
		cout << "a is farther\n";
	else
		cout << "b is farther\n";
	return 0;
}
//   PROGRAM OUTPUT
/*
Enter x and y values: 8.0 9.0
point a is (8,9)
point b is (4.3,8.2)
point b is now (10.4,2.1)
point c is (7.8,-6.3)
c is 10.0265 from the origin
Testing function chaining (7.5,11.2)
a is farther
*/

Point makePoint(double xV, double yV)  //NOTE: This is NOT a member function
{  
	Point answer;
	  answer.setX(xV);
	  answer.setY(yV);
	return answer;
}