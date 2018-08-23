#include<iostream>
using namespace std;
int main()
{
	int year=1;
	double daphne = 100.0;
	double cleo = 100.0;

	while(cleo <= daphne)
	{
		daphne = 100 * 0.1 * year + 100;
		cleo = (cleo * 0.05) + cleo;
		year++;
	}

	cout<<"daphne: "<<daphne<<endl;
	cout<<"cleo: "<<cleo<<endl;
	cout<<"year: "<<year<<endl;
	return 0;
}
