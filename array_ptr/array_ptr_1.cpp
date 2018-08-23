#include<iostream>
#include<ctime>

using namespace std;
void get_seconds(unsigned long *par);

int main()
{
	unsigned long sec;
	get_seconds(&sec);

	cout<<"number of seconds: "<<sec<<endl;
	return 0;
}

void get_seconds(unsigned long *par)
{
	*par = time(NULL);
	return;
}
