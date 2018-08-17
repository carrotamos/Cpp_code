/*
   使用以下语句：

   const int n=20;

   int a[n]; int *pa[n];  int i;

   for(i=0; i<n; i++)

      a[i]=i+1;

	  编写完整的程序，通过pa数组修改数组a元素的值，使其元素值自增10，然后通过pa数组遍历a数组，输出全部元素值，要求每行输出10个元素。
 */


#include<iostream>
using namespace std;
int main()
{
	const int n =20;
	int i;
	int a[n] = {1,2,3,4,5,6,7,8,9,10,
				11,12,13,14,15,16,17,18,19,20};
	int *pa[n];

	for(i = 0;i<n;i++)
	{
		pa[i] = &a[i];
	}

	cout<<endl;
	cout<<"Origin array is : "<<endl;

	for(i = 0;i < 10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(i = 10;i<20;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	cout<<endl<<endl<<"every array factor +10"<<endl;

	for(i=0;i<n;i++)
	{
		*pa[i] = *pa[i]+10;
	}

	cout<<endl;
	cout<<"The last array is: "<<endl;

	for(i=0;i<10;i++)
	{
		cout<<*pa[i]<<" ";
	}
	cout<<endl;
	for(i=10;i<n;i++)
	{
		cout<<*pa[i]<<" ";
	}
	cout<<endl;

	return 0;






}
