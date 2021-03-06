// 2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void selectionSort(int a[], int start, int end);


int main()
{
	int a[10] = { 23,1,6,3,7,8,5,6,2,45 };
	selectionSort(a, 0, 9);
	for (int k = 0; k <= 9; k++) cout << a[k] << endl;
    return 0;
}

void selectionSort(int a[], int start, int end) {
	if (start == end) return;
	int index;
	int min = 9999;
	for (int i = start; i <= end; i++) {
		if (a[i] < min) {
			min = a[i];
			index = i;
		}
	}
	for (int j = index - 1; j >= start; j--) {
		a[j + 1] = a[j];
	}
	a[start] = min;	// Settle down the first position;
	selectionSort(a, start + 1, end);	// Do recursion for other elements;
}
