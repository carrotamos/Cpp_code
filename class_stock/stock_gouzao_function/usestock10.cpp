#include<iostream>
#include"stock10.h"

int main()
{
		{
				using std::cout;
				cout<<"Using constructors to create new objects"<<endl;

				Stock stock1("Mike",12,20.0);
				stock1.show();

				Stock stock2("Bob",2,2.0);
				stock2.show();

				cout<<"Assigning stock1 to stock2: "<<endl;
				stock2 = stock1;

				cout<<"Listing stock1 and stock2: "<<endl;
				stock1.show();
				stock2.show();

				cout<<"Using a constructor to reset an object"<<endl;
				stock1 = Stock("Amos",10,50.0);
				cout<<"Revised stock1: "<<endl;
				stock1.show();

				cout<<"Done"<<endl;
		}
		return 0;

}
