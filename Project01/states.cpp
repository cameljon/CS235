/**
    CS235 Project 1, states.cpp
    Purpose: Create, set and print state objects.

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#include "states.h"
using namespace std;

/**
    @brief Default constructor, initialize ints

    @param nothing
    @return nothing
 */
State::State()
{
    m_year       = 0;
    m_population = 0;
}

/**
    @brief Default parameter constructor

    @param name is type string
    @param abbrev is type string
    @param year is type int
    @param population is type int
    @param capitol is type string
    @return nothing
 */
State::State(string name, string abbrev, int year, int population,
             string capitol)
{
    m_name       = name;
    m_abbrev     = abbrev;
    m_year       = year;
    m_population = population;
    m_capitol    = capitol;
}

/**
    @brief Default copy constructor

    @param state is const type State
    @return nothing
 */
State::State(State const& state)
{
    m_name       = state.m_name;
    m_abbrev     = state.m_abbrev;
    m_year       = state.m_year;
    m_population = state.m_population;
    m_capitol    = state.m_capitol;
}

State::~State() {}

void State::setStateName(string name) { m_name = name; }
void State::setStateAbbrev(string abbrev) { m_abbrev = abbrev; }
void State::setStateYear(int year) { m_year = year; }
void State::setStatePop(int population) { m_population = population; }
void State::setStateCapitol(string capitol) { m_capitol = capitol; }

string State::getStateName() { return m_name; }
string State::getStateAbbrev() { return m_abbrev; }
int    State::getStateYear() { return m_year; }
int    State::getStatePop() { return m_population; }
string State::getStateCapitol() { return m_capitol; }

void State::printStateName() { cout << m_name; }
void State::printStateAbbrev() { cout << m_abbrev; }
void State::printStateYear() { cout << m_year; }
void State::printStatePop() { cout << m_population; }
void State::printStateCapitol() { cout << m_capitol; }

/**
    @brief Default copy constructor

    @param state is const type State
    @return nothing
 */
vector<State> State::vstates;

int State::menu()
{
    cout << "\nWhat would you like to do?" << endl
         << "1. Manually enter state" << endl
         << "2. Auto load all states" << endl
         << "3. View loaded states" << endl
         << "4. Run class tests" << endl
         << "5. Quit" << endl
         << "Selection [1-5]: ";
    int input;
    cin >> input;
    cin.ignore(56, '\n');
    return input;
}

void State::manual()
{
    int   year;
    int   population;
    State state;
    cout << "Enter state: ";
    state.setStateName(State::getInput());
    cout << "Enter state abbreviation: ";
    state.setStateAbbrev(State::getInput());
    cout << "Enter year admitted to union: ";
    cin >> year;
    state.setStateYear(year);
    cout << "Enter 2010 population: ";
    cin >> population;
    cin.ignore(56, '\n');
    state.setStatePop(population);
    cout << "Enter state capitol: ";
    state.setStateCapitol(State::getInput());
    vstates.push_back(state);
}

string State::getInput()
{
    string input;
    getline(cin, input);
    return input;
}

void State::printHeader()
{
    cout << left << setw(20) << "\nState" << left << setw(15) << "Abbreviation"
         << left << setw(15) << "Entered Union" << left << setw(20)
         << "2010 Population" << left << setw(20) << "State Capitol" << endl;
}

/**
    @brief Prints a formated table using printHeader, printRow, and printFooter
   functions

    @param index is type int, index of state to print
    @return nothing
*/
void State::printRow(int index)
{
    cout << left << setw(20) << vstates[index].getStateName() << left
         << setw(15) << vstates[index].getStateAbbrev() << left << setw(15)
         << vstates[index].getStateYear() << left << setw(20)
         << vstates[index].getStatePop() << left << setw(20)
         << vstates[index].getStateCapitol() << endl;
}

void State::printFooter()
{
    cout << left << setw(20) << "\nTotal State Objects: " << vstates.size()
         << endl;
}

/**
    @brief Prints a formated table using printHeader, printRow, and printFooter
   functions

    @param nothing
    @return nothing
*/
void State::printTable()
{
    State::printHeader();
    for (unsigned int i = 0; i < vstates.size(); ++i) {
        State::printRow(i);
    }
    State::printFooter();
}

/**
    @brief Loads all state objects to the vector<State>

    @param vstates is a vector<T> of state objects
    @return nothing
*/
void State::loadAll()
{
    vstates.push_back(State("Alabama", "AL", 1819, 4447100, "Montgomery"));
    vstates.push_back(State("Alaska", "AK", 1959, 626932, "Juneau"));
    vstates.push_back(State("Arizona", "AZ", 1912, 5130632, "Phoenix"));
    vstates.push_back(State("Arkansas", "AR", 1836, 263400, "Little Rock"));
    vstates.push_back(State("California", "CA", 1850, 33871648, "Sacramento"));
    vstates.push_back(State("Colorado", "CO", 1876, 4301261, "Denver"));
    vstates.push_back(State("Connecticut", "CT", 1788, 3574097, "Hartford"));
    vstates.push_back(State("Delaware", "DE", 1787, 897934, "Dover"));
    vstates.push_back(State("Florida", "FL", 1845, 15982378, "Tallahassee"));
    vstates.push_back(State("Georgia", "GA", 1788, 8186453, "Atlanta"));
    vstates.push_back(State("Hawaii", "HI", 1959, 1211537, "Honolulu"));
    vstates.push_back(State("Idaho", "ID", 1890, 1293953, "Boise"));
    vstates.push_back(State("Illinois", "IL", 1818, 12419293, "Springfield"));
    vstates.push_back(State("Indiana", "IN", 1816, 6080485, "Indianapolis"));
    vstates.push_back(State("Iowa", "IA", 1846, 2926324, "Des Moines"));
    vstates.push_back(State("Kansas", "KS", 1861, 2688418, "Topeka"));
    vstates.push_back(State("Kentucky", "KY", 1792, 4041769, "Frankfort"));
    vstates.push_back(State("Louisiana", "LA", 1812, 4468976, "Baton Rouge"));
    vstates.push_back(State("Maine", "ME", 1820, 1274923, "Augusta"));
    vstates.push_back(State("Maryland", "MD", 1788, 5296486, "Annapolis"));
    vstates.push_back(State("Massachusetts", "MA", 1788, 6547629, "Boston"));
    vstates.push_back(State("Michigan", "MI", 1837, 9883640, "Lansing"));
    vstates.push_back(State("Minnesota", "MN", 1858, 5303925, "St. Paul"));
    vstates.push_back(State("Mississippi", "MS", 1817, 2844658, "Jackson"));
    vstates.push_back(State("Missouri", "MO", 1821, 5595211, "Jefferson City"));
    vstates.push_back(State("Montana", "MT", 1889, 902195, "Helena"));
    vstates.push_back(State("Nebraska", "NE", 1867, 1711263, "Lincoln"));
    vstates.push_back(State("Nevada", "NV", 1864, 2700551, "Carson City"));
    vstates.push_back(State("New Hampshire", "NH", 1788, 1316470, "Concord"));
    vstates.push_back(State("New Jersey", "NJ", 1787, 8791894, "Trenton"));
    vstates.push_back(State("New Mexico", "NM", 1912, 2059179, "Santa Fe"));
    vstates.push_back(State("New York", "NY", 1788, 19378102, "Albany"));
    vstates.push_back(State("North Carolina", "NC", 1789, 9535483, "Raleigh"));
    vstates.push_back(State("North Dakota", "ND", 1889, 672591, "Bismarck"));
    vstates.push_back(State("Ohio", "OH", 1803, 11536504, "Columbus"));
    vstates.push_back(State("Oklahoma", "OK", 1907, 3751351, "Oklahoma City"));
    vstates.push_back(State("Oregon", "OR", 1859, 3831074, "Salem"));
    vstates.push_back(
        State("Pennsylvania", "PA", 1787, 12702379, "Harrisburg"));
    vstates.push_back(State("Rhode Island", "RI", 1790, 1052567, "Providence"));
    vstates.push_back(State("South Carolina", "SC", 1788, 4625364, "Columbia"));
    vstates.push_back(State("South Dakota", "SD", 1889, 814180, "Pierre"));
    vstates.push_back(State("Tennessee", "TN", 1796, 6346105, "Nashville"));
    vstates.push_back(State("Texas", "TX", 1845, 25145561, "Austin"));
    vstates.push_back(State("Utah", "UT", 1896, 2763885, "Salt Lake City"));
    vstates.push_back(State("Vermont", "VT", 1791, 625741, "Montpelier"));
    vstates.push_back(State("Virginia", "VA", 1788, 8001024, "Richmond"));
    vstates.push_back(State("Washington", "WA", 1889, 6724540, "Olympia"));
    vstates.push_back(
        State("West Virginia", "WV", 1863, 1852994, "Charleston"));
    vstates.push_back(State("Wisconsin", "WI", 1848, 323311, "Madison"));
    vstates.push_back(State("Wyoming", "WY", 1890, 69844, "Cheyenne"));
}