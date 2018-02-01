#include <iostream>
#include "DataManager.h"
using namespace std;

void main() {
	DataManager<int> ints;
	DataManager<double> doubles;
	DataManager<char> chars;

	ints.push(42);
	cout << "Second element: " << ints.peek() << endl<<"in array: ";
	ints.print();
	cout << "------------------------------------------------------------" << endl;
	int a[64] = {34,56,99,21};
	ints.push(a, 64);
	cout << "Second element: " << ints.peek() << endl << "in array: ";
	ints.print();
	cout << "------------------------------------------------------------" << endl;
	ints.push(45);
	double d[5] = { 12.313,1232.3,3112,2.09,323.2 };
	doubles.push(d, 5);
	cout << "Array of double: ";
	doubles.print();
	cout << "- "<< doubles.pop() << endl;
	cout << "= ";
	doubles.print();
	cout << "------------------------------------------------------------" << endl;

	char c[] = "Hello, World! fG";
	cout <<"Array of char: "<< c << endl;
	chars.push(c, 16);
	cout << "Array of char: ";
	chars.print();
	cout << "------------------------------------------------------------" << endl;
	cout << "Pop to lower: " << chars.popLower() << endl;
	cout << "Pop to upper: " << chars.popUpper() << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Array of char: ";
	chars.print();

	system("pause");
}