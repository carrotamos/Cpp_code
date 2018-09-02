#include"stock20.h"
const int stks = 4;
using namespace std;
int main()
{
	Stock stock[stks] = {
		Stock("DiDi",12,3.5),
		Stock("BaiDu",76,20.0),
		Stock("JD",10,9.4),
		Stock("MeiTuan",100,90)
	};

	std::cout<<"Stock holding: "<<endl;
	int st;
	for(st = 0;st<stks; st++)
	{
		stock[st].show();
		std::cout<<endl;
	}

	const Stock *top = &stock[0];
	for(st = 1;st <stks;st++)
	{
		top = &top->topval(stock[st]);
	}

	std::cout<<"Most valuable holding: "<<endl;
	top->show();
	return 0;
}
