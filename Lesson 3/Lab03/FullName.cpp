#include "FullName.h"

FullName::FullName() 
{
   first = nullptr;
   last = nullptr;
   setFirstName("Jon");
   setMiddleInitial('P');
   setLastName("Volden");
}

FullName::FullName(const FullName & other)
{
   first = nullptr;
   last = nullptr;
   setFirstName(other.getFirstName());
   setMiddleInitial(other.getMiddleInitial());
   setLastName(other.getLastName());
}

FullName::FullName(const char * fr, char initial, const char * ls)
{
   first = nullptr;
   last = nullptr;
   setFirstName(fr);
   setMiddleInitial(initial);
   setLastName(ls);
}

FullName::~FullName()
{
    if ( first !=nullptr ) delete [] first;
    if (last != nullptr) delete [] last;
}

const char * FullName::getFirstName()       const
{
    return first;
}

char  FullName::getMiddleInitial()    const
{ 
    return mI;
}

const char * FullName::getLastName()         const
{
    return last;
}

// Modified for updated cstrings library.
void FullName::setFirstName(const char *fr)
{
   if ( first !=nullptr ) delete [] first;
   int len = strlen(fr) + 1;
   first = new char[len];
   strcpy(first,fr);
}
void FullName::setMiddleInitial(char value)
{
    // Not a string. Don't use strcpy.
    mI = value;
}

void FullName::setLastName(const char * lr)
{
   if ( last !=nullptr ) delete [] last;
   int len = strlen(lr) +1;
   last = new char[len];
   strcpy(last,lr);
}

void FullName::input(void)        // NEED TO ADD CODE FOR MIDDLE INITIAL AND LAST NAME
{
    // Do we set them here?
    char tempFirst[100];
    cin >> tempFirst;
    setFirstName(tempFirst);
    char tempMI;
    cin >> tempMI;
    setMiddleInitial(tempMI);
    char tempLast[100];
    cin >> tempLast;
    setLastName(tempLast);
}
void FullName::print(ostream & out ) const  // of the form:    Doe, John A.      NEED TO WRITE ALL OF THE CODE
{
    out << getLastName() << ", " << getFirstName() << " " << getMiddleInitial() << ".";
}

bool FullName::isSmaller(const FullName & right) const   // is invoking instance smaller than parameter
                                  // NEED TO ADD CODE FOR MIDDLE INITIAL AND LAST NAME
                                  // NEED TO DECIDE HOW TO COMPARE NAMES
{
    
    int b = strcmp(getFirstName(),right.getFirstName());
    if ( b > 0 ) return false;
    int a = strcmp(getLastName(), right.getLastName());
    if (a > 0) return false;
    return (getMiddleInitial() < right.getMiddleInitial());

}

void FullName::copyTo( const FullName & right)    // copy parameter to invoking instance
                                // NEED TO ADD CODE FOR MIDDLE INITIAL AND LAST NAME
{
   setFirstName(right.getFirstName());
   setMiddleInitial(right.getMiddleInitial());
   setLastName(right.getLastName());
}

bool FullName::isEqual( const FullName & right ) const // parameter and invoking instance have 
                       // the same first name, middle initial and last name
                        // NEED TO ADD CODE FOR MIDDLE INITIAL AND LAST NAME
{
    if ( strcmp(first, right.first) != 0 ) return false;
    if ( strcmp(last, right.last) != 0 ) return false;
    if ( mI != right.mI ) return false;
    return true;
}

void FullName::changeLastNameToAllCaps(void) // the last name will be changed to all capital letters
                     // the last name can contain special characters such an "Smith-Jones"
                     // which will become "SMITH-JONES"
                     // make use of the fact that corresponding lower case and capital letter differ by 32
                     // 'T' + 32 gives 't' NOTE: in C++ the following code is correct
                     // char x = 'r';
                     // x = x - 32; // x is now 'R'
{
    for (unsigned int i = 0; i < strlen(last); i++)
    {
        if (last[i] >= 'a') last[i] -= 32;
    }
}
