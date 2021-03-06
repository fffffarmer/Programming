// 6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	bool key;
	bool list[2000000] = { 0 };
	list[1] = 1;
	int n = 2000000;
	for (int i = 3; i <= n; i++) {
		key = 1;
		for (int j = 0; j <= i - 2; j++) {
			if (list[j] != 0 && i % (j + 1) == 0)  key = 0;
		}
		if (key) list[i - 1] = 1;	// Mark out all the prime numbers;
	}
	for (int k = 2; k <= n; k++) {
		if (list[k - 1] != 0) cout << k << endl;
	}
	return 0;
}

