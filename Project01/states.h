/**
    CS235 Project 1, states.h
    Purpose: Header file for state class project.

    @author Jon Volden
    @version 0.1 02/28/2018
*/

#ifndef STATES_H
#define STATES_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
    @brief Class that creates, sets and prints state objects.
*/
class State {
   public:
    // Default constructor
    State();
    // Copy constructor
    State(State const& state);
    // Parameter constructor
    State(std::string, std::string, int, int, std::string);
    // Destructor
    ~State();

    void setStateName(std::string);     // Set name
    void setStateAbbrev(std::string);   // Set initials
    void setStateYear(int);             // Set year admitted to union
    void setStatePop(int);              // Set 2010 state population
    void setStateCapitol(std::string);  // Set state's capitol

    std::string getStateName();     // Get name
    std::string getStateAbbrev();   // Get state initials
    int         getStateYear();     // Get year admitted to union
    int         getStatePop();      // Get 2010 state population
    std::string getStateCapitol();  // Get state's capitol

    void printStateName();     // Print name
    void printStateAbbrev();   // Print state initials
    void printStateYear();     // Print state year
    void printStatePop();      // Print 2010 state population
    void printStateCapitol();  // Print state's capitol

    // Print menu and return input selection
    static int menu();
    // Manually add state object to vstates vector
    static void manual();
    // Get input using getline()
    static std::string getInput();
    // Prints a formated header with state attribute titles
    static void printHeader();
    // Prints a states formated individual attributes
    static void printRow(int);
    // Prints a footer with total state objects
    static void printFooter();
    // Prints header, footer, and vector state objects
    static void printTable();
    // Used for testing. Loads all states' data into state vector
    static void loadAll();

   private:
    std::string m_name;                 ///< State name
    std::string m_abbrev;               ///< Two letter state initial
    int         m_year;                 ///< Year admitted into the Union
    int         m_population;           ///< Population according to 2010 census
    std::string m_capitol;              ///< State capitol
    static std::vector<State> vstates;  ///< Vector to manage state objects
};

#endif
