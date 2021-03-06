// 4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void horse(int x, int y);	
const int n = 6;
int k = 1;
int counter = 0;
bool board[n][n];	
int column[n * n] = { 0 };
int row[n * n] = { 0 };
int op[8][2] = { {1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1} };	// Use array to store the possible moves;


int main()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) board[i][j] = true;
	}
	board[0][0] = false;	// Set [0][0] as the starting point
	horse(0, 0);
	cout << counter << endl;
    return 0;
}

void horse(int x, int y) {		
	for (int i = 0; i < 8; i++) {
		if (board[x + op[i][0]][y + op[i][1]] && x + op[i][0] >= 0 && x + op[i][0] <= n - 1 && y + op[i][1] >= 0 && y + op[i][1] <= n -1) {
			board[x + op[i][0]][y + op[i][1]] = false;	
			column[k] = x + op[i][0];
			row[k] = y + op[i][1];
			k += 1;
			if (k == n * n) {
				counter += 1;
				cout << "Solution " << counter << endl;
				for (int t = 0; t <= n * n - 1; t++) cout << "(" << column[t] << "," << row[t] << ")" << endl;
			}
			else horse(x + op[i][0], y + op[i][1]);
			board[x + op[i][0]][y + op[i][1]] = true;	// Reset the board;
			k -= 1;	// Reset the counting;
		}
	}
}