//    CS 235               
//    Lecture 3             - class constructor functions
//                          - class destructor function
//                          - this pointer
//                          - 3 types of memory - stack, static, heap
//                          - = operator and copyTo function
#include "point1.h"
#include <iostream>
using namespace::std;

// The following is NOT a member function
Point makePoint(double xV, double yV);
// global point
Point one(1.1,1.1);   // the memory for global variables is in the static area

int main()
{
	{
       Point test(4.3, 7.8);
       cout << "testing STACK memory" << endl;
       cout << "object values for x and y " << test.getX() << " " << test.getY() << endl;
       cout << "object variable is at memory location " << test.getAddress() << endl;
       // note the & operator returns the address of a variable
       cout << "double checking, the address is " << &test << endl;
    }
    {
       Point * testPointer = new Point(4.3, 7.8);
       cout << "testing HEAP memory" << endl;
       cout << "object values for x and y " << testPointer->getX() << " " << testPointer->getY() << endl;
       cout << "object  variable is at memory location " << testPointer->getAddress() << endl;
       // note the & operator returns the address of a variable
       cout << "double checking, the address is " << testPointer << endl;
           // the variable testPointer holds a C++ pointer ( an address ) not an object
           //       the name of the pointer is testPointer and the name of the object is *testPointer

       delete testPointer;  // return HEAP memory to avoid a MEMORY LEAK
    }

	Point two(2.2,2.2);
	static Point three(3.3,3.3);
	Point * ptr;
	ptr = new Point(4.4);      //   ask for the memory on the heap

	cout << "one two and three are at addresses " << &one << " " << &two
		  << " " << &three << endl;
	cout << "the dynamic point is at address " << ptr << endl;

	cout << "Call the distance functions " << endl
		 << one.distance()    << endl
		 << two.distance()    << endl
		 << three.distance()  << endl
		 << ptr->distance()   << endl;
	delete ptr;                //   give back the memory on the heap

	// Test other constructor functions
	Point a;       // default constructor
	Point b(two);  // copy constructor
	Point c(-3.7); // one argument constructor
	Point d(b,c);  // two point argument constructor
	return 0;
}   // end main

Point makePoint(double xV, double yV)  //NOTE: This is NOT a member function
{  Point answer;
	  answer.setX(xV);
	  answer.setY(yV);
	  return answer;
}
//     Program output
/*
**** 2 double argument constructor for point object at address 0105D160
**** 2 double argument constructor for point object at address 0022FABC
**** 2 double argument constructor for point object at address 0105D148
**** one double argument constructor for point object at address 005C84D0
one two and three are at addresses 0105D160 0022FABC 0105D148
the dynamic point is at address 005C84D0
Call the distance functions
1.55563
3.11127
4.6669
6.22254
**** point variable at address 005C84D0 is leaving
**** default constructor for point object at address 0022FA98
**** copy constructor for point object at address 0022FA80
**** one double argument constructor for point object at address 0022FA68
**** two point argument constructor for point object at address 0022FA50
**** point variable at address 0022FA50 is leaving
**** point variable at address 0022FA68 is leaving
**** point variable at address 0022FA80 is leaving
**** point variable at address 0022FA98 is leaving
**** point variable at address 0022FABC is leaving
**** point variable at address 0105D148 is leaving
**** point variable at address 0105D160 is leaving
Press any key to continue . . .
*/