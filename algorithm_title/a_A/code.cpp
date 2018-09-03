#include<iostream>
#include<assert.h>
#include<cstring>
using namespace std;
char* my_change(char *pre);
char* you_change(char *you_pre);
const int size = 20;
int main()
{
	char str[size];
	char you_str[size];
	cout<<"enter the str: ";
	cin.getline(str,size);
	cout<<"enter you_str: ";
	cin.getline(you_str,size);
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
		//	pre[i] = pre[i]-32;
			pre[i] -= 'a' -'A';
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
