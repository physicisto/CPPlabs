#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "Book.h"
using namespace std;

class BookSorter {
	int n;
public:
	BookSorter(int n) :n(n) {};
	bool operator()(Book* b1, Book* b2) {
		if (n == 1)
			return b1->getName() < b2->getName();
		else
			return b1->getAuthor() < b2->getAuthor();
	}
};
class BookFinder {
	int min, max;
public:
	BookFinder(int a, int b) :min(a),max(b) {};
	bool operator()(Book* b1) {
		return ((b1->getYear() <= max) && (b1->getYear() >= min));
	}
};


void main() {
	setlocale(LC_ALL, "RUSSIAN");
	std::vector<Book*> books;
	books.push_back(new Book("\"Игра престолов\"", "Мартин", 1992));
	books.push_back(new Book("\"Алмазный меч\"", "Перумов", 1990));
	books.push_back(new Book("\"Меч истины\"", "Гудкайнд", 1998));
	books.push_back(new Book("\"Гарри Поттер\"", "Ролинг", 2002));

	cout << "Книги в алфавитном порядке по названию: " << endl;
	BookSorter b1(1);
	sort(books.begin(), books.end(), b1);
	for (int i = 0; i < books.size();i++)
		cout << *books[i] << endl;
	cout << endl;

	cout << "Книги в алфавитном порядке по автору: " << endl;
	BookSorter b2(2);
	sort(books.begin(), books.end(), b2);
	for (int i = 0; i < books.size(); i++) 
		cout << *books[i] << endl;
	cout << endl;

	cout << "Книги в диапазоне года издания 1992 - 2000: " << endl;
	BookFinder b(1992, 2000);
	vector<Book*>::iterator finder = find_if(books.begin(), books.end(), b);
	while (finder != books.end()) {
		cout << *(*finder) << endl;
		finder = find_if(++finder, books.end(), b);
	}


	for (int i = 0; i < books.size(); i++)
		delete books[i];
	system("pause");
}





















/*vector<Book*>::iterator finder = find_if(books.begin(), books.end(), b);
for (finder; finder != books.end(); finder++) {
	cout << *(*finder) << endl;
	vector<Book*>::iterator finder = find_if(books.begin(), books.end(), b);
}*/