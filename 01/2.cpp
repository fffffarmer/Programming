// 1) 0
// 2) 1020
// 3) -168

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	double a, b = 10, c;
	a = pow(2, 80) + 1 - pow(2, 80);
	b *= 2 + 100;
	c = 123 - 0x123;
	cout << "a is equal to " << a << "." << endl;
	cout << "b is equal to " << b << "." << endl;
	cout << "c is equal to " << c << "." << endl;
    return 0;
}

