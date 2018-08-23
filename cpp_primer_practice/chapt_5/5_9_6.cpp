#include<iostream>
using namespace std;

int main()
{
	int i,j;
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
	int value[3][12];

	for(i=0;i<3;i++)
	{
		cout<<"enter the "<<i+1<<" year's sale value: ";
		for(j=0;j<12;j++)
		{
			cin>>value[i][j];
		}
	}

	for(i=0;i<3;i++)
	{
		cout<<"The "<<i+1<<"year's sale situation: "<<endl;
		for(j=0;j<12;j++)
		{
			cout<<value[i][j]<<"  ";
			sum = sum + value[i][j];
		}
		cout<<endl;
	}

	cout<<"sum is: "<<sum<<endl;

	

	return 0;





}
