#include<iostream>
#include"stock10.h"
using namespace std;
int main()
{
		{
				using std::cout;
				cout<<"Using constructors to create new objects"<<endl;
				
				Stock stock3;
				stock3.show();
				cout<<endl;

				Stock stock4 = Stock("timmy",12,80.8);
				stock4.show();
				cout<<endl;

				Stock stock5 = Stock("baidu",50,5.0);
				stock5.show();
				cout<<endl;

				Stock stock1("Mike",12,20.0);
				stock1.show();
				cout<<"total_val = "<<stock1.get_total_value()<<endl;
				cout<<endl;
				

				Stock stock2("Bob",2,2.0);
				stock2.show();
				cout<<endl;

				cout<<"Assigning stock1 to stock2: "<<endl;
				stock2 = stock1;

				cout<<"Listing stock1 and stock2: "<<endl;
				stock1.show();
				cout<<endl;
				stock2.show();
				cout<<endl;
				cout<<"Using a constructor to reset an object"<<endl;
				stock1 = Stock("Amos",10,50.0);
				cout<<"Revised stock1: "<<endl;
				stock1.show();
				cout<<endl;
				cout<<"Done"<<endl;
		}
		return 0;

}


/*
Using constructors to create new objects
Constructor using Mikecalled
Company: Mike
Shares: 12
Shares price: 20.000
Total worth: 240.00
Constructor using Bobcalled
Company: Bob
Shares: 2
Shares price: 2.000
Total worth: 4.00
Assigning stock1 to stock2: 
Listing stock1 and stock2: 
Company: Mike
Shares: 12
Shares price: 20.000
Total worth: 240.00
Company: Mike
Shares: 12
Shares price: 20.000
Total worth: 240.00
Using a constructor to reset an object
Constructor using Amoscalled
Bye, Amos
Revised stock1: 
Company: Amos
Shares: 10
Shares price: 50.000
Total worth: 500.00
Done
Bye, Mike
Bye, Amos

 */
