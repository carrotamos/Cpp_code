#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int *get_random()
{
	int i;
	static int r[10];

	srand( (unsigned)time(NULL) );
	for(i=0;i<10;i++)
	{
		r[i]=rand();
		cout<<r[i]<<endl;
	}

	return r;
}

int main()
{
	int *p;
	int i;
	p = get_random();
	for(i=0;i<10;i++)
	{
		cout<<"*(p + "<<i<<"): ";
		cout<<*(p+i)<<endl;
	}
	return 0;
}



//result:
/*
   372418645
   1584556882
   1444259035
   1780972220
   1782810591
   1263399940
   1685201281
   872128630
   792411807
   1575433247
   *(p + 0): 372418645
   *(p + 1): 1584556882
   *(p + 2): 1444259035
   *(p + 3): 1780972220
   *(p + 4): 1782810591
   *(p + 5): 1263399940
   *(p + 6): 1685201281
   *(p + 7): 872128630
   *(p + 8): 792411807
   *(p + 9): 1575433247
 */
