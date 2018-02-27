#include "Number.h"
// array for the numbers from 1 to 19, 0 is a special case - in the array it is
// the null string
const string Number::name1[20] = {
    "",        "one",     "two",       "three",     "four",
    "five",    "six",     "seven",     "eight",     "nine",
    "ten",     "eleven",  "twelve",    "thirteen",  "fourteen",
    "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"};

//  array of the 10's place   0 and 1 are special cases - in the array they are
//  null strings
const string Number::name2[10] = {"",       "",      "twenty", "thirty",
                                  "fourty", "fifty", "sixty",  "seventy",
                                  "eighty", "ninety"};

//  array for thousands, millions and billions - special case for 1's and 100's
//  - in the array they ar null strings
const string Number::name3[5] = {"", "", "thousand", "million", "billion"};

Number::Number(void) {
  theNumber = 0;
  theString = figureString(theNumber, 0);
}
Number::Number(int n) {
  theNumber = n;
  theString = figureString(theNumber, 0);
}

Number::Number(const Number& r) {
  theNumber = r.theNumber;
  theString = r.theString;  // use = the the data inside of r is correct
}

Number::~Number() {}

Number& Number::setValue(int n) {
  if (n == theNumber) return *this;  // same value - no need to recompute
  theNumber = n;
  theString = figureString(theNumber, 0);
  return *this;  // allows for function chaining
}

int Number::getInteger(void) const { return theNumber; }

string Number::getString(void) const { return theString; }

string Number::figureString(int toConvert, int counterFunctionCalls) {
  // This algorithm is the heart of the logic of the class
  // Use three arrays to hold values that can be looked up with a subscript
  // Thus avoiding lots of if ... else logic

  // Use of recursion to solve the problem in groups of 3 digits
  // SPECIAL CASE of 0 - if counterFunctionCalls is 0 - the alorithm is just
  // starting and 0 is the parameter for toConvert, so return 0
  // if counterFunctionCalls is not 0,  the 0 will not be listed in the
  // string, so a null string is used for a 0

  if (toConvert == 0 && counterFunctionCalls == 0) return "zero";
  int rightThree = toConvert % 1000;

  // all three digits are 0 as in 12,000,784 - there is nothing to add to the
  // string NOTE:  the recursion builds the answer left to right
  // Work on the digits to the left - first parameter is divided by 1000
  // to get those digits, second parameter is increased by 1 to move
  // from thousands to millions to billions

  if (rightThree == 0)
    return figureString(toConvert / 1000, counterFunctionCalls + 1);

  int rightTwo = rightThree % 100;
  string answer = "";
  if (rightTwo < 20)
    answer = name1[rightTwo];  // special cases
  else
    answer = name2[rightTwo / 10] + " " + name1[rightTwo % 10];
  // we have now built the right 2 digits of the 3 digits

  // add in hundreds if needed
  if (rightThree >= 100)
    answer = name1[rightThree / 100] + " hundred " + answer;

  // add on thousands, millions, billions
  answer +=
      " " +
      name3[counterFunctionCalls + 1];  // note special case of null strings
                                        // for hundreds
  string leftAnswer = "";
  // check if there are more digits to the left of the current 3 digits to
  // convert
  //   if so, call the function recursively
  if (toConvert >= 1000)
    leftAnswer = figureString(toConvert / 1000, counterFunctionCalls + 1);
  // NOTE:  the left answer (determined by recursion) comes first, followed by
  // the current answer
  return leftAnswer + " " + answer;
}

ostream& operator<<(ostream& out, const Number& r) {
  out << r.getString();
  return out;
}

istream& operator>>(istream& in, Number& r) {
  int work;
  in >> work;
  r.setValue(work);
  return in;
}

Number operator+(int n, const Number& r)  // mixed mode, int on left
{
  return r + n;
}

Number Number::operator+(const Number& r) const {
  return Number((*this).getInteger() + r.getInteger());
}

Number Number::operator+(int n) const {
  return Number((*this).getInteger() + n);
}

Number operator*(int n, const Number& r)  // mixed mode, int on left
{
  return r * n;
}

Number Number::operator*(const Number& r) const {
  return Number((*this).getInteger() * r.getInteger());
}

Number Number::operator*(int n) const {
  return Number((*this).getInteger() * n);
}

bool Number::operator==(const Number& r) const {
  return (*this).getInteger() == r.getInteger();
}

bool Number::operator<(const Number& r) const {
  return (*this).getInteger() < r.getInteger();
}

const Number& Number::operator=(const Number& r) {
  if (this == &r) return *this;
  (*this).theNumber = r.theNumber;
  (*this).theString = r.theString;
  return *this;
}

const Number& Number::print(ostream& out) const {
  out << getInteger() << " is " << getString();
  return *this;
}
