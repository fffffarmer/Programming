// T4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int m, d, y, dayNum, isLeap, isValid, m31, m30, m2;
	cout << "Please input three positive integers which represent month, day, year respectively." << endl;
	cin >> m >> d >> y;
	isLeap = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;	// Is this year the leap year?
	m31 = (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31;	// Does this month have 31 days?
	m30 = (m == 4 || m == 6 || m == 9 || m == 11) && d <= 30;	// Does this month have only 30 days？
	m2 = m == 2 && ((isLeap && d <= 29) || (!isLeap && d <= 28));	// Is this month the special February?
	isValid = (m <= 12) && (m31 || m30 || m2);	// Judge if the date is valid.
	if (!isValid) cout << "The date is not valid." << endl;
	else {
		dayNum = 31 * (m - 1) + d;
		if (m >= 3) dayNum -= (4 * m + 23) / 10;
		if (isLeap && m >= 3) dayNum += 1;
		cout << "This is day " << dayNum << "." << endl;
	}

    return 0;
}

