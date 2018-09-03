#include "stock20.h"
using namespace std;
Stock::Stock()
{
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	company = co;
	if(n<0)
	{
		std::cout<<"Number of shares can't be negative!"<<endl;
		std::cout<<company<<" 's shares set to 0!"<<endl;
		shares = 0;
	}

	else
	{
		shares = n;
	}

	share_val = pr;
	set_tol();
}

Stock::~Stock()
{

}

void Stock::buy(long num, double price)
{
	if(num<0)
	{
		std::cout<<"Number of shares purchased can't be negative! Transaction is abroted!"<<endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tol();
	}
}


void Stock::sell(long num, double price)
{
	if(num<0)
	{
		std::cout<<"Numvber to sell can't be negative! Transaction is aborted!"<<endl;
	}
	else if(num > shares)
	{
		std::cout<<"You can't sell more than you have!"<<endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tol();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tol();
}

void Stock::show() const
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig = 
		cout.setf(ios_base::fixed, ios_base::floatfield);

	std::streamsize prec = cout.precision(3);

	cout<<"Company: "<<company<<endl;
	cout<<"Shares: "<<shares<<endl;
	cout<<"share price: "<<share_val<<endl;
	cout.precision(2);
	cout<<"Total Worth: $"<<total_val<<endl;
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
	if(s.total_val > total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}




/*
class Stock
{
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tol()
	{
		total_val = shares * share_val;
	}
				   
public:
	Stock();
	Stock(const std::string & co, long n=0, double pr = 0.0 );
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock & s) const;
};
 */
