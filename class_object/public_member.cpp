#include<iostream>
using namespace std;

class Line
{
	public:
		double length;
		void set_length(double len);
		double get_length(void);
};

double Line::get_length(void)
{
	return length;
}

void Line::set_length(double len)
{
	length = len;
}

int main()
{
	double length_cout;
	Line line;
	line.set_length(6.6);

	length_cout = line.get_length();

	cout<<"line's length is: "<<length_cout<<endl;
	return 0;
}


