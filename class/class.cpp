#include<iostream>
using namespace std;
class Box
{
	public:
		double length;
		double breadth;
		double height;
};

int main()
{
	Box Box1;
	Box Box2;
	double volume = 0.0;
	
	Box1.height  = 5.8;
	Box1.length = 3.1;
	Box1.breadth = 7.6;

	Box2.height = 7.5;
	Box2.length = 5.5;
	Box2.breadth = 4.4;

	volume = Box1.height * Box1.length * Box1.breadth;
	cout<<"Box1's Volume:"<<volume<<endl;

	volume = Box2.height * Box2.length * Box2.breadth;
	cout<<"Box2's Volume:"<<volume<<endl;

	return 0;
}
