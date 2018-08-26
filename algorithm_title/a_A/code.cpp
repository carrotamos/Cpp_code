#include<iostream>
#include<assert.h>
#include<cstring>
using namespace std;
char* my_change(char *pre);
char* you_change(char *you_pre);
int main()
{
	char str[20];
	char you_str[20];
	cout<<"enter the str: ";
	cin>>str;
	cout<<"enter you_str: ";
	cin>>you_str;
	my_change(str);
	you_change(you_str);
	cout<<str<<endl;
	cout<<you_str<<endl;
	return 0;

}

char* my_change(char *pre)
{
	assert(pre != nullptr);
	const int len = strlen(pre);

	for(int i=0;i<len;i++)
	{
		if(pre[i]>= 'a' && pre[i]<= 'z')
		{
			pre[i] = pre[i]-32;
		}
		else
		{
			pre[i] = pre[i];
		}
		
	}

	return pre;
}


char* you_change(char *you_pre)
{
	for(char *i = you_pre;*i!= '\0';i++)
	{
		if(*i<'a'||*i>'z')
		{
			continue;
		}
		*i -= 'a'-'A';

	}
	return you_pre;



}
