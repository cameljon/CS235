// CS 235 Person Class
// Composition  a Person has a FullName
// Need to use Member Initialization List (MIL) for all Person constructors

#ifndef PERSON_H
#define PERSON_H
#include "FullNameB.h"

class Person {
    friend ostream &operator<<(ostream &, const Person &);

   public:
    Person(void);            // Default Constructor
    Person(const Person &);  // Copy Constructor
    Person(const char *first, char middle, const char *last, int year, const char *firstMother,
           char middleMother, const char *lastMother, int yearMother);
    Person(const FullName &, int year);

    ~Person();

    const char *  getFirstName() const;
    char          getMiddleInitial() const;
    const char *  getLastName() const;
    int           getYearBorn() const;
    const Person *getMother() const;

    Person &setFirstName(const char *);
    Person &setMiddleInitial(char);
    Person &setLastName(const char *);

    bool          hasMotherInformation() const;
    const char *  getMotherFirstName() const;
    const Person &print(ostream &) const;  // of the form:    1964 Doe, John A.

    bool operator<(const Person &)
        const;  // STUDENT determines the meaning of <, must consider BOTH instance fields

    bool areSiblings(
        const Person &) const;  // does the invoking instance have the same mother as the parameter

    const Person &operator=(const Person &);

   private:
    FullName  name;
    const int yearBorn;
    Person *  mother;  // pointer to the Person Object with information about the mother
                       //    NOTE:  in the person class we have a pointer to a person object
};

#endif
/*   GENERAL COMMENTS:

     FullName   name    is Composition.  A Person object has a FullName object
          All of the Person Constructors should use Member Initialization List for the name field

     yearBorn is a const and cannot be changed.  Since yearBorn is a const all of the Person
   Constructors MUST use Member Initialization List to give yearBorn a value

     Inside the Person object we also want to store information about the mother of the person.
   HOWEVER, C++ does not allow us to have a Person object inside a Person object (i.e. Composition).
   But we can have a pointer to a Person inside of a Person object
          - to indicate that we have no information about the mother, we set mother to nullptr
          - to create information about the mother, since we have a pointer we must use new to
   create a Person object on the heap

     To get the first name of the person we use name.getFirstName()           to call the FullName
   method getFirstName To get the first name of the mother we use mother->name.getFirstName()   to
   call the FullName method getFirstName








*/