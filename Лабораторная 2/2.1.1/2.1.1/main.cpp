#include <iostream>
#include "Arrays.h"
using namespace std;


void main() {
	Vector v2(15);
	Matrix m;
	Vector v = m.transArray();  
	cout << "vector[3]: "<< v[3] << endl;
	m.printMatrix();
	v.printVector();
	cout << endl<< m.at(1,2) << endl;  //m[1][2]
	m.setAt(1, 2, 1998);               //m[1][2]=1998
	cout << m.at(1, 2) << endl;
	m.printMatrix();
	cout << endl;
	cout << "vector[3]: " << v[3] << endl;
	++v;
	cout << "++vector[3]: " << v[3] << endl;
	--v;
	cout << "--vector[3]: " << v[3] << endl;
	Vector v3(v--);
	cout << "vector[3]--: " << v[3] << endl;
	cout << "vector3[3]: " << v3[3] << endl;
	cout << m.at(1, 2) << endl;
	++m;
	cout << m.at(1, 2) << endl;



	system("pause");
}
