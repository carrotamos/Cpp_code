#ifndef STOCK00_H_
#define STOCK00_H_

#include<string>
class Stock
{
		private:
				std::string company;
				long shares;
				double share_val;
				double total_val;
				void set_tot()
				{
						total_val = shares * share_val;
				}
		public:
				void acquire(const std::string& co, long n, double pr);
				void buy(long num, double price);
				void sell(long num, double price);
				void update(double price);
				void show();
};

#endif




/*
	 set tabstop=4
	 set softtabstop=4
	 set shiftwidth=4
	 set autoindent
	 set cindent
	 set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s
	 set nu
	 set ruler
	 set hlsearch
	 set backspace=2
 */
