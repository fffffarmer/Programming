// Level 3

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cout << "Please input the scores of A and B." << endl;
	cin >> a >> b;
	if (a < 0 || b < 0)	// First, make sure that the input of scores is valid.
		cout << "Scores can't be negative numbers!!" << endl;
	else {
		if (abs (a - b) <= 1 || a < 11 && b < 11)	// Consider the case when there is no victor.
			cout << "Victory still hangs in the balance." << endl;
		else {
			if (a > b) cout << "A wins!!" << endl;	// Who get the greater score wins!
			else cout << "B wins!!" << endl;
		}
	}
	return 0;
}

