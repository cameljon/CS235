//    CIS 235     Lecture 7
//    Driver Program  Inventory of Containers
//        Client Function to input one container into an inventory

#include <cstring>
#include <iostream>
#include "container.h"
#include "inventory.h"
using namespace ::std;

bool keyboardInput(inventory &);  // user written function

int main(void)
{
    inventory inv;
    int       howMany, i;
    cout << "Enter the number of items in the inventory ";
    cin >> howMany;
    for (i = 1; i <= howMany; i++) {
        if (keyboardInput(inv))
            cout << "ADDED\n";
        else
            cout << "No More Room - NOT Added\n";
    }

    inv.printAll(cout);
    char desc[30];
    cout << "Try the search" << endl;
    cout << "Enter a one word description to search for "
         << "enter done when finished ";
    while (cin >> desc, strcmp(desc, "done") != 0) {
        i = inv.search(desc);
        if (i == -1)
            cout << "Not Found" << endl;
        else {
            cout << "Found in cell " << i << endl;
            inv.printOne(cout, i);
        }
    }  // end while
    cout << "Print all items\n";
    inv.printAll(cout);

    // Lesson 6: Lecture 7 step 3 instructions
    container theLargest;
    theLargest = inv.findLargestContainer();
    cout << "The largest container is " << theLargest.getSize() << " "
         << theLargest.getUsed() << " " << theLargest.getDesc() << endl;

    // test inventory copy constructor
    inventory dup(inv);
    cout << "\nPrint all of copy\n";
    dup.printAll(cout);
    return 0;
}

bool keyboardInput(inventory &in)
{
    if (in.isFull()) return false;
    int  size, used;
    char desc[200];
    cout << "Enter size, used, and description(no spaces):" << endl;
    cin >> size >> used >> desc;
    // no need for a work container variable
    //    call a container constructor as the parameter
    in.placeInto(container(size, used, desc));
    return true;
}

// SAMPLE OUTPUT
//
// Enter the number of items in the inventory 3
// Enter size, used, and description(no spaces):
// 12
// 1
// first
// ADDED
// Enter size, used, and description(no spaces):
// 2
// 1
// second
// ADDED
// Enter size, used, and description(no spaces):
// 9
// 1
// third
// ADDED
// List of all filled cells in inventory

// Capacity 12 Used 1 Description first
// Capacity 2 Used 1 Description second
// Capacity 9 Used 1 Description third
// Try the search
// Enter a one word description to search for enter done when finished third
// Found in cell 2
// Capacity 9 Used 1 Description third
// done
// Print all items
// List of all filled cells in inventory

// Capacity 12 Used 1 Description first
// Capacity 2 Used 1 Description second
// Capacity 9 Used 1 Description third
// The largest container is 12 1 first

// Print all of copy
// List of all filled cells in inventory

// Capacity 12 Used 1 Description first
// Capacity 2 Used 1 Description second
// Capacity 9 Used 1 Description third
