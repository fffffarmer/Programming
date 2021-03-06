// 11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double f1(double);
double f2(double);

double(*p[2])(double) = { f1, f2 };

double sol(double (*p)(double), double a, double b);



int main()
{
	cout << sol(*p[0], 0, 2) << endl;
    return 0;
}

double f1(double x)
{
	return x * x - 1;
}

double f2(double x)
{
	return (-3) * x + 6;
}

double sol(double (*p)(double), double a, double b)
{
	double error = 1;
	double mid;
	while (error > 0.0000001)	// Set the error;
	{
		mid = (a + b) / 2;
		error = b - a;
		if (p(a) * p(mid) > 0) a = mid;
		else b = mid;
	}
	return mid;
}