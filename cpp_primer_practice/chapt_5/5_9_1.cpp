#include<iostream>
using namespace std;

int main()
{
	int i;
	int a,b;
	int sum;
	cout<<"PLease enter the min number:  ";
	cin>>a;
	cout<<"Please enter the max number:  ";
	cin>>b;

	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;

	for(i = a; i <= b; i++)
	{
		sum+=i;
	}

	cout<<"The sum is: "<<sum<<endl;
	return 0;
}
