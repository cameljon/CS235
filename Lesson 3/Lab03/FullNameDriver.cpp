#include "FullName.h"
#include "FullNameTester.h"
#include <iostream>
#include <string>
using namespace::std;
#pragma warning(disable:4996)

//    NOTE:   method 0 tests methods that have been comletely written,
//               so your starting score is 5 out of a possible 35

const int NUMBER_NAMES = 8;

const string names[NUMBER_NAMES] = {
	"testGetAndSetFirstName()", 
    "testGetAndSetMiddleInitial()",
    "testGetAndSetLastName()",
	"testIsSmaller()",
    "testCopyTo()",
    "testIsEqual()",
    "testChangeLastNameToAllCaps()",
    "testAll()"
};
/*
 0	int testGetAndSetFirstName()      const;
 1	int testGetAndSetMiddleInitial()  const;
 2 	int testGetAndSetLastName()       const;
 3	int testIsSmaller()               const;
 4	int testCopyTo()                  const;
 5	int testIsEqual()                 const;
 6	int testChangeLastNameToAllCaps() const;
 7	int testAll()                     const;
*/
int menu();	
void visualTest();

int main()
{
	visualTest();
	FullNameTester test;
	int choice = 0;
	while (choice != -1 )
	{
		choice = menu();
		switch(choice) {
		   case 0:  cout << "score for " << names[choice] << " is " << test.testGetAndSetFirstName() << endl;
			        break;
		   case 1:  cout << "score for " << names[choice] << " is " << test.testGetAndSetMiddleInitial() << endl; 
			        break;
		   case 2:  cout << "score for " << names[choice] << " is " << test.testGetAndSetLastName() << endl;
			        break;
		   case 3:  cout << "score for " << names[choice] << " is " << test.testIsSmaller()  << endl; 
			        break;
		   case 4:  cout << "score for " << names[choice] << " is " << test.testCopyTo() << endl; 
			        break;
		   case 5:  cout << "score for " << names[choice] << " is " << test.testIsEqual()<< endl;
			        break;
		   case 6:  cout << "score for " << names[choice] << " is " << test.testChangeLastNameToAllCaps() << endl;
			        break;
		   case 7:  cout << "score for " << names[choice] << " is " << test.testAll() << endl;
			        break;
		   default: break;
		};
	}


	return 0;

}  // end main

int menu()
{
	cout << endl << endl;
	cout << "Select for the following = use -1 to quit" << endl;
	for(int i = 0; i < NUMBER_NAMES; i++)
		cout << i <<  ' ' << names[i] << endl;
	int choice;
	cin >> choice;
	return choice;
}

void visualTest()
{
	cout << "Starting Visual Test" << endl;
//   Suppy code to Visually check the correctness of each of the following methods

// 0	int testGetAndSetFirstName()      const;
	{
		cout << "Running getFirstName() and setFirstName() tests.\n";
		FullName name("John", 'D', "Doe");
		cout << "\tSet first name to John.\n";
		cout << "\tCalling getFirstName(): " << name.getFirstName() << endl;
		cout << "\tSet first name to Jane.\n";
		name.setFirstName("Jane");
		cout << "\tCalling getFirstName(): " << name.getFirstName() << endl;
	}
	
//	1	int testGetAndSetMiddleInitial()  const;

	{
		cout << "Running getMiddleInitial() and setMiddleInitial() tests.\n";
		FullName name("John", 'D', "Doe");
		cout << "\tSet middle initial to D.\n";
		cout << "\tCalling getMiddleInitial(): " << name.getMiddleInitial() << endl;
		cout << "\tSet middle initial to P.\n";
		name.setMiddleInitial('P');
		cout << "\tCalling getMiddleInitial(): " << name.getMiddleInitial() << endl;

	}
	
//	2 	int testGetAndSetLastName()       const;
	{

		cout << "Running getLastName() and setLastName() tests.\n";
		FullName name("John", 'D', "Doe");
		cout << "\tSet last name to Doe.\n";
		cout << "\tCalling getLastName(): " << name.getLastName() << endl;
		cout << "\tSet last name to Howard.\n";
		name.setLastName("Howard");
		cout << "\tCalling getLastName(): " << name.getLastName() << endl;

	}

//	3	int testIsSmaller()               const;
	{

		cout << "Running isSmaller() test.\n";
		FullName john("John", 'D', "Doe");
		FullName jane("Jane", 'A', "Adams");
		FullName zach("Zachary", 'S', "Stephens");
		string size = (jane.isSmaller(john))? "smaller": "bigger";
		cout << "\tJane A. Adams is " << size << " than John D. Doe.\n";
		size = (zach.isSmaller(john))? "smaller": "bigger";
		cout << "\tZachary S. Stephens is " << size << " than John D. Doe.\n";


	}
	
	
//	4	int testCopyTo()                  const;
	{
		cout << "Running copyTo() tests.\n";
		FullName john("John", 'D', "Doe");
		FullName jane("Jane", 'A', "Adams");
		cout << "\tThe object John is " << john.getFirstName() << " " << john.getMiddleInitial() << " " << john.getLastName() << endl;
		john.copyTo(jane);
		cout << "\tThe object John is now " << john.getFirstName() << " " << john.getMiddleInitial() << " " << john.getLastName() << endl;

	}
	

//	5	int testIsEqual()                 const;
	{
		cout << "Running isEqual() tests.\n";
		FullName name1("John", 'D', "Doe");
		FullName name2("John", 'D', "Doe");
		FullName name3("Jane", 'A', "Adams");
		cout << "\tThe object name1 is " << name1.getFirstName() << " " << name1.getMiddleInitial() << " " << name1.getLastName() << endl;
		cout << "\tThe object name2 is " << name2.getFirstName() << " " << name2.getMiddleInitial() << " " << name2.getLastName() << endl;
		cout << "\tThe object name3 is " << name3.getFirstName() << " " << name3.getMiddleInitial() << " " << name3.getLastName() << endl;
		string oneTwo = (name1.isEqual(name2))? "equal": "not equal";
		string twoThree = (name2.isEqual(name3))? "equal": "not equal";
		cout << "\tName1 is " << oneTwo << " to name2.\n";
		cout << "\tName2 is " << twoThree << " to name3.\n";

	}
	
		
//	6	int testChangeLastNameToAllCaps() const;
	{
		cout << "Running changeLastNameToAllCaps() tests.\n";
		FullName name1("John", 'D', "Doe");
		FullName name2("Zachary", 'S', "Stephens");
		FullName name3("Jane", 'A', "Adams");
		cout << "\tNames before caps: " << name1.getLastName() << " " << name2.getLastName() << " " << name3.getLastName() << endl;
		name1.changeLastNameToAllCaps();
		name2.changeLastNameToAllCaps();
		name3.changeLastNameToAllCaps();
		cout << "\tNames after caps: " << name1.getLastName() << " " << name2.getLastName() << " " << name3.getLastName() << endl;

	}

	cout << "Ending Visual Test" << endl;
}