# CS235: Project 1 - States class

Author: Jon Volden
Date: 3/21/2018
Instructor: Isabelle Chen

## Objective

The goal was to create an object-oriented class to store and retrieve information about states of the United States.

## Implementation

The main class is in states.h and states.cpp. The statesDriver.cpp is used as a driver file to access the functions of the class. Also, test functions were split up into separate files, testStates.h and testStates.cpp.

To get state, abbreviation, and capital names, the std::getline() function is used in a separate function State::getInput(). This was used in State::manual() for readability and to handle spaces in user input.

The states class uses the Vector STL to handle the storing of the states objects. It is not limited to 50 states, but maybe should be? From the vector STL we only use the push_back and size member functions. This could be expanded so states can be modified or deleted.

For testing purposes there is a State::loadall() to add all states automatically.

The TestStates class is used to test all the functions of the State class. The tests include constructors, destructor (no error by default), setters, getters, and printer functions. The static functions are not explicitly tested.

## Issues (To-Do)

* Modify state objects
* Delete state objects
* Print individual state objects
* Add field validation for object fields:
  1. Year within certain range
  2. Abbreviation only 2 capitol letters
  3. State and capital names have no invalid chars
  4. Population greater than 0