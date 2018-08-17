#include<iostream>
using namespace std;

class Box
{
	public:
		double length;
		double breadth;
		double height;

		double getvolume(void);
		void set_length(double len);
		void set_breadth(double bre);
		void set_height(double hei);

};


double Box::getvolume(void)
{
	return length*breadth*height;
}

void Box::set_length(double len)
{	
	length = len;
}

void Box::set_breadth(double bre)
{
	breadth = bre;
}

void Box::set_height(double hei)
{
	height = hei;
}

int main()
{
	Box Box1;
	Box Box2;

	double volume = 0.0;

	Box1.set_length(12.4);
	Box1.set_breadth(2.4);
	Box1.set_height(5.5);

	
	Box2.set_length(2.6);
	Box2.set_breadth(5.8);
	Box2.set_height(10.82);

	volume = Box1.getvolume();
	cout<<"Box1's volume is : "<<volume<<endl;

	volume = Box2.getvolume();
	cout<<"Box2's volume is : "<<volume<<endl;

	return 0;

}


