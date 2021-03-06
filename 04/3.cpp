// 3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct complexN
{
	int r;
	int i;
};

complexN add(complexN a, complexN b);
complexN mul(complexN a, complexN b);
complexN input(void);
void output(complexN a);

int main()
{
	complexN a, b;
	cout << "Set a:" << endl;
	a = input();
	cout << "Set b:" << endl;
	b = input();
	cout << "a + b = ";
	output(add(a, b));
	cout << endl;
	cout << "a * b = ";
	output(mul(a, b));
    return 0;
}

complexN add(complexN a, complexN b)
{
	complexN c;
	c.r = a.r + b.r;
	c.i = a.i + b.i;
	return c;
}

complexN mul(complexN a, complexN b)
{
	complexN c;
	c.r = a.r * b.r + a.i * b.i;
	c.i = a.r * b.i + a.i * b.r;
	return c;
}

complexN input(void)
{
	complexN a;
	int real, ima;
	cout << "Please input the real part." << endl;
	cin >> real;
	cout << "Please input the imaginary part." << endl;
	cin >> ima;
	a.r = real;
	a.i = ima;
	return a;
}

void output(complexN a)
{
	cout << a.r << " + " << a.i << "i";
}