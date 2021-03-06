// 8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void getdate(int n, int *month, int *day);


int main()
{
	int month, day;
	getdate(365, &month, &day);
	cout << month << '\t' << day << endl;
    return 0;
}

void getdate(int n, int *month, int *day)
{
	int m = 1;
	while (n > 0)
	{
		n -= months[m - 1];
		m += 1;
	}
	if (n <= 0)	// Compensation;
	{
		m -= 1;
		n += months[m - 1];
	}
	*month = m;
	*day = n;
	return;
}