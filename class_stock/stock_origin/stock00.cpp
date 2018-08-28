#include<iostream>
#include"stock00.h"

void Stock::acquire(const std::string& co, long n, double pr)
{
		company = co;
		if(n<0)
		{
				std::cout<<"NUmber of shares cant't be negative "<<company<<" shares set to 0"<<endl;
				shares = 0;
		}
		else
		{
				shares = n;
		}
		share_val = pr;
		set_tot();
}

void Stock::buy(long num, double price)
{
		if(num<0)
		{
				std::<<"Number of shares purchased cant't be negative"<<endl<<company<<"Transaction is aborted"<<endl;
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
		using std::cout;
		if(num<0)
		{
				cout<<"NUmber of shares sold can't be negative"<<endl<<"Transaction is aborted!"<<endl;
		}
		else if(num>shares)
		{
				cout<<"You are sell more than your share, Transaction is absorted"<<endl;
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
		std::cout<<"Company: "<<company<<endl;
		std::cout<<"Shares: "<<shares<<endl;
		std::cout<<"share price: $"<<share_val<<endl;
		std::cout<<"Total worth: $"<<total_val<<endl;
}




