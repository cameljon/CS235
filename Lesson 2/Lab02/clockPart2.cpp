#include "clockPart2.h"
#include <ctime>     // need to call time function

// Lab 2 Member Functions

void Clock::setToCurrentTime()
{
	int currentT = time(0);              // get time in number of seconds elapsed since January 1, 1970
								          //    time is GMT - Greenwich Mean Time
	currentT = currentT % (24 * 60 * 60);   // convert to seconds past midnight
	currentT = currentT / 60;               // convert to minutes
	int cHr, cMn;
	cHr = currentT / 60;                    // get current hour
	const int GMT_DIFFERENCE = -6;          // for Central Standard Time compared to Greenwich Mean Time

	cHr = ( cHr + GMT_DIFFERENCE + 24) % 24;

	cMn = currentT % 60;                    // get current minute
	setHours(cHr);
	setMinutes(cMn);
}
// Constructors
Clock::Clock(void)
{
	setToCurrentTime();        // will set hours and minutes
	setChimeOnHalfHour(false);   // default value of false
	setChimeOnHour(false);
}
Clock::Clock(int hr, int m, bool chimeHalfHour, bool chimeHour)      // Argument Constructor
{
	setMinutes(m);
	// students complete the code
	setHours(hr);
	setChimeOnHalfHour(chimeHalfHour);
	setChimeOnHour(chimeHour);
}
Clock::Clock(const Clock & right)     // Copy Constructor
{
	setMinutes(right.getMinutes());
	// students complete the code
	setHours(right.getHours());
	setChimeOnHalfHour(right.getChimeOnHalfHour());
	setChimeOnHour(right.getChimeOnHour());
}


// Destructor
Clock::~Clock()
{
	// no code, no work to be done
}

void Clock::sync(Clock & right) const      // parameter will have same time as invoking instance
{                 // sync the time, ie both will have the same values
	              //      but do not change the should chime fields
	// students write the code
	right.setMinutes(this->getMinutes());
	right.setHours(this->getHours());
}

void Clock::setHoursAhead(int h)    //   Assume 1 <= h <= 23
{
    setHours((getHours() + h) % 24);
}

void Clock::setHoursBack(int h)      //   Assume 1 <= h <= 23
{
    setHours((getHours() - h + 24) % 24);
}

void Clock::setMinutesAhead(int m)   //   Assume 1 <= m <= 59, leave hours the same
{
	setMinutes((getMinutes() + m) % 60);     // in case the result is >= 60
}

void Clock::setMinutesBack(int m)    //   Assume 1 <= m <= 59, leave hours the same
{
	setMinutes((getMinutes() - m + 60 ) % 60);     // in case the result is < 0  
}

int Clock::differenceInClocks(const Clock & right) const
{
	int hrs = right.getHours() - this->getHours();
	int mins = right.getMinutes() - this->getMinutes();
	// Total minutes(?) clocks are off
	return ((hrs * 60) + mins);
}

const Clock & Clock::operator=(const Clock & right)
{
	// see Lecture 3 for an example of the = operator
	// students write the code
	if(this == & right) return *this;
	this->setMinutes(right.getMinutes());
	this->setHours(right.getHours());
	return *this;    // necessary for the code to compile
}



//  Lab 1 Member Functions 

// 11 member functions, i.e. methods  

int  Clock::getMinutes(void) const
{
    return minutes;
}
int  Clock::getHours(void)   const
{
	return hours;
}
bool Clock::getChimeOnHalfHour(void)   const
{
	return shouldChimeOnHalfHour;
}
void Clock::setMinutes(int m )
{
	if ( m >= 0 && m <= 59 )
		minutes = m;
	else
		minutes = 0;
}
void Clock::setHours(int h)
{
	if (h >= 0 && h <= 23)
		hours = h;
	else
		hours = 0;
}
void Clock::setChimeOnHalfHour(bool v )
{
	shouldChimeOnHalfHour = v;
}
string Clock::chimeOnHalfHour(void) const
{
    if ( getChimeOnHalfHour() && getMinutes() == 30 )
		return "ding";
	else
		return "";
}
bool Clock::getChimeOnHour(void)       const
{
	return shouldChimeOnHour;
}
void Clock::setChimeOnHour(bool v)
{
	shouldChimeOnHour = v;
}
// Students supply your code from Lab 1 for these member functions

void Clock::tick(void)
{
	// time goes up 1 minute
	// however when the minute is 59, it changes to 0
	// and the hour is changed
	//     if the hour is not 23, the hour goes up by 1
	//     otherwise the hour resets to 0
	//  need to consider the cases:   
	//           59 minutes and any hour but 23
	//           59 minues and 23 hours

	// FUNCTION STUB
	if (minutes == 59)
	{
		if (hours == 23)
		{
			minutes = 0;
			hours = 0;
		}
		else
		{
			minutes = 0;
			hours++;
		}
	}
	else
	{
		minutes++;
	}
}

string Clock::chimeOnHour(void) const
{
// clock should chime the number of hours, from 1 to 12
//    use string concatenation to build the return value
//    see the example in the driver program
	string dong = "";
	int undoMilitary = hours % 12;
    if (getChimeOnHour())
	{
		for (int i = 0; i < undoMilitary; ++i)
		{
			dong = dong + " " + "dong";
		}
	}
	return dong;
}




