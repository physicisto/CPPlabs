#include "ExpressionEvaluator.h"
#include <iostream>
#include <ios>
#include <fstream>
using namespace std;

int ExpressionEvaluator::number = 0;
ExpressionEvaluator::ExpressionEvaluator() {
	nOperands = 20;
	operands = new double [nOperands] {0.0};
}
ExpressionEvaluator::ExpressionEvaluator(int n) {
	nOperands = n;
	operands = new double [n] {0.0};
}
//------------------------------------------------------------------
//Присвоить значение value одному операнду на позиции pos:
void ExpressionEvaluator::setOperand(int pos, double value) {
	if (pos > nOperands) {						//если выход за пределы размерности массива
		double* temp = new double[pos] {0.0};	//то создаем временный массив нулей размером pos
		for (int i = 0; i < nOperands; i++)		//копируем массив operands во временный массив
			temp[i] = operands[i];				
		temp[pos - 1] = value;					//на последнюю позицию временного массива помещаем значение value
		nOperands = pos;						//присваиваем размерности массива nOperands позицию последнего элемента
		delete[]operands;						//избегаем memory leak
		operands = new double[nOperands];		//создаем новый массив operands с новой размерностью nOperands(=pos)
		for (int i = 0; i < nOperands; i++)		//копируем временный массив в operands
			operands[i] = temp[i];
		delete[]temp;							//избегаем memory leak
	}
	else {										//если не выходим за пределы размерности operands
		double* temp = new double[pos];			//то создаем временный массив размером pos
		operands[pos - 1] = value;				//последнему элементу присваиваем значение value
		int count = 0 , n = nOperands;			
		for (int i = 0; i < n; i++) {			//отсекаем последние нули в массиве operands
			count++;
			if (operands[i] == 0)
				continue;
			nOperands = count;					//новая размерность массива operands
		}
		for (int i = 0; i < nOperands; i++)		//копируем массив operands во временный массив до позиции последнего значащего числа
			temp[i] = operands[i];
		delete[]operands;						//предупреждаем memory leak
		operands = new double[nOperands];		//создаем новый массив operands с новой размерностью nOperands
		for (int i = 0; i < nOperands; i++)		//копируем временный массив в operands
			operands[i] = temp[i];
		//delete[]temp;							//освобождаем память
	}
}
//Заполнить сразу группу из N операндов массивом значений ops:
void ExpressionEvaluator::setOperands(double ops[], int N) {
	delete[]operands;
	nOperands = N;
	operands = new double[N];
	for (int i = 0; i < N; i++)
		operands[i] = ops[i];
}
//------------------------------------------------------------------
//Реализация интерфейса ILoggable:
//Запись лога всего выражения на консоль:
void ExpressionEvaluator::logToScreen() {
	string filename = "log.txt"; 
	ifstream log(filename, ios_base::in);
	char *temp = new char[50];
	log.getline(temp,50);
	cout << temp;
}
//Добавление записи лога всего выражения в файл лога:
void ExpressionEvaluator::logToFile(string filename) {
	ofstream log(filename, ios_base::app || ios::ate);
	number++;
	/*
	for (int i = 0; i<nOperands; i++) {
		log << operands[i] << " ";
		if (i = nOperands-1) {
			log << endl;
		}
	}*/
	log.close();
}
//------------------------------------------------------------------
//Деструктор, освобождение памяти
ExpressionEvaluator::~ExpressionEvaluator() {
	delete []operands;
}
