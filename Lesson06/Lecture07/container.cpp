//    CIS 235      Lecture 7 Container
#include "container.h"
#include <cstring>

container::container(void)
{
	setSize(20).setUsed(0).setDesc("Container to be set later");
}
container::container( const container & other)
{
  setSize(other.getSize()).setUsed(other.getUsed()).setDesc(other.getDesc());
}
container::container( long s, long u, const char d[])
{
	setSize(s).setUsed(u).setDesc(d);
}
//*****************************************************************
container::~container()
{
	delete [] desc;
}
//*****************************************************************
long container::getSize(void) const
{
	return size;
}
long container::getUsed(void) const
{
	return used;
}
const char * container::getDesc(void) const
{
	return desc;
}

container & container::setSize(long s)
{
	size = s;
	return *this;    // for function chaining
}
container & container::setUsed(long u)
{
	used = u;
	return *this;    // for function chaining
}
container & container::setDesc(const char d[])
{
	desc = new char [strlen(d) + 1];
	strcpy(desc,d);
	return *this;    // for function chaining
}

container & container::changeDesc(const char w[])
{
	delete [] desc;   // give back memory already allocated
	setDesc(w);
	return *this;    // for function chaining
}
const container & container::operator=(const container & r) 
{
	if ( this == & r ) return *this;
	this->size = r.size;
	this->used = r.used;
	this->changeDesc(r.getDesc());
	return *this;    // for function chaining
}