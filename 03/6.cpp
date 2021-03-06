// 6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int n = 3;	// The number of items;
const int c = 10;	// The volumn of the knapsack;
int maxValue[n + 1][c + 1];
int knapsack(int volumn[], int value[]);

int main()
{
	int volumn[n] = { 1,6,7 };
	int value[n] = { 2,4,6 };
	cout << knapsack(volumn, value) << endl;
    return 0;
}

int knapsack(int volumn[], int value[]) 
{
	for (int i = 0; i <= n; i++) maxValue[i][0] = 0;
	for (int j = 0; j <= c; j++) maxValue[0][j] = 0;
	for (int p = 1; p <= n; p++) 
	{
		for (int q = 1; q <= c; q++) 
		{
			maxValue[p][q] = maxValue[p - 1][q];
			if (volumn[p - 1] <= q) maxValue[p][q] = maxValue[p][q] > (maxValue[p - 1][q - volumn[p - 1]] + value[p - 1]) ? maxValue[p][q] : (maxValue[p - 1][q - volumn[p - 1]] + value[p - 1]);
		}
	}
	return maxValue[n][c];
}