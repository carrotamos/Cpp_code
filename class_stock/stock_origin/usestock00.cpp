#include<iostream>
#include"stock00.h"
int main()
{
		Stock didi;
		didi.acquire("DiDi",20,12.50);
		didi.show();
		didi.buy(15,18.125);
		didi.show();
		didi.sell(400);
		didi.show();
		didi.buy(300000,40.125);
		didi.show();
		didi.sell(300000,0.125);
		didi.show();
		return 0;
}
