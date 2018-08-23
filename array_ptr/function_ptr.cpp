#include<iostream>
using namespace std;

double get_Average(int *ptr,int size);

int main()
{
	int var[5] = {1,3,3,4,5};
	double average;
	average = get_Average(var,5);
	cout<<"the average is: "<<average<<endl;
	return 0;
}

double get_Average(int *ptr ,int size)
{
	int i,sum = 0;
	double ave=0.0;
	for(i=0;i<size;i++)
	{
		sum = sum + *ptr;
		ptr++;
	}
	ave = double(sum)/size;
	return ave;

}
