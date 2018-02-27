//   CS 235
//   Lecture 02 - point class

#include <iostream>
using namespace::std;

#ifndef POINT_H    //  used to keep this file from being presented
#define POINT_H    //  to the C++ Compiler more than 1 time


class Point {
	public:
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

		int location();
		
	private:


		double x,
			   y;
};


#endif