//      point.cpp

#include <iostream>
using std::ostream;

#include "PointB.h"

ostream& operator<<(ostream& out, const Point& r)
{
    out << '(' << r.getRow() << ',' << r.getColumn() << ')';
    return out;
}

Point::Point(void)
{
    setRow(0).setColumn(0);  //  use of function chaining
}

Point::Point(int rowV, int columnV)
{
    setRow(rowV).setColumn(columnV);  //  use of function chaining
}

Point::Point(const Point& old)
{
    setRow(old.getRow()).setColumn(old.getColumn());  //  use of function chaining
}

Point::~Point(void) {}

int Point::getRow(void) const { return row; }

int Point::getColumn(void) const { return column; }

Point& Point::setRow(int a)
{
    row = a;
    return *this;  //  return alias to invoking instance
}  //     allows for chaining member functions

Point& Point::setColumn(int column)
{
    (*this).column = column;  // Some programmers pick the same name for the
    return *this;             // parameter as the instance field
}  // Use (*this).column to refer to the instance field

const Point& Point::operator=(const Point& r)
{
    if (this == &r) return *this;  // for function chaining
    row    = r.row;
    column = r.column;
    return *this;
}

const Point& Point::print(ostream& w) const
{
    w << '[' << getRow() << ',' << getColumn() << ']';
    return *this;
}
