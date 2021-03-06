// 14.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
T maxmin(T a[], int n) { //	n: 0 for maximum; 1 for minimum;
	if (n == 0) {
		int max = -9999;
		for (int i = 0; a[i] != 0; i++) {
			if (a[i] > max) {
				max = a[i];

			}
		}
		return max;
	}
	if (n == 1) {
		int min = 9999;
		for (int i = 0; a[i] != 0; i++) {
			if (a[i] < min) {
				min = a[i];
			}
		}
		return min;
	}	
	return 0;
}

int main()
{
	int k[20] = { 2,3,425,6,3,7,3,2,7,5 };
	char p[20] = "hello, world!";
	cout << "The maximum in k is:" << maxmin(k, 0) << endl; 
	cout << "The minimum in k is:" << maxmin(k, 1) << endl;
	cout << "The maximum in p is:" << maxmin(p, 0) << endl;
	cout << "The minimum in k is:" << maxmin(p, 1) << endl;
    return 0;
}




