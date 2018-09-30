// 3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int i, k;
	int times;
	int score;
	double rate;
	int n[11] = { 0 };

	srand(time(NULL));

	cout << "How many times would you like to simulate?" << endl;
	cin >> times;

	for (i = 1; i <= times; i++) {
		score = 0;
		for (k = 1; k <= 10; k++) {
			rate = rand() / double(RAND_MAX + 1);	// Create the random number;
			if (rate < 0.5) score += 10;
			else score += 5;
		}
		switch (score) {
		case 50:n[0] += 1;
			break;
		case 55:n[1] += 1;
			break;
		case 60:n[2] += 1;
			break;
		case 65:n[3] += 1;
			break;
		case 70:n[4] += 1;
			break;
		case 75:n[5] += 1;
			break;
		case 80:n[6] += 1;
			break;
		case 85:n[7] += 1;
			break;
		case 90:n[8] += 1;
			break;
		case 95:n[9] += 1;
			break;
		case 100:n[10] += 1;
			break;
		}
	}
	for (int t = 0; t <= 10; t++)
		cout << n[t] << endl;
    return 0;
}

