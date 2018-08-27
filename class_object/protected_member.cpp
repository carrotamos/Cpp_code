#include<iostream>
using namespace std;

class Box
{
	protected:
		double width;
};

class smallbox:Box
{
	public:
		void set_smallwidth(double wid);
		double get_smallwidth(void);
};

void smallbox::set_smallwidth(double wid)
{
	width = wid;
}

double smallbox::get_smallwidth(void)
{
	return width;
}

int main()
{
	double result;
	smallbox box;
	
	box.set_smallwidth(8.88);
	result = box.get_smallwidth();
	
	cout<<"width of box is : "<<result<<endl;
	return 0;
}
