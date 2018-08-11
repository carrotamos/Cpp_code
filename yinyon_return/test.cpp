#include <iostream>
using namespace std;

double val[]={10.1,12.6,33.1,24.1,43.0};

double& setvalue(int i)
{
	return val[i];
}

int main()
{
	cout<<"改变前的值: "<<endl;
	for(int i=0; i<5; i++)	
	{
		cout<<"val["<<i<<"]=";
		cout<<val[i]<<endl;
	}


	setvalue(1) = 100.0;
	setvalue(3) = 200.0;

	cout<<"改变后的值: " <<endl;

	for(int i=0; i<5; i++)
	{
		cout<<"val["<<i<<"]=";
		cout<<val[i]<<endl;
	}

	return 0;
}





