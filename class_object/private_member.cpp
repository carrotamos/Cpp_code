
#include<iostream>
using namespace std;

class Box
{
	public:	
		double length;
		void set_width(double wid);
		double get_width(void);
	private:
		double width;

};

void Box::set_width(double wid)
{
	width = wid;
}

double Box::get_width(void)
{
	return width;
}

int main()
{
	Box box;
	
	box.length = 15.4;
	cout<<"length of box is : "<<box.length<<endl;
	
	box.set_width(8.88);
	cout<<"width od box is : "<<box.get_width()<<endl;

	return 0;

}
