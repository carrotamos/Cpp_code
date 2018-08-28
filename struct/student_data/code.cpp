#include<iostream>

using namespace std;

struct Data
{
	int year;
	int month;
	int day;
};

struct Student
{
	long long num;
	char name[20];
	char sex[5];
	int age;
	Data birthday;
	float score;
	char addr[30];
};

int main()
{
	Student timmy;
	
	cout<<"please enter your student-id:  "<<endl;
	cin>>timmy.num;
	cout<<"please enter your name:  "<<endl;
	cin>>timmy.name;
	cout<<"please enter your sex:  "<<endl;
	cin>>timmy.sex;
	cout<<"please enter your age:  "<<endl;
	cin>>timmy.age;
	cout<<"please enter your year-month-day:  "<<endl;
	cin>>timmy.birthday.year;
	cin>>timmy.birthday.month;
	cin>>timmy.birthday.day;

	cout<<"please enter your score:  "<<endl;
	cin>>timmy.score;
	cout<<"please enter your addr:  "<<endl;
	cin>>timmy.addr;

	cout<<"student-id: "<<timmy.num<<endl;
	cout<<"name:  "<<timmy.name<<endl;
	cout<<"sex:  "<<timmy.sex<<endl;
	cout<<"age:  "<<timmy.age<<endl;
	cout<<"birthday:  "<<timmy.birthday.year<<"/"<<timmy.birthday.month<<"/"<<timmy.birthday.day<<endl;
	cout<<"score:  "<<timmy.score<<endl;

	cout<<"addr:  "<<timmy.addr<<endl;
	return 0;
}
