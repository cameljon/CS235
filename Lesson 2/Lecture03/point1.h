//   CS 235
//   Lecture 03 - point class with constructors and a destructor

#include <iostream>
using namespace::std;

#ifndef POINT_H    //  used to keep this file from being presented
#define POINT_H    //  to the C++ Compiler more than 1 time


class Point {
	public:
		// Constructor Functions
		Point(void);                    // Default constructor
		Point(double xV, double yV);    // 2 Argument constructor
		Point(const Point &);           // Copy constructor
		Point(double);                  // Set both x and y the same parameter
		Point(const Point &, const Point &);  // x and y are the sum of the
											  // x and y from both parameters
	//  Destructor Function 
		~Point(void);                   // One and only destructor

	//   = operator and copyTo function ******************************
		void copyTo( Point & copy) const;
		
		const Point & operator = ( const Point & right);

    //   Lecture 02 functions

		void   setX( double xV );

		void   setY( double yV );

		void   set(double value, char whichOne);  // use 'x' for x and use 'y' for y    

		double getX(void)         const;

		double getY(void)         const;

		double get(char whichOne) const;          // use 'x' for x and use 'y' for y                    

		void   print(ostream & w) const;

		double distance(void)     const;

		void   input(void);

		Point  move( double xC, double yC) const;

		Point * getAddress();
	private:

		double x,
			   y;
};


#endif