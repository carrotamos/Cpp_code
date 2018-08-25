#include<iostream>
#include<cstring>
using namespace std;
int my_atoi(char *ptr);
int main()
{

}


int my_atoi(char *ptr)
{
	int value = 0;
	int times = 1;
	int i;
	const int len = strlen(ptr);
	if( ptr == nullptr)
	{
		cout<<"error!"<<endl;
	}
	else
	{
		for(i = len -1;i >= 0;i--)
		{
			value += (ptr[i] - '0') * times;
			times *= 10;
		}

	}


	return value;
}
