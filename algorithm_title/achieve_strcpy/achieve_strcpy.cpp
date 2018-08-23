#include<iostream>
#include<stdio.h>
using namespace std;
char* my_strcpy(char *pre,const char *next);
int main()
{
	char a[10] = "hello";
	char b[10] = "world";

	cout<<"before change!"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	my_strcpy(a,b);
	

	cout<<endl;
	cout<<"after change!"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	return 0;

}

char* my_strcpy(char *pre,const char *next)
{
	if(pre == nullptr || next == nullptr)
	{
		return nullptr;
	}

	else if(pre == next)
	{
		return pre;
	}

	else
	{
		while(*pre != '\0')
		{
			*pre = *next;
			pre++;
			next++;
		}
		return pre;
	}
}


/*
before change!
a: hello
b: world

after change!
a: world
b: world
 */
