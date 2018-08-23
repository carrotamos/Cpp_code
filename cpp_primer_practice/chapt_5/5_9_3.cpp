#include<iostream>
using namespace std;

int main()
{
	int i;
    int sum =0;
	do
	{
		cout<<"enter the number: ";
		cin>>i;
		sum += i;
		if(i != 0)
		{
			cout<<"now the sum is: "<<sum<<endl;
		}
		else
		{
			cout<<"The end sum is: "<<sum<<endl;
			cout<<"EXIT!!!"<<endl;
		}
	}
	while(i != 0);

	return 0;
}
