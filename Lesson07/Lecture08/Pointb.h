// CS 235 Class Example on Composition of Classes  Lecture 8
//    A point on the computer screen 
//    Upper left corner is row 0, column 0
//        Move down,  the row increases.     Move up, the row decreases
//        Move right, the column increases.  Move left, the column decreases
//      point.h
#ifndef POINT_H
#define POINT_H
#include <iostream>
using std::ostream;

class Point {
friend ostream & operator<<(ostream &, const Point &);
	public:

	  Point (void);
	  Point (int rowV, int columnV);
      Point (const Point & );

	  ~Point(void);

	  int     getRow(void) const;
	  int     getColumn(void) const;

	  Point & setRow(int a);        // return alias to invoking instance
	  Point & setColumn(int a);     //    allows for function chaining

	  const Point & operator=(const Point &);

	  const Point & print(ostream &) const;

	private:

	  int row;
	  int column;
};

#endif


