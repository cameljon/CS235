#include "clockPart2.h"

void visualTests();
void visualTestForConstructors();
void visualTestForSetAheadAnBackMembererFunctions();

// Students - following the pattern given for the 2 visual test functions above
//                add the following 2 visual test functions to your code
//                1.  write the test code for each visual test
//                2.  call each function from the visualTests() function
void visualTestForSyncAndAssignmentOperator();
void visualTestForDifference();
void visualTestForSyncAndAssignmentOperator();
void visualTestForDifference();

void computerTests();

int main()
{
	visualTests();
	computerTests();
	return 0;
}

void visualTests()
{
	visualTestForSyncAndAssignmentOperator();
	visualTestForDifference();
	visualTestForConstructors();
	visualTestForSetAheadAnBackMembererFunctions();

}

void visualTestForSyncAndAssignmentOperator()
{
	// Test sync and = operator.
	cout << "\n\nvisualTestForSyncAndAssignmentOperator()" << endl;
	cout << "      Clock 1 set to 12:15, true true." << endl;
	Clock test1(12, 15, true, true);
	cout << test1.getMinutes() << " is the current minute. Should be 15." << endl;
	cout << test1.getHours() << " is the current hour. Should be 12." << endl;
	cout << "      Clock 2 set to 15:30, true true." << endl;
	Clock test2(15, 30, true, true);
	cout << test2.getMinutes() << " is the current minute. Should be 30." << endl;
	cout << test2.getHours() << " is the current hour. Should be 15." << endl;
	cout << "      Setting clock 2 to clock 1 with sync." << endl;
	test1.sync(test2);
	cout << test2.getMinutes() << " is the current minute. Should be 15." << endl;
	cout << test2.getHours() << " is the current hour. Should be 12." << endl;
	cout << "      Setting clock 1 to clock 3 with assignment operator." << endl;
	Clock test3(17, 33, true, true);
	test1 = test3;
	cout << test1.getMinutes() << " is the current minute. Should be 33." << endl;
	cout << test1.getHours() << " is the current hour. Should be 17." << endl;
}

void visualTestForDifference()
{
	// Test clock difference function.
	cout << "\n\nvisualTestForDifference()" << endl;
	cout << "      Clock 1 set to 12:15, true true." << endl;
	Clock test1(12, 15, true, true);
	cout << "      Clock 2 set to 15:30, true true." << endl;
	Clock test2(15, 30, true, true);
	int diff = test1.differenceInClocks(test2);
	string ahead = (diff > 0)? "ahead of" : "behind";
	cout << "Clock 2 is " << ahead << " clock 1 by " << abs(diff) << " minutes." << endl;
	cout << "Or " << abs(diff / 60) << " hours and " << abs(diff % 60) << " minutes." << endl; 

}

void visualTestForConstructors()
{
	cout << "\n\nvisualTestForConstructors" << endl;
	cout << "     Default Constructor" << endl;
	Clock test;
	cout << test.getMinutes() << " is the current minute" << endl;
	cout << test.getHours() << " is the current hour" << endl;
	// same test as above, but with pointers
	Clock * testPointer;
	testPointer = new Clock;
	cout << testPointer->getMinutes() << " is the current minute" << endl;
	cout << testPointer->getHours() << " is the current hour" << endl;
	cout << "     Argument Constructor" << endl;
	// STUDENTS - COMPLETE THIS SECTION  
	Clock argTest(1, 30, true, true);
	cout << argTest.getMinutes() << " is the current minute. Should be 30." << endl;
	cout << argTest.getHours() << " is the current hour. Should be 1." << endl;
	cout << argTest.getChimeOnHour() << ": getChimeOnHour should be 1." << endl;
	cout << argTest.getChimeOnHalfHour() << ": getChimeOnHalfHour should be 1." << endl;
	cout << "     Copy Constructor" << endl;
	// STUDENTS - COMPLETE THIS SECTION 
	// Using the clock we just created with param constructor.
	Clock copyTest(argTest);
	cout << argTest.getMinutes() << " is the current minute. Should be 30." << endl;
	cout << argTest.getHours() << " is the current hour. Should be 1." << endl;
	cout << argTest.getChimeOnHour() << ": getChimeOnHour should be 1." << endl;
	cout << argTest.getChimeOnHalfHour() << ": getChimeOnHalfHour should be 1." << endl;
}

void visualTestForSetAheadAnBackMembererFunctions()
{
	cout << "\n\nvisualTestForSetAheadAnBackMembererFunctions" << endl;
	cout << "     Minutes ahead and back" << endl;
	Clock test;
	test.setMinutes(30);
	test.setMinutesAhead(25);
	cout << test.getMinutes() << " should be 55" << endl;
	test.setMinutesAhead(38);
	cout << test.getMinutes() << " should be 33 " << endl;
	test.setMinutes(40);
	test.setMinutesBack(23);
	cout << test.getMinutes() << " should be 17 " << endl;
	test.setMinutesBack(20);
	cout << test.getMinutes() << " should be 57 " << endl;
	test.setMinutesAhead(20);
	cout << test.getMinutes() << " should be 17 " << endl;
	cout << "     Hours ahead and back" << endl;
	// STUDENTS - COMPLETE THIS SECTION FOR set hours ahead and back
	test.setHours(12);
	test.setHoursAhead(5);
	cout << test.getHours() << " should be 17" << endl;
	test.setHoursAhead(10);
	cout << test.getHours() << " should be 3 " << endl;
	test.setHours(9);
	test.setHoursBack(6);
	cout << test.getHours() << " should be 3 " << endl;
	test.setHoursBack(4);
	cout << test.getHours() << " should be 23 " << endl;
	test.setHoursAhead(25);
	cout << test.getHours() << " should be 0 " << endl;

}

void computerTests()
{
	// no compter tests at this time
}

