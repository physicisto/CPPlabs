#pragma once
#include <iostream>

class ILoggable {
public:
	//������ ���� ����� ��������� �� �������:
	virtual void logToScreen() = 0;
	//���������� ������ ���� ����� ��������� � ���� ����:
	virtual void logToFile(std::string filename) = 0;
};

