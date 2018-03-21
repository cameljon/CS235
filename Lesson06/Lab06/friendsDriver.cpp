#include <iostream>
#include <string>
using namespace ::std;
#include "Friends.h"
#include "FullNameB.h"

const int NUMBER_NAMES = 11;

const string names[NUMBER_NAMES] = {
    "Not in use",      // 0
    "addFront",        // 1
    "addRear",         // 2
    "removeFront",     // 3
    "removeRear",      // 4
    "= Operator",      // 5
    "isSorted",        // 6
    "findFriend",      // 7
    "retrieveFriend",  // 8
    "printAll",        // 9
    "clearAll"         // 10
};

int menu();

int main()
{
    Friends myFriends;
    // list of work variables
    Friends  copyOfFriends;
    int      choice = -100;
    FullName work;
    int      w;
    int      loc;
    bool     result;
    char     first[20], last[30], middle;

    // main loop
    while (choice != -1) {
        choice = menu();
        switch (choice) {
            case 1:
                cout << "Enter first middle last names of friend to add to the front of the list\n";
                cin >> first >> middle >> last;
                myFriends.addFront(FullName(first, middle, last));
                break;
            case 2:
                cout << "Enter first middle last names of friend to add at the end of the list\n";
                cin >> first >> middle >> last;
                myFriends.addRear(FullName(first, middle, last));
                break;
            case 3:
                result = myFriends.removeFront();
                cout << "removeFront called with return value of " << result << endl;
                break;
            case 4:
                result = myFriends.removeRear();
                cout << "removeRear called with return value of " << result << endl;
                break;
            case 5:
                copyOfFriends = myFriends;
                break;
            case 6:
                result = myFriends.isSorted();
                cout << "isSorted called with return value of " << result << endl;
                break;
            case 7:
                cout << "Enter the first name of the friend to search for ";
                cin >> first;
                loc = myFriends.findFriend(first);
                cout << first << " found in location " << loc << endl;
                break;
            case 8:
                cout << "starting with 1, input the requested location ";
                cin >> w;
                work = myFriends.retrieveFriend(w);
                cout << "location " << w << " holds " << work << endl;
                break;
            case 9:
                myFriends.printAll(cout);
                break;
            case 10:
                myFriends.clearAll();
                break;
            default:
                break;
        };  // end switch
    }       // end while
    return 0;
}  // end main

int menu()
{
    cout << endl << endl;
    cout << "Select for the following = use -1 to quit" << endl;
    for (int i = 1; i < NUMBER_NAMES; i++) cout << i << ' ' << names[i] << endl;
    int choice;
    cin >> choice;
    return choice;
}
