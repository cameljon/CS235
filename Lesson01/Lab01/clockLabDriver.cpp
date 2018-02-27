#include "clock.h"

void visualTests();
void visualTestForSetsAndGets();
void visualTestForTick();
void visualTestsForChimes();

void computerTests();
void computerTestForTick();

int main()
{
	visualTests();
	computerTests();
	return 0;
}

void visualTests()
{
	visualTestForSetsAndGets();
	visualTestForTick();
	visualTestsForChimes();
}

void visualTestForSetsAndGets()
{
	cout << "\n\nvisualTestForSetsAndGets" << endl;
	Clock test;
	test.setMinutes(52);
	cout << test.getMinutes() << " should be 52" << endl;
	test.setMinutes(87);
	cout << test.getMinutes() << " should be 0" << endl;
	test.setHours(14);
	cout << test.getHours() << " should be 14" << endl;
	test.setHours(24);
	cout << test.getHours() << " should be 0" << endl;
	test.setChimeOnHalfHour(false);
	cout << test.getChimeOnHalfHour() << " should be false, i.e. 0" << endl;
	test.setChimeOnHalfHour(true);
	cout << test.getChimeOnHalfHour() << " should be true, i.e. 1" << endl;
	test.setChimeOnHour(false);
	cout << test.getChimeOnHour() << " should be false, i.e. 0" << endl;
	test.setChimeOnHour(true);
	cout << test.getChimeOnHour() << " should be true, i.e. 1" << endl;

}
void visualTestForTick()
{
	cout << "\n\nvisualTestForTick" << endl;
	Clock test;

	test.setHours(2);
	test.setMinutes(15);
	for (int i = 1; i <= 30; i++)
		test.tick();
	cout << test.getHours() << " should be 2" << endl;
	cout << test.getMinutes() << " should be 45" << endl;

	test.setHours(2);
	test.setMinutes(15);
	for (int i = 1; i <= 300; i++)    // 300 minutes is exactly 5 hours
		test.tick();
	cout << test.getHours() << " should be 7" << endl;
	cout << test.getMinutes() << " should be 15" << endl;

	test.setHours(14);     // 14 is 2 in the afternoon
	test.setMinutes(15);
	for (int i = 1; i <= 1489; i++)  // 1489 minutes is exactly 24 hours and 45 minutes
		test.tick();
	cout << test.getHours() << " should be 15" << endl;
	cout << test.getMinutes() << " should be 4" << endl;

}
void visualTestsForChimes()
{
	cout << "\n\nvisualTestForTick" << endl;
	Clock test;
	cout << "     testing chime on half hour" << endl;
	test.setChimeOnHalfHour(false);
	test.setMinutes(17);
	test.setHours(14);
	cout << test.chimeOnHalfHour() << "\n should be empty string" << endl;
	test.setMinutes(30);
	cout << test.chimeOnHalfHour() << "\n should be empty string" << endl;
	test.setMinutes(17);
	test.setChimeOnHalfHour(true);
	cout << test.chimeOnHalfHour() << "\n should be empty string" << endl;
	test.setMinutes(30);
	cout << test.chimeOnHalfHour() << "\n should be ding" << endl;
	cout << "     testing chime on hour" << endl;
	test.setMinutes(0);  // it is now on the hour
	test.setHours(5);
	test.setChimeOnHour(false);
	cout << test.chimeOnHour() << " \n should be empty string" << endl;
	test.setChimeOnHour(true);
	cout << test.chimeOnHour() << " \n should be \n dong dong dong dong dong" << endl;
	test.setHours(20);  // 8 at night
	cout << test.chimeOnHour() << " \n should be \n dong dong dong dong dong dong dong dong" << endl;

}

void computerTests()
{
	computerTestForTick();
}


void computerTestForTick()
{
	cout << "\n\ncomputerTestForTick" << endl;
	Clock test;
	test.setHours(0);
	test.setMinutes(0);
	cout << "     testing minutes" << endl;
	for (int i = 1; i <= (24 * 60); i++)   // one day is 60 * 24 minutes
	{
		test.tick();
		if (test.getMinutes() != i % 60)  // i.e. start at 0 after 100 ticks, minutes should be 100 % 60 or 40 minutes
		{
			cout << "Test for Tick minutes failed when i was " << i << endl;
			return;
		}
	}
	cout << "     testing minutes successful" << endl;

	cout << "     testing hours" << endl;
	test.setHours(0);
	test.setMinutes(0);
	for (int i = 1; i <= (60 * 24 * 7); i++) // one week is 60 * 24 * 7 minutes
	{
		test.tick();
		if (test.getHours() != (i / 60) % 24)  //  / 60 gets the total hours and then % 24 gives the hours within the day
		{
			cout << "Test for Tick hours failed when i was " << i << endl;
			return;
		}
	}
	cout << "     testing hours successful" << endl;
	cout << "     testing ticks successful" << endl;
}
