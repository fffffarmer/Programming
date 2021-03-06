// 9.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int list[8] = { 2,3,2,5,7,4,8,4 };
	int n;
	cout << "Please input the number of the elements." << endl;
	cin >> n;	
	cout << endl;
	int *nlist;
	nlist = new int[n];
	nlist[0] = list[0];
	for (int i = 1; i < n; i++) {
		if (list[i] < nlist[0]) {	// When the number is the smallest one, put it in the first position;
			for (int i2 = i - 1; i2 >= 0; i2--) nlist[i2 + 1] = nlist[i2];
			nlist[0] = list[i];
			continue;
		}
		for (int j = 0; j <= i - 1; j++) {
			if (i == j + 1) nlist[i] = list[i];	// When the number is the largest one, put it in the last position;
			else {
				if (list[i] >= nlist[j] && list[i] < nlist[j + 1]) {	// When the number can be put between two numbers, leave it there;
					for (int k = i - 1; k >= j + 1; k--) nlist[k + 1] = nlist[k];
					nlist[j + 1] = list[i];
					break;
				}
			}
		}
	}
	for (int time = 0; time < n; time++) cout << nlist[time] << endl;
	delete [] nlist;
	return 0;
}