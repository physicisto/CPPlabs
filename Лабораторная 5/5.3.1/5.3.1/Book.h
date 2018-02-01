#pragma once
#include <iostream>
#include <string>
using namespace std;


class Book
{
	string name;
	string author;
	int year;
public:
	Book();
	Book(string n, string a, int y);
	~Book();
	string getName();
	string getAuthor();
	int getYear();
	friend ostream& operator<<(ostream& o, Book b);
};

