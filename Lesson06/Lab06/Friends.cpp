#include "Friends.h"

Friends::Friends() { itemCount = 0; }

Friends::Friends(const Friends& right)  // Students write code this method
{                                       // There is no formal testing of the method in the driver
                                        // students write the code
    itemCount = right.itemCount;
    for (int i = 0; i < NUMBER_FRIENDS; ++i) {
        info[i] = right.info[i];
    }
}

Friends::~Friends()
{
    // No dynamic memory in the Friends Class, Hence no code for the destructor
}

bool Friends::isFull(void) const { return itemCount >= NUMBER_FRIENDS; }

bool Friends::isEmpty(void) const { return itemCount == 0; }

bool Friends::addFront(const FullName& aPerson)
{
    // Students write the code
    if (isFull()) return false;
    for (int i = itemCount; i >= 0; --i) {
        info[i + 1] = info[i];
    }
    info[0] = aPerson;
    itemCount++;
    return true;
}

bool Friends::addRear(const FullName& aPerson)
{
    if (isFull()) return false;
    info[itemCount] = aPerson;  // uses overloaded FullName = operator
    itemCount++;
    return true;
}

bool Friends::removeFront()  // return true if not empty and data removed
{
    // Students write the code
    if (isEmpty()) return false;
    info[0].setFirstName("");
    info[0].setMiddleInitial('\0');
    info[0].setLastName("");
    for (int i = 0; i < (itemCount - 1); ++i) {
        info[i] = info[i + 1];
    }
    itemCount--;
    return true;
}
bool Friends::removeRear()  // return true if not empty and data removed
{
    // Students write the code
    if (isEmpty()) return false;
    info[itemCount].setFirstName("");
    info[itemCount].setMiddleInitial('\0');
    info[itemCount].setLastName("");
    itemCount--;
    return true;
}
const Friends& Friends::operator=(const Friends& right)
{
    // Students write the code
    itemCount = right.itemCount;
    for (int i = 0; i < NUMBER_FRIENDS; ++i) {
        info[i] = right.info[i];
    }
    return *this;
}

bool Friends::isSorted(void) const  // return true is the names are sorted
{
    // Students write the code
    for (int i = 0; i < itemCount - 1; ++i) {
        if (info[i + 1] < info[i]) {
            return false;
        }
    }
    return true;
}

void Friends::printAll(ostream& out) const
{
    if (isEmpty())
        out << "No data " << endl;
    else {
        for (int i = 0; i < itemCount; i++) {
            out << info[i] << endl;  // uses FullName << operator
        }
    }
    return;
}

int Friends::findFriend(const char* firstName) const
{
    // Location is not the index? Location starts at 1?
    // Using location logic from retrieveFriend()
    if (isEmpty()) return -1;
    for (int i = 0; i < itemCount; i++) {
        if (!strcmp(info[i].getFirstName(), firstName)) return i + 1;
    }
    return -1;
}

FullName Friends::retrieveFriend(int location) const  // starting at 1 return the FullName in the
{                                                     //   requested location
    //  The valid subscripts are 0, 1, 2, ..., (itemCount - 1 )
    //  The valid location values are 1, 2, 3, ..., itemCount
    if (location < 1 || location > itemCount) {
        return FullName("Dummy", 'X', "Person");
    }
    return info[location - 1];
}

void Friends::clearAll(void) { itemCount = 0; }
