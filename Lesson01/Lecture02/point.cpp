#include "point.h"
#include <cmath>

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

int Point::location()
{
	if (this->x == 0 || this->y == 0)
	{
		return 0;
	}	
	else if (this->x > 0 && this->y > 0)
	{
		return 1;
	}
	else if (this->x <0 && this->y > 0)
	{
		return 2;
	}
	else if (this->x < 0 && this->y < 0)
	{
		return 3;
	}
	else // Last remaining case. x > 0 and y < 0
	{
		return 4;
	}
}