#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
using namespace::std;
class Clock   // use military time  see the website:
                 //  http://en.wikipedia.org/wiki/24-hour_clock
				 //  we will NOT use a time of 24 hours and 0 minutes
				 //  a time of 0 hours and 45 minutes is 12:45 am
				 //  a time of 1 hour and 0 minutes is 1:00am
				 //      and the clock would chime 1 time
				 //  a time of 14 hours and 0 minutes is 2:00pm
				 //      and the clock would chime 2 times

{
public:    
   // Lab 2 Methods
   // Constructors
	Clock(void);                // Default Constructor
		// Argument Constructor
	Clock(int hr, int m, bool chimeHalfHour, bool chimeHour);       
	Clock(const Clock & right);       // Copy Constructor
	// Destructor
	~Clock(); 
	// Additional Clock Member Functions
	void sync(Clock & right) const;      // parameter will have same time as invoking instance
	void setToCurrentTime(void);   //   Instructor Written
	void setHoursAhead(int h);     //   Assume 1 <= h <= 23
	void setHoursBack(int h);      //   Assume 1 <= h <= 23
	void setMinutesAhead(int m);   //   Assume 1 <= m <= 59, leave hours the same
	void setMinutesBack(int m);    //   Assume 1 <= m <= 59, leave hours the same
	int differenceInClocks(const Clock & right) const;
	//  will return in minutes the absolute value of the time difference between the 
	//      invoking instance and the parameter
	//  HINT:  instead of comparing 1 hour 55 minutes to 2 hours 12 minutes
	//                   convert both times to minutes past midnight and work with those numbers

	// overloaded = operator, study Lecture 3 for an example of the = operator
	const Clock & operator=(const Clock & right);
	
	
	
	
	//  Lab 1 Methods
    int  getMinutes(void) const;
	int  getHours(void)   const;
	bool getChimeOnHalfHour(void)   const;
	bool getChimeOnHour(void)       const;

	void setMinutes(int m );
	void setHours(int h);
    void setChimeOnHalfHour(bool v );
	void setChimeOnHour(bool v);

	string chimeOnHalfHour(void) const;
	string chimeOnHour(void) const;

	void tick(void);           // time goes up 1 minute
	           //  need to consider the cases:   59 minutes and any hour but 23
	           //                                59 minues and 23 hours
private:
	int minutes;   // will range between 0 and 59
	int hours;     // will range between 0 and 23
	bool shouldChimeOnHalfHour;
	bool shouldChimeOnHour;
};
#endif