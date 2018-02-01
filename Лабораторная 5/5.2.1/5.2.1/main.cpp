#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef	map<string, int>	Frequency;

void findWord(string filename);
bool mySort(const pair<string,int>& p1, const pair<string,int>& p2) {
	return p1.second > p2.second;
};

void main() {
	setlocale(LC_ALL, "Russian");
	string filename = "tobe.txt";
	findWord(filename);
	cout << endl << endl;
	filename = "d.txt";
	findWord(filename);
	cout << endl << endl;
	system("pause");
}


void findWord(string filename) {
	Frequency freq;
	ifstream f(filename);
	string str;
	string word;
	while (f.good()) {
		getline(f, str);
		transform(str.begin(), str.end(), str.begin(), tolower);
		// Обработка строки str
		for (int i = 0; i <= str.size(); i++) {
			if (str[i] == '!' || str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == ';' || str[i] == ':' || str[i] == '"' || i == str.size()) {
				freq[word]++;
				word.clear();
				continue;
			}
			else {
				word.push_back(str[i]);
			}
		}
	}
	vector< pair< string, int > > vec(freq.begin(), freq.end());
	//сортируем этот вектор по значению
	sort(vec.begin(), vec.end(), mySort);
	cout << "In file " << filename << ":" << endl;
	//вывод 
	for (auto p : vec) {
		if (p.first.size() > 3 && p.second > 4) {
			cout << p.first << ' ' << p.second << endl;
		}
	}


	f.close();
}