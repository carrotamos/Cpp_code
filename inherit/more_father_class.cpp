//多继承
#include<iostream>
using namespace std;

class Shape
{
	public:
		void set_width(int wid);
		void set_height(int hei);
	protected:
		int width;
		int height;
};

void Shape::set_width(int wid)
{
	width = wid;
}

void Shape::set_height(int hei)
{
	height = hei;
}




class Paintcost
{
	public:
		int get_cost(int area);
};

int Paintcost::get_cost(int area)
{
	return area * 70;
}




class Rectangle: public Shape, public Paintcost
{
	public:
		int get_area();
};

int Rectangle::get_area()
{
	return width * height;
}

int main()
{
	Rectangle Rect;
	int area;
	int cost;
	Rect.set_width(5);
	Rect.set_height(7);
	area = Rect.get_area();

	cout<<"Total area is: "<<area<<endl;
	
	cost = Rect.get_cost(area);
	cout<<"Total cost is : "<<cost<<endl;
	return 0;
}


















