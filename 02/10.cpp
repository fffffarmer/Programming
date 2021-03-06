// 10.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
bool perfectnum(int);

int main()
{
	int m, n;
	cout << "Please input two numbers m and n with m less than n." << endl;
	cin >> m >> n;
	for (int k = m; k <= n; k++) {
		if (perfectnum(k)) cout << k << endl;
	}
    return 0;
}

bool perfectnum(int n) {
	int result = 0;
	for (int i = 1; i <= n - 1; i++) if (n % i == 0) result += i;
	if (result == n) return true;
	else return false;
}