#include<iostream>
using namespace std;
int get_day(int year,int month,int day);
int main()
{
	cout<<"calculate the day in this year: "<<endl;
	int year_,month_,day_,days_;
	cout<<"enter year: ";
	cin>>year_;
	cout<<"\nenter month: ";
	cin>>month_;
	cout<<"\nenter day: ";
	cin>>day_;

	days_ = get_day(year_,month_,day_);
	cout<<"days = "<<days_<<endl;
	return 0;
}

int get_day(int year,int month,int day)
{
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if((year%4 == 0 && year%100 !=0)||(year%400 == 0))
	{
		months[1] += 1;	
	}
	int days = 0;
	for(int i = 0;i<month;i++)
	{
		days = days + months[i];
	}

	days += day;
	return days;
}
