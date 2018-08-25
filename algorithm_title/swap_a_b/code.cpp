//不使用第三个变量交换两个数的值 
#include<iostream>
using namespace std;
void swap(int *A,int *B);

int main()
{
	int a,b;
	cout<<"enter a: ";
	cin>>a;
	cout<<"enter b: ";
	cin>>b;

	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	swap(&a,&b);
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	
	return 0;

}

void swap(int *A,int *B)
{
	*A = *A + *B;
	*B = *A - *B;
	*A = *A - *B;
	return;

}
