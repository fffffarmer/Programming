// 15.cpp: 定义控制台应用程序的入口点。
// 1) 9.0min
// 2) 7.6min


#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
	int c1, c2;
	double time1 = 0, time2 = 0;
	int total;
	int ran;
	int count;
	int n = 10000;	// How many times will you simulate?
	int index[10];
	int cus[10] = { 1,1,1,1,1,1,1,1,1,5 };

	for (int k = 0; k <= 9; k++) index[k] = -1;
	
	srand(unsigned(time(NULL)));

	for (int i = 1; i <= n; i++) {	// Do n sumilation for n times;
		// Create the random sequence;
		for (int m = 0; m <= 9; m++) index[m] = -1;	
		count = 0;
		while (index[0] == -1 || index[1] == -1 || index[2] == -1 || index[3] == -1 || index[4] == -1 || index[5] == -1 || index[6] == -1 ||
			index[7] == -1 || index[8] == -1 || index[9] == -1) {
			ran = rand() % 10;
			if (index[ran] == -1) {
				index[ran] = count;
				count += 1;
			}
		}

		// Solution 1;
		c1 = c2 = 0;
		total = 0;
		for (int p = 0; p <= 9; p++) {	
			if (p <= 4) c1 += cus[index[p]];
			total += cus[index[p]];
		}
		c2 = total - c1;
		time1 += c1 > c2 ? c1 : c2;

		// Solution 2;
		c1 = c2 = 0;
		for (int q = 0; q <= 9; q++) {	
			if (c1 <= c2) {
				time2 += c1;
				c2 -= c1;
				c1 = 0;
			}
			else {
				time2 += c2;
				c1 -= c2;
				c2 = 0;
			}
			if (c1 == 0) {
				c1 += cus[index[q]];
				continue;
			}
			if (c2 == 0) {
				c2 += cus[index[q]];
			}
		}
		time2 += c1 > c2 ? c1 : c2;
	}

	time1 = time1 / n;
	time2 = time2 / n;
	cout << time1 << endl;
	cout << time2 << endl;
    return 0;
}

 