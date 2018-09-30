// T8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a, b, i, i0, I;
	cout << "Please input two positive integers." << endl;
	cin >> a >> b;
	for (i = a; i <= b; i++) {	// Judge every number in the closed interval [a, b] if it is Armstrong Number;
		I = i;
		i0 = 0;
		while (I % 10 > 0) {	// Add up the third power of each individual number;
			i0 += (I % 10) * (I % 10) * (I % 10);
			I = I / 10;
		}
		if (i == i0) cout << i << " is an Armstrong number." << endl;
	}
    return 0;
}

