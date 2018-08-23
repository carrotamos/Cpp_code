#include<iostream>
using namespace std;

class printdata
{
	public:
		void print(int i);
		void print(double f);
		void print(char c[]);
};

void printdata::print(int i)
{
	cout<<"整数为: "<<i<<endl;
}
void printdata::print(double f)
{
	cout<<"浮点数为: "<<f<<endl;
}
void printdata::print(char c[])
{
	cout<<"字符串为: "<<c<<endl;
}

int main()
{
	printdata pd;

	pd.print(5);
	pd.print(8.8);
	
	char d[] = "Hello world";
	pd.print(d);

	return 0;
}
