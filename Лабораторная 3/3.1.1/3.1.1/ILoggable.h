#pragma once
#include <iostream>

class ILoggable {
public:
	//Запись лога всего выражения на консоль:
	virtual void logToScreen() = 0;
	//Добавление записи лога всего выражения в файл лога:
	virtual void logToFile(std::string filename) = 0;
};

