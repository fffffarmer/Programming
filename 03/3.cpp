// 3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void delchar(char str[], char ch);


int main()
{
	char s[50] = "Hello, aksfdiuejra!";
	delchar(s, 'a');
	for (int n = 0; s[n] != '\0'; n++) cout << s[n];
    return 0;
}

void delchar(char str[], char ch) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) {
			for (int j = i + 1; str[j] != '\0'; j++) {
				str[j - 1] = str[j];
				if (str[j + 1] == '\0') str[j] = '\0';	// Set the new end mark;
			}
		}
	}
}