// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void show_z(int n, char str[]);


int main()
{
	char num, str[30];
	int n;
	cout << "Please input the number of rows and the string." << endl;
	cin >> num >> str;
	n = num - '0';
	show_z(n, str);
    return 0;
}

void show_z(int n, char str[])
{
	int group = 2 * n - 2;
	int x = 0, y = 0;
	char **a;	// Set the 2-dim dynamic array;
	a = new char *[n];
	for (int i = 0; i < n; i++) a[i] = new char[30 / n];
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < 30 / n; q++)
			a[i][q] = '0';	// Initialize every element;
	}
	for (int j = 0; str[j] != '\0'; j++)
	{
		if (j % group < n - 1)
		{
			a[x][y] = str[j];
			x++;
		}
		else
		{
			a[x][y] = str[j];	
			x--;
			y++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 30 / n; j++)
		{
			if (a[i][j] != '0') cout << a[i][j];	// Output every row;
		}
	}
	for (int i = 0; i < n; i++) delete[] a[i];
	delete a;
}