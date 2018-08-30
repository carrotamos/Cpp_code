#ifndef Bank_H_
#define Bank_H_

#include<iostream>
#include<string>
class Bank
{
		private:
				std::string user_name;
				std::string user_id;
				double money;
		public:
				Bank(const std::string& name,const std::string& id,double mon);
				~Bank();
				

				void show();
				void save(double num);
				void draw(double num);
				void usersave();
};

#endif
