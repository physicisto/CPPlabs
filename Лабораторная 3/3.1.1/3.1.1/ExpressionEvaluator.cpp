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
//��������� �������� value ������ �������� �� ������� pos:
void ExpressionEvaluator::setOperand(int pos, double value) {
	if (pos > nOperands) {						//���� ����� �� ������� ����������� �������
		double* temp = new double[pos] {0.0};	//�� ������� ��������� ������ ����� �������� pos
		for (int i = 0; i < nOperands; i++)		//�������� ������ operands �� ��������� ������
			temp[i] = operands[i];				
		temp[pos - 1] = value;					//�� ��������� ������� ���������� ������� �������� �������� value
		nOperands = pos;						//����������� ����������� ������� nOperands ������� ���������� ��������
		delete[]operands;						//�������� memory leak
		operands = new double[nOperands];		//������� ����� ������ operands � ����� ������������ nOperands(=pos)
		for (int i = 0; i < nOperands; i++)		//�������� ��������� ������ � operands
			operands[i] = temp[i];
		delete[]temp;							//�������� memory leak
	}
	else {										//���� �� ������� �� ������� ����������� operands
		double* temp = new double[pos];			//�� ������� ��������� ������ �������� pos
		operands[pos - 1] = value;				//���������� �������� ����������� �������� value
		int count = 0 , n = nOperands;			
		for (int i = 0; i < n; i++) {			//�������� ��������� ���� � ������� operands
			count++;
			if (operands[i] == 0)
				continue;
			nOperands = count;					//����� ����������� ������� operands
		}
		for (int i = 0; i < nOperands; i++)		//�������� ������ operands �� ��������� ������ �� ������� ���������� ��������� �����
			temp[i] = operands[i];
		delete[]operands;						//������������� memory leak
		operands = new double[nOperands];		//������� ����� ������ operands � ����� ������������ nOperands
		for (int i = 0; i < nOperands; i++)		//�������� ��������� ������ � operands
			operands[i] = temp[i];
		//delete[]temp;							//����������� ������
	}
}
//��������� ����� ������ �� N ��������� �������� �������� ops:
void ExpressionEvaluator::setOperands(double ops[], int N) {
	delete[]operands;
	nOperands = N;
	operands = new double[N];
	for (int i = 0; i < N; i++)
		operands[i] = ops[i];
}
//------------------------------------------------------------------
//���������� ���������� ILoggable:
//������ ���� ����� ��������� �� �������:
void ExpressionEvaluator::logToScreen() {
	string filename = "log.txt"; 
	ifstream log(filename, ios_base::in);
	char *temp = new char[50];
	log.getline(temp,50);
	cout << temp;
}
//���������� ������ ���� ����� ��������� � ���� ����:
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
//����������, ������������ ������
ExpressionEvaluator::~ExpressionEvaluator() {
	delete []operands;
}
