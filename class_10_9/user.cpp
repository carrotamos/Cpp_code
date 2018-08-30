#include"Bank.h"
using namespace std;
int main()
{
		cout<<"Bank System"<<endl;

		Bank Amos = Bank("Amos","440582199610045498",0.0);
		Amos.show();
		cout<<endl;

		Amos.usersave();
		Amos.show();
		cout<<endl;

		Amos.save(3000.0);
		Amos.show();
		cout<<endl;

		Amos.draw(357.0);
		Amos.show();
		cout<<endl;
		return 0;

}

    
