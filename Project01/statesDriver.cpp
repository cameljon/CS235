/**
    CS235 Project 1, statesDriver.cpp
    Purpose: To create state class using OO programming in C++.

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#include "states.h"
#include "testStates.h"
using namespace std;

int main()
{
    int selection;
    do {
        selection = State::menu();
        switch (selection) {
            case 1:
                // Ask user input to add state object
                State::manual();
                break;
            case 2:
                // Load all state information
                State::loadAll();
                break;
            case 3:
                // Print all state information loaded
                State::printTable();
                break;
            case 4:
                // Run tests for all functions in state class
                TestStates::allTests();
                break;
            case 5:
                break;
        }
    } while (selection != 5);

    return 0;
}

/** Sample output

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]: 1
Enter state: State Name
Enter state abbreviation: SN
Enter year admitted to union: 2018
Enter 2010 population: 20987656
Enter state capitol: State Capitol

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]: 3

State              Abbreviation   Entered Union  2010 Population     State Capitol
State Name          SN             2018           20987656            State Capitol

Total State Objects: 1

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]: 2

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]: 3

State              Abbreviation   Entered Union  2010 Population     State Capitol
State Name          SN             2018           20987656            State Capitol
Alabama             AL             1819           4447100             Montgomery
Alaska              AK             1959           626932              Juneau
Arizona             AZ             1912           5130632             Phoenix
Arkansas            AR             1836           263400              Little Rock
California          CA             1850           33871648            Sacramento
Colorado            CO             1876           4301261             Denver
Connecticut         CT             1788           3574097             Hartford
Delaware            DE             1787           897934              Dover
Florida             FL             1845           15982378            Tallahassee
Georgia             GA             1788           8186453             Atlanta
Hawaii              HI             1959           1211537             Honolulu
Idaho               ID             1890           1293953             Boise
Illinois            IL             1818           12419293            Springfield
Indiana             IN             1816           6080485             Indianapolis
Iowa                IA             1846           2926324             Des Moines
Kansas              KS             1861           2688418             Topeka
Kentucky            KY             1792           4041769             Frankfort
Louisiana           LA             1812           4468976             Baton Rouge
Maine               ME             1820           1274923             Augusta
Maryland            MD             1788           5296486             Annapolis
Massachusetts       MA             1788           6547629             Boston
Michigan            MI             1837           9883640             Lansing
Minnesota           MN             1858           5303925             St. Paul
Mississippi         MS             1817           2844658             Jackson
Missouri            MO             1821           5595211             Jefferson City
Montana             MT             1889           902195              Helena
Nebraska            NE             1867           1711263             Lincoln
Nevada              NV             1864           2700551             Carson City
New Hampshire       NH             1788           1316470             Concord
New Jersey          NJ             1787           8791894             Trenton
New Mexico          NM             1912           2059179             Santa Fe
New York            NY             1788           19378102            Albany
North Carolina      NC             1789           9535483             Raleigh
North Dakota        ND             1889           672591              Bismarck
Ohio                OH             1803           11536504            Columbus
Oklahoma            OK             1907           3751351             Oklahoma City
Oregon              OR             1859           3831074             Salem
Pennsylvania        PA             1787           12702379            Harrisburg
Rhode Island        RI             1790           1052567             Providence
South Carolina      SC             1788           4625364             Columbia
South Dakota        SD             1889           814180              Pierre
Tennessee           TN             1796           6346105             Nashville
Texas               TX             1845           25145561            Austin
Utah                UT             1896           2763885             Salt Lake City
Vermont             VT             1791           625741              Montpelier
Virginia            VA             1788           8001024             Richmond
Washington          WA             1889           6724540             Olympia
West Virginia       WV             1863           1852994             Charleston
Wisconsin           WI             1848           323311              Madison
Wyoming             WY             1890           69844               Cheyenne

Total State Objects: 51

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]: 4
Testing constructors:
Should be empty string: passed
Should be initialized to 0: passed
Should be ABCD: passed
Should be AB: passed
Should be 1234: passed
Should be 2345678: passed
Should be ABCDEFG: passed
Should be STATE: passed
Should be ST: passed
Should be 1918: passed
Should be 23456789: passed
Should be CAPITOL: passed
Testing setters and getters:
Should be TEST STATE: passed
Should be TS: passed
Should be 2018: passed
Should be 123456789: passed
Should be TEST CAPITOL: passed
Testing printers:
Should be TEST STATE: TEST STATE
Should be TS: TS
Should be 2018:  2018
Should be 123456789: 123456789
Should be TEST CAPITOL TEST CAPITOL
All tests done!

What would you like to do?
1. Manually enter state
2. Auto load all states
3. View loaded states
4. Run class tests
5. Quit
Selection [1-5]:

*/