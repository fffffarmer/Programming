// 7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	bool isLeap;
	int n = 20;
	int year = 1900, month;
	int count[7] = { 0 };
	int weekday = 5;
	for (int i1 = 0; i1 <= n - 1; i1++) {
		if ((((year + i1) % 4 == 0) && (year + i1) % 100 != 0) || (year + i1) % 400 == 0) isLeap = 1;	// Judge whether the year is the leap year or not;
		else isLeap = 0;
		month = 0;
		while (month <= 11) {
			if (month == 0 && i1 == 0) {
				count[weekday] += 1;
				month += 1;
				continue;
			}
			if ((month - 1) == 0 || (month - 1) == 2 || (month - 1) == 4 || (month - 1) == 6 || (month - 1) == 7 || (month - 1) == 9 || month == 0) {
				weekday += 31;	// For month 1, 3, 5, 7, 8, 10, 12;
			}
			if ((month - 1) == 3 || (month - 1) == 5 || (month - 1) == 8 || (month - 1) == 10) {
				weekday += 30;	// For month 4, 6, 9, 11;
			}
			if ((month - 1) == 1 && isLeap) {	
				weekday += 29;
			}
			if ((month - 1) == 1 && !isLeap) {
				weekday += 28;
			}
			weekday %= 7;	// Get the index of the weekday for every 13th;
			count[weekday] += 1;
			month += 1;
		}
	}
	for (int i2 = 0; i2 <= 6; i2++) cout << count[i2] << endl;
    return 0;
}

