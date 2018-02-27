// FullName Tester implementation file
#include "FullNameTester.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace::std;

//  All of the code for the FullNameTester class has been written
//  Students should study this code to help understand how automated testing of
//               the methods can be accomplished

FullNameTester::FullNameTester()
{
}
	

int FullNameTester::testGetAndSetFirstName()      const
{
	const char testFirstName[] = "This is a test of first name";
	FullName work;
	work.setFirstName(testFirstName);
	if ( strcmp(work.getFirstName(),testFirstName) != 0 ) return 0;
    	return TEST_POINTS;
}

int FullNameTester::testGetAndSetMiddleInitial()  const
{
	FullName work;
	work.setMiddleInitial('A');
	if ( 'A' != work.getMiddleInitial() ) return 0;
	return TEST_POINTS;
}

int FullNameTester::testGetAndSetLastName()       const
{
	const char testLastName[] = "This is a test of last name";
	FullName work;
	work.setLastName(testLastName);
	if ( strcmp(work.getLastName(),testLastName) != 0 ) return 0;
	return TEST_POINTS;
}
	
int FullNameTester::testIsSmaller()               const
{
	FullName a("Mary",'L',"Jones");
	FullName b("Mary",'L',"Jones");
	FullName c("Mary",'E',"Jones");
	FullName d("Mart",'E',"Jones");
	FullName e("Mary",'L',"Janes");
	
	if ( a.isSmaller(b) ) return 0;
	if ( a.isSmaller(c) ) return 0;
	if ( a.isSmaller(d) ) return 0;
	if ( a.isSmaller(e) ) return 0;
	return TEST_POINTS;
}

int FullNameTester::testCopyTo()                  const
{
	FullName a("Mary",'L',"Jones");
	FullName b("Mary",'L',"Jones");
	FullName c("Tom",'R',"Smith");
	c.copyTo(b);                     // data in b is copied to c
	if ( !a.isEqual(c) ) return 0;
	return TEST_POINTS;
}

int FullNameTester::testIsEqual()                 const
{
	FullName a("Mary",'L',"Jones");
	FullName b("Mary",'L',"Jones");
	if ( !a.isEqual(b)) return 0;
	b.setMiddleInitial('T');
	if ( a.isEqual(b) ) return 0;	
	b.setMiddleInitial('L');
	b.setFirstName("Mary Ann");
	if ( a.isEqual(b) ) return 0;
	b.setFirstName("Mary");
	b.setLastName("Johnson");
	if ( a.isEqual(b) ) return 0;

	return TEST_POINTS;
}

int FullNameTester::testChangeLastNameToAllCaps() const
{
	FullName a("Mary",'L',"Jones-Smith");
	a.changeLastNameToAllCaps();
	if ( strcmp(a.getLastName(),"JONES-SMITH") != 0 ) return 0;
	return TEST_POINTS;
}

int FullNameTester::testAll()                     const
{
	FullNameTester test;
	int total = 0;
	for ( int choice = 0; choice <= 6; choice++)
	{
		    int oldTotal = total;
		    switch(choice) {
		       case 0:  total+=  test.testGetAndSetFirstName();
			            break;
		       case 1:  total+=  test.testGetAndSetMiddleInitial(); 
			            break;
		       case 2:  total+=  test.testGetAndSetLastName();
			            break;
		       case 3:  total+=  test.testIsSmaller(); 
			            break;
		       case 4: total+=   test.testCopyTo(); 
			            break;
		       case 5:  total+=  test.testIsEqual();
			            break;
		       case 6:  total+=  test.testChangeLastNameToAllCaps();
			            break;
		       default: break;
		    };// end switch
			if (oldTotal == total)
				cout << "FAILED TEST " << choice << " " << namesR[choice] << endl;

	} // end for
		return total;
}
