#include <cstdio>
#include <iostream> // необходимо для system("pause")
#include <cstring>
using namespace std;


int MYstrcmp(const char* s1, const char* s2) {
	for (int i = 0; i < strlen(s1) || i < strlen(s2); i++) {
		if (*(s1 + i) == *(s2 + i))
			continue;
		else if (*(s1 + i) > *(s2 + i))
			return 1;
		else
			return -1;
	}
	return 0;

}

void main() {
	char* s1 = "AaabbC";
	char* s2 = "AaabzC";
	printf("%d  %d  %d\n", strcmp(s1, s2), strcmp(s2, s1), strcmp(s1, s1));
	printf("%d  %d  %d\n", MYstrcmp(s1,s2), MYstrcmp(s2, s1), MYstrcmp(s1, s1));
	system("pause");
}