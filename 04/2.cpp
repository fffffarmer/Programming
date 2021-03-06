// 2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
char *newStr(char *s, char ch);
char *strReverse(char *s);	

int main()
{
	char a[30][31];
	char ch;
	int count = 0;
	char *ns, *reverse;

	while (count < 30)
	{
		cout << "Please input the string(less than 30 letters). Input 'q' to quit." << endl;
		cin >> a[count];
		if (strcmp(a[count], "q") == 0) break;
		count++;
	}
	cout << "Please input the letter you want to delete." << endl;
	cin >> ch;
	for (int i = 0; i < count; i++)
	{	
		ns = newStr(a[i], ch);
		reverse = strReverse(ns);
		cout << "String " << i + 1 << " with " << '\'' << ch << "\' deleted: " << ns;
		cout << "\tReversed:" << reverse;
		cout << endl;
		delete reverse;	
		delete ns;
	}		

    return 0;
}

char *newStr(char *s, char ch)
{
	char *ns;
	int len = strlen(s);
	ns = new char[len + 1];
	int index = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ch) {
			ns[index] = s[i];
			index++;
		}
	}
	ns[index] = '\0';	// Set the end mark;
	return ns;
}

char *strReverse(char *s)
{
	char *reverse;
	int len = strlen(s);
	reverse = new char[len + 1];
	reverse[0] = s[0];
	for (int i = 1; s[i] != '\0'; i++) {
		if (s[i] > reverse[0]) {	
			for (int i2 = i - 1; i2 >= 0; i2--) reverse[i2 + 1] = reverse[i2];
			reverse[0] = s[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (i == j + 1) reverse[i] = s[i];	
			else {
				if (s[i] <= reverse[j] && s[i] > reverse[j + 1]) {	
					for (int k = i - 1; k >= j + 1; k--) reverse[k + 1] = reverse[k];
					reverse[j + 1] = s[i];
					break;
				}
			}
		}
	}
	reverse[len] = '\0';	// Set the end mark;
	return reverse;
}	
