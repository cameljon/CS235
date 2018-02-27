// FullName Tester h file
#ifndef FULL_NAME_TESTER
#define FULL_NAME_TESTER
#include <iostream>
#include <cstring>
#include <string>
using namespace::std;
#include "FullName.h"

const int NUMBER_NAMESR = 8;

const string namesR[NUMBER_NAMESR] = {
	"testGetAndSetFirstName()",
	"testGetAndSetMiddleInitial()",
	"testGetAndSetLastName()",
	"testIsSmaller()",
	"testCopyTo()",
	"testIsEqual()",
	"testChangeLastNameToAllCaps()",
	"testAll()"
};

class FullNameTester
{
public:
	FullNameTester();
	

	int testGetAndSetFirstName()      const;
	int testGetAndSetMiddleInitial()  const;

	int testGetAndSetLastName()       const;
	
	int testIsSmaller()               const;
	int testCopyTo()                  const;

	int testIsEqual()                 const;
	int testChangeLastNameToAllCaps() const;

	int testAll()                     const;
private:
	static const int TEST_POINTS = 5;



};
#endif