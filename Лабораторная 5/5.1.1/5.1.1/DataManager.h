#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class DataManager {
protected:
	T array[64];
	int N;
public:

	DataManager() {
		N = 0;
	};

	~DataManager() {};

	void push(T elem) { //данные пишутс€ в начало набора, остальные смещаютс€ вправо
		if (N < 64) {
			T arr[64];
			for (int i = 0; i < N; i++) { //копируем со сдвигом на 1 элемент
				arr[i + 1] = array[i];
			}
			N++;
			arr[0] = elem;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < 64; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			N = 1;
			array[0] = elem;
		}
	};

	void push(T elems[], int n) {
		if (N+n <= 64) {
			T arr[64];
			for (int i = 0; i < N; i++) { //копируем со сдвигом на n элементов
				arr[i + n] = array[i];
			}
			for (int i = 0; i < n; i++) {
				arr[i] = elems[i];
			}
			N += n;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < N; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			if (n > 64)
				N = 64;
			else {
				N = n;
				for (int i = 0; i < N; i++) {
					array[i] = elems[i];
				}
			}
		}
	};

	T peek() { //возвращает второй элемент в наборе или 0, если элементов в наборе меньше 2
		if (N < 2)
			return 0;
		else
			return array[1];
	};

	T pop() { //извлекает последний элемент
		if (N != 0) {
			N--;
			return array[N];
		}
	};

	void print() {
		for (int i = 0; i < N; i++) {
			cout << array[i] <<" ";
		}
		cout << endl ;
	};
};

template<>
class DataManager<char> {
protected:
	char array[64];
	int N;
public:
	DataManager() {
		N = 0;
	};
	~DataManager() {};
	void push(char elem) {
		if (elem == '!' || elem == '?' || elem == '/' || elem == '.' || elem == ',' || elem == ' ' || elem == '-')
			elem = '_';
		if (N < 64) {
			char arr[64];
			for (int i = 0; i < N; i++) { //копируем со сдвигом на 1 элемент
				arr[i + 1] = array[i];
			}
			N++;
			arr[0] = elem;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < 64; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			N = 1;
			array[0] = elem;
		}
	};
	void push(char elems[], int n) {
		for (int i = 0; i < n; i++) {
			if (elems[i] == '!' || elems[i] == '?' || elems[i] == '/' || elems[i] == '.' || elems[i] == ',' || elems[i] == ' ' || elems[i] == '-')
				elems[i] = '_';
		}
		if (N + n <= 64) {
			char arr[64];
			for (int i = 0; i < N; i++) { //копируем со сдвигом на n элементов
				arr[i + n] = array[i];
			}
			for (int i = 0; i < n; i++) {
				arr[i] = elems[i];
			}
			N += n;
			for (int i = 0; i < N; i++) {
				array[i] = arr[i];
			}
		}
		else {
			ofstream f("dump.dat", ios_base::app);
			for (int i = 0; i < N; i++) {
				f << array[i] << " ";
			}
			f << endl;
			f.close();
			if (n > 64)
				N = 64;
			else {
				N = n;
				for (int i = 0; i < N; i++) {
					array[i] = elems[i];
				}
			}
		}
	};
	char peek() {
		if (N < 2)
			return 0;
		else
			return array[1];
	};
	char pop() {
		if (N != 0) {
			N--;
			return array[N];
		}
	};
	char popUpper() {
		if (N != 0 && ((('a' <= array[N-1]) && (array[N-1] >= 'z'))||(('а' <= array[N-1]) && (array[N-1] >= '€')))) {
			N--;
			return toupper(array[N]);
		}
	};
	char popLower() {
		if (N != 0 && ((('A' <= array[N-1]) && (array[N-1] >= 'Z'))||(('ј' <= array[N-1]) && (array[N-1] >= 'я')))) {
			N--;
			return tolower(array[N]);
		}
	};
	void print() {
		for (int i = 0; i < N; i++) {
			cout << array[i] ;
		}
		cout << endl;
	};
};



















/*//реализаци€ шаблонного класса DataManager
template<typename T>
DataManager::DataManager() {
	N = 0;
};
template<typename T>
DataManager::~DataManager() {

};
template<typename T>
void DataManager::push(T elem) { //данные пишутс€ в начало набора, остальные смещаютс€ вправо
	if (N < 64) {
		T arr[64];
		for (int i = 0; i < N; i++) { //копируем со сдвигом на 1 элемент
			arr[i + 1] = array[i];
		}
		arr[0] = elem;
		N++;
	}
};
template<typename T>
void DataManager::push(T elems[], int n) {

};
template<typename T>
T DataManager::peek() {

};
template<typename T>
T DataManager::pop() {

};
//реализаци€ специализированного шаблонного класса DataManager
template<char>
DataManager<char>::DataManager() {

};
template<char>
DataManager<char>::~DataManager() {

};
template<char>
void DataManager<char>::push(char elem) {

};
template<char>
void DataManager<char>::push(char elems[], int n) {

};
template<char>
T DataManager<char>::peek() {

};
template<char>
T DataManager<char>::pop() {

};
template<char>
char DataManager<char>::popUpper() {

};
template<char>
char DataManager<char>::popLower() {

};*/