#include <iostream>
using namespace std;

void swap(int& x,int& y);

int main()
{
	int a = 10;
	int b = 90;
	
	cout<<"交换前a的值: "<<a<<endl;
	cout<<"交换前b的值: "<<b<<endl;

	swap(a,b);

	cout<<"交换后a的值: "<<a<<endl;
	cout<<"交换后b的值: "<<b<<endl;
}


void swap(int& x,int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;

	return;
}
