// 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int num, i = 1, input;
	srand(time(NULL));
	num = rand() * 100 / (RAND_MAX + 1) + 1;	// Create the random number;
	cout << num << endl;
	cout << "Guess the number I've got !! 1-100!!" << endl;
	cin >> input;
	if (input == num) cout << "right" << endl;
	else {
		while (i < 7) {	// Use while loop to control the input;
			if (input == num) {
				cout << "right" << endl;
				break;
			}
			else {
				if (input > num) cout << "too big" << endl;
				else cout << "too small" << endl;
				cin >> input;
				i++;
			}
		}
	}
	return 0;
}

