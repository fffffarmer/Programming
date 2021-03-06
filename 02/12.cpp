// 12.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int findstr(char a[], char b[]);

int main()
{
	char a[10];
	char b[10];
	cout << "Please input two strings(a and b). If b is in a, I will tell you the index where b is in a. Otherwise, you will get a '-1'." << endl;
	cin.getline(a, 10);
	cin.getline(b, 10);
	cout << findstr(a, b) << endl;
    return 0;
}

int findstr(char a[], char b[]) {
	int key;
	for (int i = 0; a[i] != '\0'; i++) {
		key = 1;
		for (int j = 0; b[j] != '\0'; j++) {
			if (a[i + j] != b[j]) key = 0;
		}		
		if (key == 1) return i;
	}
	return -1;
}
