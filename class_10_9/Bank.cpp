#include"Bank.h"
using namespace std;

Bank::Bank(const std::string& name,const std::string& id,double mon)
{
		std::cout<<"Buile a count, username is "<<name<<endl;
		user_id = id;
		user_name = name;
		money = mon;
		
}

Bank::~Bank()
{
		cout<<"Bye! "<<user_name;
}

void Bank::show()
{
		cout<<"Name: "<<user_name<<endl;
		cout<<"User_id: "<<user_id<<endl;
		cout<<"Money: "<<money<<endl;
}

void Bank::save(double num)
{
		money += num;
		cout<<"Your have saved $"<<num<<endl;
		cout<<"Now your money is: $"<<money<<endl;
}

void Bank::draw(double num)
{
		money -= num;
		cout<<"Your have drawed $"<<num<<endl;
		cout<<"Now your money is: $"<<money<<endl;
}


void Bank::usersave()
{
		double num;
		cout<<"Please enter the money you want to save: $";
		cin>>num;
		money += num;
		cout<<"You have saved $"<<num<<endl;
		cout<<"Now your money is: $"<<money;
}




