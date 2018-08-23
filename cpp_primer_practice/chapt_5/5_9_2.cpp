#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int n = 100;

int main()
{
	vector<int> vec;
	int i;
	long long result=1;
	for(i=1;i<=100;i++)
	{
		vec.push_back(i);
	}

	for(i=0;i<100;i++)
	{
		cout<<"vec["<<i<<"] = "<<vec[i]<<endl;
	}

	for(i=0;i<100;i++)
	{
		result = result + vec[i];
	}

	cout<<"result = "<<result<<endl;

	return 0;


}
