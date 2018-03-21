//       CIS 235    inventory.cpp    Lecture 7

#include "inventory.h"
#include <cstring>
#include <iostream>
using namespace ::std;

container inventory::findLargestContainer(void) const
{
    container largestContainer(0, 0, "");
    for (int i = 0; i < 20; ++i) {
        if (data[i].getUsed() && data[i].getSize() > largestContainer.getSize()) {
            largestContainer = data[i];
        }
    }
    return largestContainer;
}

inventory::inventory(void)
{
    placer = 0;  // NOTE: Default containter constructor called
}  //        to fill all cells in the container array data

inventory::inventory(const inventory& other)
{
    // NOTE: Default containter constructor called
    //        to fill all cells in the container array data
    placer = 0;
    for (int i = 0; i < other.placer; i++) {
        (*this).placeInto(other.data[i]);
    }
}

inventory::~inventory(void)
{
    //  container desctructor will be called for
    //      all cells in the array data
}

bool inventory::isFull(void) const { return placer >= MAX_CELLS; }

bool inventory::placeInto(const container& c)
{
    if (isFull()) return false;
    data[placer] = c;  // use overloaded container = operator
    placer++;
    return true;
}

int inventory::search(const char* d) const
{
    for (int i = 0; i < placer; i++) {
        if (strcmp(data[i].getDesc(), d) == 0) return i;
    }
    return -1;  // failure
}

void inventory::printAll(ostream& w) const
{
    if (placer == 0) {
        w << "Inventory is Empty" << endl;
        return;
    }
    w << "List of all filled cells in inventory" << endl << endl;
    for (int i = 0; i < placer; i++) displayCell(w, i);
}

void inventory::printOne(ostream& w, int whichOne) const
{
    if (whichOne < 0 || whichOne >= placer) {
        w << "No Such Cell" << endl;
        return;
    }
    displayCell(w, whichOne);
}

void inventory::displayCell(ostream& w, int cell) const
{
    w << "Capacity " << data[cell].getSize() << " Used " << data[cell].getUsed() << " Description "
      << data[cell].getDesc() << endl;
}
