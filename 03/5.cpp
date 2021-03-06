// 5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);


int main()
{
	int num[10] = { 1,3,6,3,5,5,7,4,3,65 };
	sort(num, 0, 9);
	for (int p = 0; p <= 9; p++) cout << num[p] << endl;
    return 0;
}

void merge(int a[], int low, int mid, int high) {
	int index[20] = { 0 };
	int i = 0, j = 0;
	while (i + j != high - low + 1) {
		if (i == mid - low + 1) {
			index[i + j] = a[mid + 1 + j];
			j += 1;
			continue;
		}
		if (j == high - mid) {
			index[i + j] = a[low + i];
			i += 1;
			continue;
		}
		if (a[low + i] > a[mid + 1 + j]) {
			index[i + j] = a[mid + 1 + j];
			j += 1;
		}
		else {
			index[i + j] = a[low + i];
			i += 1;
		}
	}
	for (int k = low; k <= high; k++) a[k] = index[k - low];
}

void sort(int a[], int low, int high) {
	if (low == high) return;
	int mid = (low + high) / 2;
	sort(a, low, mid);
	sort(a, mid + 1, high);
	merge(a, low, mid, high);
}