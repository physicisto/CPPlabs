#include "Book.h"



Book::Book()
{
}

Book::Book(string n, string a, int y): name(n), author(a),year(y) {}
string Book::getName() {
	return this->name;
}
string Book::getAuthor() {
	return author;
}
int Book::getYear() {
	return year;
}
ostream& operator<<(ostream& o, Book b) {
	o << b.name << " " << b.author << " " << b.year;
	return o;
}
Book::~Book()
{
}
