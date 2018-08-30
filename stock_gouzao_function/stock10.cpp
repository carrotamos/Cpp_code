#include<iostream>
#include"stock10.h"
using namespace std;
Stock::Stock()
{
		std::cout<<"Default constructor called"<<endl;
		company = "no name";
		shares = 0;
		share_val = 0.0;
		total_val = 0.0;
}

Stock::Stock(const std::string& co,long n, double pr)
{
		std::cout<<"Constructor using "<<co<<"called"<<endl;
		company = co;

		if(n<0)
		{
				std::cout<<"Number of shares can't be negative ";
				std::cout<<company<<"shares set to 0"<<endl;
				shares = 0;
		}
		else
		{

				shares = n;
		}
		share_val = pr;
		set_tot();
}

Stock::~Stock()
{
		std::cout<<"Bye, "<<company<<endl;
}

void Stock::buy(long num, double price)
{
		if(num<0)
		{
				std::cout<<"Number of shares purchased can't be negative"<<endl;
				std::cout<<"Transaction is aborted"<<endl;
		}
		else
		{
				shares += num;
				share_val = price;
				set_tot();
		}
}

void Stock::sell(long num, double price)
{
		if(num > shares)
		{
				std::cout<<"You can't sell more than you have!"<<endl;
				std::cout<<"Transaction is aborted!"<<endl;
		}

		else if(num<0)
		{
				std::cout<<"Number of shares sold can't be negative!"<<endl;
				std::cout<<"Transaction is aborted!"<<endl;
		}
		else
		{
				shares -= num;
				share_val = price;
				set_tot();
		}
}

void Stock::update(double price)
{
		share_val = price;
		set_tot();
}

void Stock::show()
{
		using std::cout;
		using std::ios_base;

		ios_base::fmtflags orig = 
				cout.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = cout.precision(3);

		cout<<"Company: "<<company<<endl;
		cout<<"Shares: "<<shares<<endl;
		cout<<"Shares price: "<<share_val<<endl;
		cout.precision(2);
		cout<<"Total worth: "<<total_val<<endl;
		cout.setf(orig, ios_base::floatfield);
		cout.precision(prec);
}





















