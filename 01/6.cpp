// T6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	double result, ave;
	int u = 0, d = 0, l = 0, r = 0;
	srand(unsigned(time(NULL)));
	for (n = 0; n <= 1000; n += 10) {	// Set the data range. 
		m =  n + 1000;
		result = 0;
		for (int i = 1; i <= m; i++) {	// Do m times simulation. 
			u = 0;
			d = 0;
			l = 0;
			r = 0;
			for (int j = 1; j <= n; j++) {	// Calculate the distance for each time.
				switch (rand() % 4) {
				case 0: u += 1;
					break;
				case 1: d += 1;
					break;
				case 2: l += 1;
					break;
				case 3: r += 1;
					break;
				}
			}
			result += sqrt(u * u + d * d + l * l + r * r);
		}
		ave = result / m;
		cout << ave << endl;
	}
    return 0;
}

