#include<iostream>
using namespace std;
int main()
{
	int i;
	int value[10];
	int sum=0;
	const char* months[12] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"Setember",
	"October",
	"November",
	"December"};

	for(i=0;i<12;i++)
	{
		cout<<"Enter the sale_value of "<<months[i]<<": ";
		cin>>value[i];
		cout<<endl;

		sum = sum + value[i];
	}

	for(i=0;i<12;i++)
	{
		cout<<months[i]<<": "<<value[i]<<endl;
	}

	cout<<"Total sale value is: "<<sum<<endl;
	return 0;

}
