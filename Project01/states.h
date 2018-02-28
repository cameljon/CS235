#include <string>

Class State
{
   public:
    // Default constructor
    State();
    // Default copy constructor
    State(State);
    // Default destructor
    ~State();

    // Get, set, print methods
    void setStateName(string);
    void setStateAbbrev(string);
    void setStateYear(int);
    void setStatePop(int);
    void setStateCapitol(string);

    string getStateName();
    string getStateAbbrev();
    int    getStateYear();
    int    getStatePop();
    string getStateCapitol();

    string printStateName();
    string printStateAbbrev();
    int    printStateYear();
    int    printStatePop();
    string printStateCapitol();

    string getInput();

   private:
    string m_name;
    string m_abbrev;
    int    m_year;
    int    m_population;
    string m_capitol;
};