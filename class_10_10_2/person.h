#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<cstring>
using namespace std;
class Person
{
		private:
				static const int LIMIT = 25;
				string lname;
				char fname[LIMIT];
		public:
				
				Person() {lname = ""; fname[0] = '\0';}
				Person(const std::string& ln,  const char* fn = "Heyou");

				void show() const;
				void Formalshow() const;
};

#endif
