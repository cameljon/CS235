// window.h
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
using std::ostream;

#include "Pointb.h"
//   Window on the screen   the point (0,0) is the upper left corner of the screen
class Window {
    friend ostream &operator<<(ostream &, const Window &);

   public:
    Window(void);
    Window(int leftRow, int leftColumn, int rightRow, int rightColumn);
    Window(const Point &left, const Point &right);
    Window(const Window &);

    ~Window(void);

    Window &setLeft(const Point &);
    Window &setRight(const Point &);

    const Window &operator=(const Window &);

    int perimeter(void) const;

    Window &moveHor(int amount);

    Window &moveVer(int amount);

    const Window &print(ostream &) const;   // need const return
    static long   getActiveWindowes(void);  // cannot declare const

    int  area(void) const;       // will return the area of the window
    bool validData(void) const;  // check if uLeft and lRight valid points

   private:
    Point uLeft;   //  Upper Left point of the window
    Point lRight;  //  Lower right point of the window

    const long idNumber;  //  assign a unique id to each window

    static long      activeWindowes;  //  class data
    static long      idGenerator;     //  class data
    static const int MAX_ROWS;        //  class data
    static const int MAX_COLS;        //  class data
};

#endif
