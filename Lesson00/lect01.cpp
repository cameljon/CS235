//    CS 235
//    Lecture 1      - passing parametere, structures, data abstraction,
//                   - information hiding, function chaining
//                   - 3 types of memory - stack, static, heap
//                   - different ways a function can return an answer
#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

struct point {
    double x, y;
};

void setX(point& p, double xV);

void setY(point& p, double yV);

double getX(const point& p);  // I do not want to use pass by value
                              //    because of the time and memory cost

double getY(const point& p);

void print(ostream& w, const point& p);

double distance(const point& p);

point makePoint(double xV, double yV);

point* makePointPtr(double xV, double yV);

void makePoint(double xV, double yV, point& result);

void makePoint(double xV, double yV, point* ptrAns);

void input(point& p);

point move(const point& p, double xC, double yC);

//--------------------------------------------------------------------------

int main()
{
    point a;  //  a is on the stack same as auto point a;
    input(a);
    cout << "a is ";
    print(cout, a);
    cout << endl;
    static point b;  //  b is in the static area
    b = move(a, 3.2, -4.1);
    cout << "b is ";
    print(cout, b);
    cout << endl;

    // Use of function chaining
    //  If I was at 4.5, 3.2 and x changed 3 and y changed 8
    //     where would I be
    cout << "result of function chaining is ";
    print(cout, move(makePoint(4.5, 3.2), 3, 8));
    cout << endl;

    //  4 ways for the function to return an answer;

    //  1 - structure is put on the stack by the function
    point c;
    c = makePoint(12.3, 19.4);
    cout << "c is ";
    print(cout, c);
    cout << endl;
    cout << "c is " << distance(c) << " from the origin" << endl;

    //  2 - function changes caller's memory - reference parameter
    point d;
    makePoint(2.3, 8.9, d);
    cout << "d is ";
    print(cout, d);
    cout << endl;

    //  3 - functions changes caller's memory - pointer parameter
    point e;
    makePoint(12.5, 1.6, &e);  // send address of callers memory
    cout << "e is ";
    print(cout, e);
    cout << endl;

    //  4 - function returns a pointer to the answer
    point* ptr;
    ptr = makePointPtr(8.4, 3.5);
    cout << "*ptr is ";
    print(cout, *ptr);
    cout << endl;
    delete ptr;  // return heap memory
    return 0;
}

//--------------------------------------------------------------------------

void setX(point& p, double xV)
{
    p.x = xV;
    return;
}

void setY(point& p, double yV)
{
    p.y = yV;
    return;
}

double getX(const point& p)  // I do not want to use pass by value
{                            //    because of the time and memory cost
    return p.x;
}

double getY(const point& p) { return p.y; }

void print(ostream& w, const point& p)
{  //  My programming style - always call a function rather than do it yourself
    w << '(' << getX(p) << ',' << getY(p) << ')';
    return;
}

double distance(const point& p)
{  //  My programming style - avoid work variables, if possible
    return sqrt(pow(getX(p), 2) + pow(getY(p), 2));
}

point makePoint(double xV, double yV)
{
    point answer;
    setX(answer, xV);
    setY(answer, yV);
    return answer;
}

void makePoint(double xV, double yV, point& result)
{
    //   caller provides the memory
    setX(result, xV);
    setY(result, yV);
    return;
}

point* makePointPtr(double xV, double yV)
{
    point* pt;
    pt = new point;  // heap memory
    setX(*pt, xV);
    setY(*pt, yV);
    return pt;
}

void makePoint(double xV, double yV, point* ptrAns)
{
    setX(*ptrAns, xV);  // use the caller's memory
    setY(*ptrAns, yV);  // dereference the pointer to get the structure
    return;
}

void input(point& p)
{
    double xV, yV;
    cout << "Enter x and y values: ";
    cin >> xV >> yV;
    setX(p, xV);
    setY(p, yV);
    return;
}

point move(const point& p, double xC, double yC)
{  //   Call functions rather than do the work yourself
    point answer;
    setX(answer, getX(p) + xC);
    setY(answer, getY(p) + yC);
    return answer;
}
/*
Enter x and y values: 5.6 7.8
a is (5.6,7.8)
b is (8.8,3.7)
result of function chaining is (7.5,11.2)
c is (12.3,19.4)
c is 22.9706 from the origin
d is (2.3,8.9)
e is (12.5,1.6)
*ptr is (8.4,3.5)
Press any key to continue
*/