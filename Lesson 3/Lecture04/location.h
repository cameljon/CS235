//       CS 235  Lecture 04
//
//    Another example of classes:
//       Work with 3 types of strings in this example
//                  1 - predefined string class
//                  2 - fixed array of characters   - allocate at compile time
//                  3 - dynamic array of characters - allocate at run time
#ifndef LOCATION_H         // Avoid having the header compiled more
#define LOCATION_H         //          than once

#include <iostream>
#include <string>
#include <cstring>

class Location {
	public:
		Location(void);                       // Default constructor

// 3 Argument constructor
		Location(const string & tCity, const char * tState, const char * tCountry);

		Location(const Location &);          // Copy constructor

		//**************************************************************
		~Location(void);                   // One and only destructor

		void setLocation(const string & tCity, const char * tState,
							  const char * tCountry);

		//   gets - return through function call

		const char *   getCountry(void) const;       // return pointer to object's data
		const char *   getState(void)   const;       // return pointer to object's data
		string         getCity(void)    const;       // return copy of object's data
		const string * getCityPointer(void) const;   // return the address of the city object inside the invoking instance
		const string & getCityReference(void) const; // return a reference to the city object inside the invoking instance
        
		//    gets - use a parameter, place data in caller's memory

		void getCountry( char *)       const;   // copy object's data to caller
		void getState(char *)          const;   // copy object's data to caller
		void getCity(string &)         const;   // copy object's data to caller

		void   print(ostream & w) const;    //   will print   city, state country
		void   input(void);                 //   user types in 3 data items
		void   copyTo( Location & ) const;  //   copy invoking instance to parameter

		// return true if invoking instance is smaller than the parameter
		bool   isSmaller(const Location & r) const;
		bool   isEqual(const Location & r) const;

	private:

		string city;          // use a string object
		char   state[20];     // memory set at compile time
		char * country;       // memory set at run time
};


#endif