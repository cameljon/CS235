#ifndef FULL_NAME
#define FULL_NAME
#include <iostream>
#include <cstring>
using namespace::std;

class FullName
{
public:
	FullName();                                                 // Default Constructor
	FullName(const FullName &);                                 // Copy Constructor
	FullName(const char * fr, char initial, const char * ls);   // Argument Constructor

	~FullName();                      // Destructor

	const char * getFirstName()       const;
	char         getMiddleInitial()   const;
	const char * getLastName()        const;

	void setFirstName(const char *);
	void setMiddleInitial(char);
	void setLastName(const char *);

	void input(void);              // will read three values from cin and place the values inside the invoking instance
	void print(ostream & ) const;  // will display the full name in the form of:    Doe, John A.

	bool isSmaller(const FullName & ) const;   // is invoking instance smaller than parameter

	void copyTo( const FullName &) ;          // copy parameter to invoking instance

	bool isEqual( const FullName & ) const; // parameter and invoking instance have 
                       // the same first name, middle initial and last name

    void changeLastNameToAllCaps(void); // the last name will be changed to all capital letters
                     // the last name can contain special characters such an "Smith-Jones"
                     // which will become "SMITH-JONES"
                    

private:
	char * first;
	char   mI;
	char * last;


};
#endif