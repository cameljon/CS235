#ifndef _TEST
#define _TEST
#include <iostream>
using namespace::std;

#include "nibbleHeader.h"

class NibbleTest
{
public:
	NibbleTest( ostream & w);
	int nibbleDefaultConstructor() const;
	int nibbleCopyConstructor() const;
    int nibbleIntegerArgumentConstructor() const;
	int nibbleArrayArgumentConstructor() const;
	int nibbleDestructor() const;
	int nibbleGetDecimalValue() const;
	int nibbleGetBinaryStringObject() const;
	int nibbleGetHexCharacter() const;
	int nibbleGetCppString() const;
	int nibbleOpertorAssignment() const;
	int nibbleOperatorInsertion() const;
	int nibbleOperatorEqual() const;
	int nibbleOperarotLessThan() const;
	int nibbleOperatorPlus() const;
	int nibbleOperatorMultiply() const;
	int nibbleTestAll() const;


private:
	ostream & out;
	const static int TEST_VALUE = 5;
};

#endif
