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


class Rectangle: public Shape
{
	public:
		int get_area();
};

int Rectangle::get_area()
{
	return (width * height);
}


int main(void)
{
	int result;
	Rectangle Rect;
	Rect.set_width(5);
	Rect.set_height(4);

	result = Rect.get_area();
	cout<<"The Rectangle's area is : "<<result<<endl;

	return 0;
}
