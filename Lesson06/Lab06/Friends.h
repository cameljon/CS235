#ifndef FRIENDS_H
#define FRIENDS_H
#include <cstring>
#include <iostream>
using namespace ::std;
#include "FullNameB.h"

const int NUMBER_FRIENDS = 10;
class Friends {
   public:
    Friends();  // WRITTEN
    Friends(const Friends& right);

    ~Friends();  // WRITTEN

    bool isFull(void) const;   // WRITTEN
    bool isEmpty(void) const;  // WRITTEN

    // 01 addFront
    bool addFront(const FullName& right);  // return true if room and data added
    // 02 addRear
    bool addRear(const FullName& right);  // return true if room and data added  WRITTEN

    // 03 removeFront
    bool removeFront();  // return true if not empty and data removed
    // 04 removeRear
    bool removeRear();  // return true if not empty and data removed

    // 05 = Operator
    const Friends& operator=(const Friends& right);

    // 06 isSorted
    bool isSorted(
        void) const;  // return true is the names are sorted, use the < operator for FullName

    // 07 findFriend
    int findFriend(const char* firstName) const;  // return first location where a FullName
                                                  // is found with the same firstName
                                                  // return -1 is not found

    // 08 retrieveFriend                // WRITTEN
    FullName retrieveFriend(int location)
        const;  // starting at 1, i.e. location 1 means array cell 0, return the FullName in the
                //   requested location
                //   if the location is not valid return a "dummy" FullName object

    // 09 printAll
    void printAll(ostream& out) const;  // WRITTEN

    // 10 clearAll                             // WRITTEN
    void clearAll(void);  // will reset the Friends object to the EMPTY state

   private:
    int itemCount;  // subscript of first empty cell, work left to right

    FullName info[NUMBER_FRIENDS];
};
#endif