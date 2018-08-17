#include<iostream>
#include<cstring>

using namespace std;
void printbook(struct Books *book);

struct Books
{
	char title[50];
	char author[50];
	char subject[50];
	int book_id;
};

int main()
{
	Books Book1;
	Books Book2;

	strcpy(Book1.title,"C++");
	strcpy(Book1.author,"amos");
	strcpy(Book1.subject,"language");
	Book1.book_id =123;

	strcpy(Book2.title,"css");
	strcpy(Book2.author,"amos");
	strcpy(Book2.subject,"language");
	Book2.book_id = 456;


	printbook(&Book1);

	printbook(&Book2);

	return 0;

}

void printbook(struct Books *book)
{
	cout<<"book's title: "<<book->title<<endl;
	cout<<"book's author: "<<book->author<<endl;
	cout<<"book'subject: "<<book->subject<<endl;
	cout<<"book's id: "<<book->book_id<<endl;
}






