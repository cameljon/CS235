/**
    CS235 Project 1, testStates.cpp
    Purpose: Test class for the states class

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#include "testStates.h"
using namespace std;

TestStates::TestStates() {}

TestStates::~TestStates() {}

void TestStates::allTests()
{
    TestStates test;
    test.testConstructors();
    test.testSetGet();
    test.testPrint();
    cout << "All tests done!" << endl;
}

void TestStates::test(bool condition, string text)
{
    cout << text << ": ";
    if (condition) {
        cout << "passed" << endl;
    }
    else {
        cout << "failed" << endl;
    }
}

void TestStates::testConstructors()
{
    cout << "Testing constructors: " << endl;
    {  // Default constructor
        State a;
        test(a.getStateName() == "", "Should be empty string");
        test(a.getStateYear() == 0, "Should be initialized to 0");
    }
    {  // Copy constructor
        State a("ABCD", "AB", 1234, 2345678, "ABCDEFG");
        State b(a);
        test(b.getStateName() == "ABCD", "Should be ABCD");
        test(b.getStateAbbrev() == "AB", "Should be AB");
        test(b.getStateYear() == 1234, "Should be 1234");
        test(b.getStatePop() == 2345678, "Should be 2345678");
        test(b.getStateCapitol() == "ABCDEFG", "Should be ABCDEFG");
    }
    {  // Param constructor
        State a("STATE", "ST", 1918, 23456789, "CAPITOL");
        test(a.getStateName() == "STATE", "Should be STATE");
        test(a.getStateAbbrev() == "ST", "Should be ST");
        test(a.getStateYear() == 1918, "Should be 1918");
        test(a.getStatePop() == 23456789, "Should be 23456789");
        test(a.getStateCapitol() == "CAPITOL", "Should be CAPITOL");
    }
    // No errors for testing destructor
}

void TestStates::testSetGet()
{
    cout << "Testing setters and getters: " << endl;
    {  // Test setStateName(), getStateName()
        State a;
        a.setStateName("TEST STATE");
        test(a.getStateName() == "TEST STATE", "Should be TEST STATE");
    }
    {  // Test setStateAbbrev(), getStateAbbrev()
        State a;
        a.setStateAbbrev("TS");
        test(a.getStateAbbrev() == "TS", "Should be TS");
    }
    {  // Test setStateYear(), getStateYear()
        State a;
        a.setStateYear(2018);
        test(a.getStateYear() == 2018, "Should be 2018");
    }
    {  // Test setStatePop(), getStatePop()
        State a;
        a.setStatePop(123456789);
        test(a.getStatePop() == 123456789, "Should be 123456789");
    }
    {  // Test setStateCapitol(), getStateCapitol
        State a;
        a.setStateCapitol("TEST CAPITOL");
        test(a.getStateCapitol() == "TEST CAPITOL", "Should be TEST CAPITOL");
    }
}

void TestStates::testPrint()
{
    cout << "Testing printers: " << endl;
    {  // Test printStateName()
        State a;
        a.setStateName("TEST STATE");
        cout << "Test printStateName() - Should be TEST STATE: ";
        a.printStateName();
        cout << endl;
    }
    {  // Test printStateAbbrev()
        State a;
        a.setStateAbbrev("TS");
        cout << "Test printStateAbbrev() - Should be TS: ";
        a.printStateAbbrev();
        cout << endl;
    }
    {  // Test printStateYear()
        State a;
        a.setStateYear(2018);
        cout << "Test printStateYear() - Should be 2018:  ";
        a.printStateYear();
        cout << endl;
    }
    {  // Test printStatePop()
        State a;
        a.setStatePop(123456789);
        cout << "Test printStatePop() - Should be 123456789: ";
        a.printStatePop();
        cout << endl;
    }
    {  // Test printStateCapitol()
        State a;
        a.setStateCapitol("TEST CAPITOL");
        cout << "Test printStateCapitol() - Should be TEST CAPITOL ";
        a.printStateCapitol();
        cout << endl;
    }
}