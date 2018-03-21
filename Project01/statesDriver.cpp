/**
    CS235 Project 1, statesDriver.cpp
    Purpose: To create state class using OO programming in C++.

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#include "states.h"
#include "testStates.h"
using namespace std;

int main()
{
    int selection;
    do {
        selection = State::menu();
        switch (selection) {
            case 1:
                // Ask user input to add state object
                State::manual();
                break;
            case 2:
                // Load all state information
                State::loadAll();
                break;
            case 3:
                // Print all state information loaded
                State::printTable();
                break;
            case 4:
                // Run tests for all functions in state class
                TestStates::allTests();
                break;
            case 5:
                break;
        }
    } while (selection != 5);

    return 0;
}
