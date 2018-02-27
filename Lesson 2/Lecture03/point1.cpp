#include "point1.h"
#include <cmath>
//                      Constructor functions
Point::Point(void)                    // Default constructor
{
	setX(0.0);
	setY(0.0);
	cout << "**** default constructor for point object at address "
		  << this << endl;
}

Point::Point(double xV, double yV)           // 2 Argument constructor
{
	setX(xV);
	setY(yV);
	cout << "**** 2 double argument constructor for point object at address "
		  << this << endl;
}

Point::Point(const Point &other)                // Copy constructor
{
	setX( other.getX());
	setY( other.getY());
	cout << "**** copy constructor for point object at address "
		  << this << endl;
}

Point::Point(double q)
{
  setX(q);
  setY(q);
  cout << "**** one double argument constructor for point object at address "
		  << this << endl;
}

Point::Point(const Point &left , const Point & r)
{
	setX( left.getX() + r.getX());
	setY( left.getY() + r.getY());
	cout << "**** two point argument constructor for point object at address "
		  << this << endl;
}
//              End Constructors
//---------------------------------------------------------------------------
Point::~Point(void)                   // One and only destructor
{
	cout << "**** point variable at address " << this <<" is leaving"<< endl;
}

//---------------------------------------------------------------------------
	 //   = operator and copyTo function ******************************

void Point::copyTo( Point & copy) const
{
	copy.setX(getX());
	copy.setY((*this).getY());
	return;
}

const Point & Point::operator = ( const Point & right)
{
	if(this == & right) return *this;
	this->setX(right.getX());
	setY(right.getY());
	return *this;
}



// Lecture 02 Member Functions
void Point::setX( double xV)
{
	x = xV;
}

void Point::setY( double yV)
{
	y = yV;
}

void   Point::set(double value, char whichOne)
{
	switch ( whichOne)
	{
	case 'x': case 'X': setX(value);
			            break;
	case 'y': case 'Y': setY(value);
			            break;
	}
	return;
}

double Point::getX(void) const
{
	return x;
}

double Point::getY(void) const
{
	return y;
}

double Point::get(char whichOne)  const
{
	switch(whichOne)
	{
	case 'x': case 'X':  return getX();
	case 'y': case 'Y':  return getY();
	}
	return 0;  //  will not execute with a valid parameter
}

void Point::print(ostream & w)  const
{
	w << '(' << getX() << ',' << getY() << ')';
}

double Point::distance(void) const
{
	return sqrt( pow(getX(),2) + pow(getY(),2));
}

void Point::input(void)
{
	double xV,yV;
	cout <<"Enter x and y values: ";
	cin >> xV >> yV;
	setX(xV);
	setY(yV);
}

Point Point::move( double xC, double yC) const
{
	Point answer;
		answer.setX( getX() + xC );   //  getX will be called by the same invoking
		                              //    instance that called the move function
		// OR
		answer.setX( (*this).getX() + xC);  // this holds the address of
                                            //    the invoking instance
		answer.setY( getY() + yC );
		// OR
		answer.setY( this->getY() + yC);    // ->  is the same as (*    ).
	return answer;
}

Point * Point::getAddress()
{
	return this;
}