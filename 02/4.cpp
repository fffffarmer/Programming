// 4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int key;
	int matrix[3][3] = { 1, 3, 4 ,2, 5, 9, 4, 3, 6 };
	int maximum[3] = { 0 };
	int loc[3][3] = { 0 };
	int column;
	
	for (int i = 0; i <= 2; i++) { 
		for (int j = 0; j <= 2; j++) {
			if (matrix[i][j] > maximum[i]) {
				maximum[i] = matrix[i][j];	// Record the maximum for every row.
				loc[i][0] = i;	// Record the position of the points;
				loc[i][1] = j;
			}
		}
	}
	for (int n = 0; n <= 2; n++) {
		column = loc[n][1];
		key = 1;
		for (int row = 0; row <= 2; row++) {	
			if (matrix[row][column] < maximum[n]) key = 0;
		}
		if (key == 0) loc[n][2] = -1;	// Mark out the points that are not the minimum of the column;
	}
	for (int time = 0; time <= 2; time++) {
		if (loc[time][2] != -1) cout << loc[time][0] << " " << loc[time][1] << endl;
	}
    return 0;
}

