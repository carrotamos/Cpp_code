#include"person.h"
using namespace std;


Person::Person(const std::string& ln,  const char* fn)
{
		lname = ln;
		strcpy(fname,fn);
}

void Person::show() const
{
		cout<<lname<<" "<<fname<<endl;
}

void Person::Formalshow() const
{
		cout<<fname<<" "<<lname<<endl;
}







