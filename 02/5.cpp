// 5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int list[5] = { 0 };
	int num[5] = { 2, 9, 1, 4, 13};
	list[0] = num[0];
	for (int i = 1; i <= 4; i++) {			
		if (num[i] < list[0]) {	// When the number is the smallest one, put it in the first position;
			for (int i2 = i - 1; i2 >= 0; i2--) list[i2 + 1] = list[i2];
			list[0] = num[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {	
			if (i == j + 1) list[i] = num[i];	// When the number is the largest one, put it in the last position;
			else {
				if (num[i] >= list[j] && num[i] < list[j + 1]) {	// When the number can be put between two numbers, leave it there;
					for (int k = i - 1; k >= j + 1; k--) list[k + 1] = list[k];
					list[j + 1] = num[i];
					break;
				}
			}
		}
	}
	for (int time = 0; time <= 4; time++) cout << list[time] << endl;
    return 0;
}

