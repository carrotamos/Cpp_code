#include<iostream>
#include<cstring>
using namespace std;
void printfbook(struct Books book);

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

int main()
{
	Books Book1;
	Books Book2;

	strcpy(Book1.title , "C++教程");
	strcpy(Book1.author, "amos");
	strcpy(Book1.subject , "code language");
	Book1.book_id = 123;
	
	strcpy(Book2.title , "Css teach");
	strcpy(Book2.author , "runnob");
	strcpy(Book2.subject , "technique");
	Book2.book_id = 345;

	printfbook(Book1);
	printfbook(Book2);

	return 0;
}

void printfbook(struct Books book)
{
	cout<<"book's title: "<<book.title<<endl;
	cout<<"book's author: "<<book.author<<endl;
	cout<<"book's subject: "<<book.subject<<endl;
	cout<<"book's id: "<<book.book_id<<endl;
}


