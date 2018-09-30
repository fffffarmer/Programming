// 11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int fib(void);


int main()
{
	for (int n = 0; n <= 10; n++) cout << fib() << endl;	// Run the fib() for n times and output the result for each time.
    return 0;
}

int fib(void) {
	static int a = 0, b = 1, c;	// Use static variable to keep the value;
	c = a + b;
	a = b;
	b = c;
	return a;
}

