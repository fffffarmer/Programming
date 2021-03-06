// 8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	char str[81];
	char result[80];
	int e = result[0];
	cout << "Please input a string whose length is no more than 80." << endl;
	cin.getline(str, 81);
	result[0] = str[0];
	for (int i = 1; str[i] != '\0'; i++) {	// Use "insection" to fulfill the function of inversing the string;
		if (str[i] > result[0]) {
			for (int i2 = i - 1; i2 >= 0; i2--) result[i2 + 1] = result[i2];
			result[0] = str[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (i == j + 1) result[i] = str[i];
			else {
				if (str[i] == result[j]) break;
				if (str[i] < result[j] && str[i] > result[j + 1]) {
					for (int k = i - 1; k >= j + 1; k--) result[k + 1] = result[k];
					result[j + 1] = str[i];
					break;
				}
			}
		}
	}
	for (int time = 0; result[time] != e; time++) cout << result[time];
    return 0;
}

