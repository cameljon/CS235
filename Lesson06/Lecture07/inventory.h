//                Inventory Class
//   CIS 235      Lecture 7  -  Array of Objects
//                Array of Classes

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
using std::ostream;

#include "container.h"

const int MAX_CELLS = 20;

class inventory {
   public:
    inventory(void);               //  Default Constructor
    inventory(const inventory &);  //  Copy Constructor

    ~inventory(void);  //  Destructor

    bool isFull(void) const;

    bool placeInto(const container &);

    int search(const char *d) const;  // search for a container with
                                      //  a description of d

    container findLargestContainer(void) const;

    void printAll(ostream &) const;
    void printOne(ostream &, int whichOne) const;

   private:
    container data[MAX_CELLS];

    int placer;

    void displayCell(ostream &, int cell) const;
};
#endif