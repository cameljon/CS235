//    CS 235       Lecture 04
//    Driver Program
//        - Enter data from the keyboard into an array
//        - Sort the array

#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace::std;

#include "location.h"
// *********************************************************************************
//  user written functions for main

void sort( Location info[], int count);
void print(ostream &, const Location info[], int, const char * message);

//      Main program  **************************************************************

const int ENTRIES = 1;

int main()
{
	Location jccc("Overland Park","KS","USA");
	char workCountry[40];   // Quess on the maximum memory
	jccc.getCountry(workCountry);
	cout << "JCCC is in the country of " << workCountry << endl;
	Location one[ENTRIES];

	cout << "Enter " << ENTRIES << " locations - city state country\n";
	int i;
	for ( i = 0; i < ENTRIES ; i++)
		one[i].input();

	print(cout,one,ENTRIES,"Location array before sorting");

	sort(one,ENTRIES);

	print(cout,one,ENTRIES,"Location array after sorting");

	cout << "Using the 3 functions that return information about the city" << endl;
	cout << jccc.getCity() << ' ' << jccc.getCityReference() << ' ' << *(jccc.getCityPointer()) << endl;

    cout << "\nTesting isEqual() function." << endl;
    Location home("Tonganoxie", "KS", "USA");
    string areTheyEqual = (jccc.isEqual(home))? "equal": "not equal";
    cout << "Location 1: " << jccc.getCity() << ",\t" << jccc.getState() << "\t" << jccc.getCountry() << endl;
    cout << "Location 2: " << home.getCity() << ",\t\t" << home.getState() << "\t" << home.getCountry() << endl;
    cout << "\tThe 2 locations are " << areTheyEqual << "." << endl;
    cout << "-\t-\t-\t-\t-\t-" << endl;
    Location newHome("Overland Park", "KS", "USA");
    cout << "Location 1: " << jccc.getCity() << ",\t" << jccc.getState() << "\t" << jccc.getCountry() << endl;
    cout << "Location 2: " << newHome.getCity() << ",\t" << newHome.getState() << "\t" << newHome.getCountry() << endl;
    areTheyEqual = (jccc.isEqual(newHome))? "equal": "not equal";
    cout << "\tThe 2 locations are " << areTheyEqual << "." << endl;



	return 0;     // end main
}

//  **********************  User written functions

void swapValues(Location &, Location &);      //  used in sort

int  indexSmallest(const Location data[] , int start, int count);  // used in sort

void sort(Location info[], int count)
{
	 //  Selection sort
	int smallIndex;
	for ( int i =0 ; i < count -1; i++)
	{
		smallIndex = indexSmallest(info,i,count);
		if ( i != smallIndex)
			swapValues(info[i],info[smallIndex]);
	}
}

void swapValues(Location & left, Location & right)
{
  Location work;
  left.copyTo(work);
  right.copyTo(left);
  work.copyTo(right);
}

int indexSmallest(const Location data[], int start, int numberUsed)
{
  int indexMin = start;
  Location min(data[start]);
  for ( int i = start + 1; i < numberUsed; i++)
  {
		if ( data[i].isSmaller(min) )
	  {
		  indexMin = i;
		  data[i].copyTo(min);
	  }
  }
  return indexMin;
}


void print(ostream & w, const Location info[], int count, const char * message)
{
	w << message << endl;
	for(int i = 0; i < count; i++)
	{
		 info[i].print(w);
		 w << endl;
	}
}

