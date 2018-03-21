//     Window.cpp
#include <iostream>
using std::ostream;

#include <cmath>
#include "Window.h"

ostream& operator<<(ostream& out, const Window& r)
{
    out << r.uLeft << ' ' << r.lRight;
    //  << operator for window class uses << operator for point class
    return out;
}

//        Declare static member
long Window::activeWindowes = 0;

long Window::idGenerator = 1000;

const int Window::MAX_ROWS = 1024;
const int Window::MAX_COLS = 1280;

Window::Window(void)  // Member initialization list
    : uLeft(0, 0), lRight(MAX_ROWS - 1, MAX_COLS - 1), idNumber(idGenerator++)
{
    activeWindowes++;
}

Window::Window(int leftRow, int leftColumn, int rightRow, int rightColumn)
    : uLeft(leftRow, leftColumn), lRight(rightRow, rightColumn), idNumber(idGenerator++)
{
    activeWindowes++;
}

Window::Window(const Window& other)
    : uLeft(other.uLeft), lRight(other.lRight), idNumber(idGenerator++)
{
    activeWindowes++;
}

Window::Window(const Point& left, const Point& right)
    : uLeft(left), lRight(right), idNumber(idGenerator++)
{
    activeWindowes++;
}

Window::~Window(void) { activeWindowes--; }

int Window::perimeter(void) const
{
    return 2 *
           (abs(uLeft.getRow() - lRight.getRow()) + abs(uLeft.getColumn() - lRight.getColumn()));
}

Window& Window::moveHor(int amount)
{
    uLeft.setColumn(uLeft.getColumn() + amount);
    lRight.setColumn(lRight.getColumn() + amount);
    return *this;
}

Window& Window::moveVer(int amount)
{
    uLeft.setRow(uLeft.getRow() + amount);
    lRight.setRow(lRight.getRow() + amount);
    return *this;
}

const Window& Window::operator=(const Window& r)
{
    if (this == &r) return *this;
    this->uLeft  = r.uLeft;   // = operator for window class
    this->lRight = r.lRight;  //  uses = operator for point class
    //    NOTE:   cannot change idNumber since it is const
    //    For all classes with const data, the = operator MUST
    //        be written - the default = operator supplied by
    //        the compiler will not work because of const data fields
    return *this;
}
const Window& Window::print(ostream& w) const
{
    w << "Upper Left ";
    uLeft.print(w);
    w << "  Lower Right ";
    lRight.print(w);
    return *this;
}

long Window::getActiveWindowes(void) { return activeWindowes; }

Window& Window::setLeft(const Point& r)
{
    this->uLeft = r;
    return *this;
}

Window& Window::setRight(const Point& r)
{
    this->lRight = r;
    return *this;
    return *this;
}

int Window::area(void) const  // will return the area of the window
{
    if (!this->validData()) return -1;
    int length = lRight.getColumn() - uLeft.getColumn();
    int height = lRight.getRow() - uLeft.getRow();
    return abs(length * height);
}

bool Window::validData(void) const  // check if uLeft and lRight valid points
{
    // row and colume of uLeft and lRight >= 0
    if (uLeft.getRow() < 0 || uLeft.getColumn() < 0) return false;
    if (lRight.getRow() < 0 || lRight.getColumn() < 0) return false;
    // row of uLeft and lRight < MAX_ROWS
    if (uLeft.getRow() >= MAX_ROWS || lRight.getRow() >= MAX_ROWS) return false;
    // column of uLeft and lRight are < MAX_COLS
    if (uLeft.getColumn() >= MAX_COLS || lRight.getColumn() >= MAX_COLS) return false;
    // column of uLeft < lRight
    if (uLeft.getColumn() >= lRight.getColumn()) return false;
    // row of uLeft < lRight
    if (uLeft.getRow() >= lRight.getRow()) return false;
    return true;
}