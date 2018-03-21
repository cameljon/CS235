/**
    CS235 Project 1, testStates.h
    Purpose: Test class for states class

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#ifndef TESTSTATES_H
#define TESTSTATES_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "states.h"

class TestStates {
   public:
    // Default constructor
    TestStates();
    // Default destructor
    ~TestStates();

    void test(bool, std::string);  // (TEST) Output test results
    void testConstructors();       // (TEST) Default constructors
    void testSetGet();             // (TEST) Setters and getters
    void testPrint();              // (TEST) Printers

    static void allTests();  // Runs all tests in test class
};

#endif
