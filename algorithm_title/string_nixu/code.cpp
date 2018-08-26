#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;

char* my_inverted(char *pre);
int main()
{
	char str[20];
	cout<<"enter a string: ";
	cin.getline(str,20);
	cout<<str<<endl;
	my_inverted(str);
	cout<<str<<endl;
	return 0;

}

char* my_inverted(char *pre)
{
	assert(nullptr != pre);
	if(strlen(pre) == 0)
	{
		cout<<*pre<<"is none"<<endl;
	}
	else
	{
		const int len = strlen(pre);
		char t = '0';
		for(int i=0;i<len/2;i++)
		{
			t = pre[i];
			pre[i] = pre[len - i - 1];
			pre[len - i -1]  = t;
		}

		return pre;
	}
		

}
