//    CS 235 -  Lecture 04
//    Implementation File -            location.cpp
#include "location.h"
using namespace::std;
#pragma warning(disable:4996)     // Used to disable VS 2015 warnings for strcpy() not being safe

Location::Location(void)
{
	country = NULL;    // Let setLocation - indicate there is no heap memory to return
	setLocation("city","state","country");
}

Location::Location(const string & tCity, const char * tState, const char * tCountry)
{
	country = NULL;    // Let setLocation - indicate there is no heap memory to return
	setLocation(tCity,  tState,  tCountry);
}

Location::Location(const Location & other)
{
	country = NULL;    // Let setLocation - indicate there is no heap memory to return
	setLocation(other.city, other.state, other.country);

	 // could use gets  QUESTION - which get takes the most time?

//	setLocation(other.getCity(), other.getState(), other.getCountry() );
}

Location::~Location(void)
{
	delete [] country;     //  return heap memory for variable "country"
								  //  the string destructor will take care of
								  //       the memory for variable "city"
								  //  the memory for variable "state" is inside the
								  //       object and will be reclaimed when the
								  //       memory for the object is reclaimed
}

void   Location::setLocation( const string & tCity, const char * tState,
							  const char * tCountry)
{
	city = tCity;               //   "=" -  assignment for string objects

	strncpy(state,tState,20);   //  use 20 bytes set aside
	state[19] = '\0';

	//  check to see if heap memory has been allocated for country
	//     if memory has been allocated, return the memory
	//     to avoid a memory leak
	if ( country != NULL ) delete [] country;
	country = new char[strlen(tCountry) + 1];    //  acquire memory on the heap
	strcpy(country,tCountry);                    //  use strcpy
}

void Location::print(ostream & w) const
{
	w << city << ", " << state << ' ' << country;

	// could use gets
	//   QUESTION - which get takes the most time?
	//       Illustrates 3 ways to call the member function
	//             all 3 produce the same machine code

//	w << getCity() << ", " << (*this).getState() << ' ' << this->getCountry();
}


void  Location::input(void)
{
	char workState[20];          // work memory for state
	char workCountry[20];        // work memory for country
	string workCity;             // work memory for city
	cout << "Enter city state country: ";
	cin >> workCity >> workState >> workCountry;
	setLocation(workCity,workState,workCountry);
}

void Location::copyTo( Location & r ) const
{
	r.city = city;            //  = works for string objects

	strcpy(r.state,state);   // can use strcpy since state fits in 20 bytes

	delete [] r.country;                        // give back dynamic memory
															  //    to avoid memory leak
	r.country = new char[strlen(country) + 1];  // acquire new memory
	strcpy(r.country,country);                  // strcpy the country

	// could have also used setLocation member function
	//   in general a full argument set function is not available
	//     so the code above represents the more general coding solution
}

bool Location::isSmaller(const Location & r) const
{
	//  ORDER OF COMPARISONS ==> 1st country; 2nd state; 3rd city

	int a = strcmp(country,r.country);        // need strcmp
	if      ( a < 0 )    return true;
	else if ( a > 0 )    return false;
    
	// at this point in the logic, the countries are the same
	int b = strcmp(state,r.state);            // need strcmp
	if      ( b < 0 )             return true;
	else if ( b > 0 )             return false;
	
	// at this point in the logic, the countries are the same
	//       and the states are the same
	return ( city < r.city );    // < works for string objects
}

bool Location::isEqual(const Location & r) const
{
	int a = strcmp(country,r.country);
	// Return false for anything but zero.
	if (a != 0) return false;
	int b = strcmp(state,r.state);
	// Return false for anything but zero.
	if (b != 0) return false;
	return (city == r.city);
}


const char * Location::getCountry(void) const  // return pointer to object's data
{
	return country;   // place a copy of the address on the stack
}

const char *  Location::getState(void)   const // return pointer to object's data
{
	return state;     // place a copy of the address on the stack
}

string Location::getCity(void)    const   // return copy of object's data
{
	return city;      // place a copy of city string on the stack
}

const string * Location::getCityPointer(void) const
{
     return & city; // return the address of the city object inside the invoking instance	
}

const string & Location::getCityReference(void) const
{
	return city; // return a reference to the city object inside the invoking instance
}    

void Location::getCountry( char * ans) const   // copy object's data to caller
{
	strcpy(ans,country);  //  use caller's memory - assume there is enough memory
}

void Location::getState(char * ans)  const  // copy object's data to caller
{
	strcpy(ans,state);    //  use caller's memory - assume there is enough memory
}

void Location::getCity(string & ans)  const   // copy object's data to caller
{
	ans = city;        // use string = to copy the city to user's memory
}

