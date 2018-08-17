/*
 
 （1）声明一个长度为10的整型数组；

 （2）输入数组元素；

 （3）寻找数组中的最大值元素和这个元素的下标；

 （4）输出最大值元素的值和它的下标值。

 */
#include<iostream>

using namespace std;

int main()
{
	int array[10];
	int i;
	int biggest = 0;
	int biggest_i = 0;
	cout<<endl<<endl<<"pleasr input 10 number(int) for your array: "<<endl;
	for(i = 0;i < 10;i++)
	{
		cin >> array[i];
	}
	cout<<"Your array is:"<<endl;

	for(i = 0;i < 10; i++)
	{
		cout<<array[i];
		cout<<"  ";
	}
	cout<<endl;

	for(i = 0;i <10; i++)
	{
		if(array[i]>biggest)
		{
			biggest = array[i];
			biggest_i = i;
		}
		
	}

	cout<<"The biggest number is : "<<biggest<<endl;
	cout<<"THe biggest i is: "<<biggest_i<<endl;

	cout<<"array["<<biggest_i<<"] ="<<biggest<<endl;




	return 0;
}

