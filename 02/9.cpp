// 9.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;


int main()
{	
	const int o1 = '+';
	const int o2 = '-';
	const int o3 = '*';
	const int o4 = '/';
	char input[20];
	char op;
	char e = input[0];
	int end;	// Record the last index of the string;
	int index;	// Record the index where the operator locates;
	int n1 = 0, n2 = 0;
	int result;
	cout << "Please input a math expression so that I can help you calculate it." << endl;
	cin.getline(input, 20);
	for (int i = 0; input[i] != e; i++) {
		if (input[i] == o1 || input[i] == o2 || input[i] == o3 || input[i] == o4) { 
			index = i;
			op = input[i];
		}	
		end = i - 1;
	}
	// Calculate the two numbers;
	for (int j = 0; j <= index - 1; j++) n1 += (input[j] - '0') * pow(10, index - j - 1);
	for (int k = index + 1; k <= end;  k++) n2 += (input[k] - '0') * pow(10, end - k);

	switch (op) {	// Do different operation in different cases;
	case o1:result = n1 + n2; break;
	case o2:result = n1 - n2; break;
	case o3:result = n1 * n2; break;
	case o4:result = n1 / n2; break;
	}
	cout << result << endl;
    return 0;
}

