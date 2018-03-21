#include "Person.h"

//  *****************    THIS CODE WILL NOT COMPLILE UNTIL MIL CODE IS WRITTEN FOR THE INSTANCE
//  FIELD yearBorn   *************

// Students - no additional code needed for this function
ostream& operator<<(ostream& out, const Person& r)
{
    out << r.yearBorn << ' ' << r.name;
    if (r.mother == nullptr)
        out << "Information on mother not available";
    else
        out << "Mother: " << r.mother->yearBorn << ' '
            << r.mother->name;  // NOTE the use of -> since mother is a pointer
    return out;
}

// STUDENTS: WRITE Member Initialization List (MIL) for John D Doe born in 1900
Person::Person(void) : yearBorn(1900)
{
    name   = FullName("John", 'D', "Doe");
    mother = nullptr;  // use nullptr to indicate no information available
}

// STUDENTS: WRITE Member Initialization List (MIL) for  instance fields name and yearBorn
Person::Person(const Person& r) : yearBorn(r.yearBorn)
{
    name = r.name;
    if (r.mother == nullptr)
        mother = nullptr;
    else
        mother = new Person(r.mother->name, r.mother->yearBorn);
}

// STUDENTS: WRITE Member Initialization List (MIL) for name and yearBorn
Person::Person(const char* first, char middle, const char* last, int year, const char* firstMother,
               char middleMother, const char* lastMother, int yearMother)
    : yearBorn(year)
{
    name   = FullName(first, middle, last);
    mother = new Person(FullName(firstMother, middleMother, lastMother), yearMother);
}

//  STUDENTS: WRITE Member Initialization List (MIL) for name and yearBorn
Person::Person(const FullName& r, int year) : yearBorn(year)
{
    name   = FullName(r.getFirstName(), r.getMiddleInitial(), r.getLastName());
    mother = nullptr;  // no information about the mother
}

Person::~Person()  // Students - no additional code needed for this function
{
    if (mother != nullptr) delete mother;
    mother = nullptr;
}

// Students - no additional code needed for this function
const char* Person::getFirstName()
    const  // NOTE:  We are writing the getFirstName for a Person object
{
    return name.getFirstName();  // NOTE:  we are calling the getFirstName for a FullName object
}

char Person::getMiddleInitial() const
{
    return name.getMiddleInitial();  // STUDENTS:  write the code to return the middle initial
}

// Students - no additional code needed for this function
const char* Person::getLastName()
    const  // NOTE:  We are writing the getLastName for a Person object
{
    return name.getLastName();  // NOTE:  we are calling the getLastName for a FullName object
}

int Person::getYearBorn() const  // Students - no additional code needed for this function
{
    return yearBorn;
}

Person& Person::setFirstName(
    const char* r)  // Students - no additional code needed for this function
{
    name.setFirstName(r);
    return *this;
}

Person& Person::setMiddleInitial(char r)  // Students - no additional code needed for this function
{
    name.setMiddleInitial(r);
    return *this;
}

Person& Person::setLastName(const char* r)
{
    //  STUDENTS:   write the code to set the last name
    name.setLastName(r);
    return *this;
}

// Students - no additional code needed for this function
const Person& Person::print(ostream& out) const  // of the form:    1964 Doe, John A.
{
    out << yearBorn << ' ' << name;
    if (mother == nullptr)
        out << "Information on mother not available";
    else
        out << "Mother: " << mother->yearBorn << ' ' << mother->name;
    return *this;
}

bool Person::operator<(const Person& r) const
{
    // STUDENTS COMPLETE THE FOLLOWING CODE
    // Recall that a FullName object has an overloaded < operator
    // First compare the name objects inside the Person invoking instance and the Person parameter r
    // If the FullName objects are not different, then compare the yearBorn instance fields

    if (name == r.name) return false;
    if (yearBorn < r.yearBorn)
        return true;
    else
        return false;
}

bool Person::areSiblings(const Person& r) const
{
    //  STUDENTS:  write the code to return false if there in no information on the mother of
    //                    either the invoking instance or the parameter
    if (mother == nullptr || r.mother == nullptr) return false;

    //   STUDENTS:  write the code to return true if the mother's name for both the invoking
    //   instance and the parameter are the same
    //                   and the year born for both the invoking instance and the parameter are the
    //                   same
    //              otherwise return false
    //    NOTE:  the FullName class has a == operator
    if (mother->name == r.mother->name && mother->yearBorn == r.mother->yearBorn) return true;
    return false;  // DUMMY CODE - need to change
}

// Students - no additional code needed for this function
bool Person::hasMotherInformation() const { return mother != nullptr; }

// Students - no additional code needed for this function
const Person* Person::getMother() const { return mother; }

const char* Person::getMotherFirstName() const
{
    // precondition hasMotherInformation() is true

    //  STUDENTS:   write the code to return the name of the mother of the invoking instance
    return mother->getFirstName();
}

const Person& Person::operator=(const Person& right)
{
    if (this == &right)
        return *this;  // check for self assignment
                       // STUDENTS WRITE THE CODE FOR THE OVERLOADED = OPERATOR
                       // for the name field, since name is a FullName object and
    //      there is a FullName = operator, you can use the = opertor for the name
    name = right.name;

    // recall the the mother field is a pointer and pointer MUST be treated differently
    // conside the following logic for working with pointers
    //     - if the invoking instance has information on the mother ( mother != nullptr ) that
    //     information should be deleted ( delete mother )
    //                    the logic on the line above will prevent a MEMORY LEAK, i.e. memory on the
    //                    heap that no one is pointing to
    //     - if the parameter right has no information, the mother field in the invoking instance
    //     should be set to nullptr
    //               otherwise a new mother object should be created using new
    //               NOTE:  see the code in the Person copy constructor to get the idea of how this
    //               is done
    if (mother != nullptr) delete mother;
    if (right.mother == nullptr)
        mother = nullptr;
    else
        mother = right.mother;

    //  NOTE: since yearBorn is const, you WILL NOT be able to change the yearBorn field inside the
    //  invoking instance

    return *this;
}