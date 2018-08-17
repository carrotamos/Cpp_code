/*
输入一个矩阵的元素，并输出指定行的元素
 */

#include<iostream>
using namespace std;

int main()
{
	const int n=5;

	int intary[n][n];
	int k;
	
	int i;
	int j;

	int x,y;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>intary[i][j];
		}
	}
	cout<<endl<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<intary[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"输入行号:  ";
	cin >>x;
	
	while(x>=5)
	{
		cout<<"input again :  ";
		cin>>x;
	}

	cout<<endl;


	cout<<"输入列号:  ";
	cin>>y;
	while(y>=5)
	{
		cout<<"input again :  ";
		cin>>y;
	}
	cout<<endl;


	cout<<"intary["<<x<<"]["<<y<<"] = "<<intary[x][y]<<endl;

	return 0;



	
}
