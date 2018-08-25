#include<iostream>
#include<string.h>
char* my_strcpy(char *pre_cpy,char *next_cpy);
char* my_strcat(char *pre_cat,char *next_cat);

int main()
{
	using namespace std;
	char a[10] = "Hello";
	char b[10] = "world";

	cout<<a<<endl<<b<<endl;
	my_strcpy(a,b);

	cout<<a<<endl<<b<<endl;

	my_strcat(a,b);
	cout<<a<<endl<<b<<endl;
	return 0;
}

char* my_strcpy(char *pre_cpy,char *next_cpy)
{
	if( next_cpy == nullptr)
	{
		return nullptr;
	}
	else
	{
		while(*pre_cpy != '\0')
		{
			*pre_cpy = *next_cpy;
			pre_cpy++;
			next_cpy++;
		}
	}

	return pre_cpy;
}

char* my_strcat(char *pre_cat,char *next_cat)
{
	if(next_cat == nullptr)
	{
		return pre_cat;
	}
	else
	{
		char *tmp_ptr = pre_cat + strlen(*pre_cat);
		while(*next_cat != '\0')
		{
			*tmp_ptr = *next_cat;
			tmp_ptr++;
			next_cat++;
		}
		return pre_cat;
	}

}
