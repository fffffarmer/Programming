// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int bSearch(int a[], int n, int start, int end);

int main()
{
	int a[10] = { 1,3,6,7,8,12,16,17,19,20 };
	cout << bSearch(a, 19, 0, 9) << endl;
    return 0;
}

int bSearch(int a[], int n, int start, int end) {
	int mid;
	if (start == end) return start;
	mid = (start + end) / 2;
	if (n < a[mid]) return bSearch(a, n, start, mid - 1);
	else {
		if (n == a[mid]) return mid;
		else {
			return bSearch(a, n, mid + 1, end);
		}
	}
}
