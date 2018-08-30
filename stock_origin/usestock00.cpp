#include<iostream>
#include"stock00.h"
int main()
{
		Stock didi;
		didi.acquire("DiDi",20,12.50);
		didi.show();
		didi.buy(15,18.125);
		didi.show();
		didi.sell(400,1.20);
		didi.show();
		didi.buy(300000,40.125);
		didi.show();
		didi.sell(300000,0.125);
		didi.show();
		return 0;
}


/*
Company: DiDi
Shares: 20
share price: $12.5
Total worth: $250
Company: DiDi
Shares: 35
share price: $18.125
Total worth: $634.375
You are sell more than your share, Transaction is absorted
Company: DiDi
Shares: 35
share price: $18.125
Total worth: $634.375
Company: DiDi
Shares: 300035
share price: $40.125
Total worth: $1.20389e+07
Company: DiDi
Shares: 35
share price: $0.125
Total worth: $4.375

 */
