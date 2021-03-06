// 1)4.24242
// 2)4.15152

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int m1 = 1, m2 = 5, m3 = 10, m4 = 20, m5 = 50;	// m1, m2, m3, m4, m5: the denomination of the money. Change them for another case;
	int money, m, total = 0;
	int n1, n2, n3, n4, n5;	// n1, n2, n3, n4, n5: the numbers of notes;
	for (money = 1; money <= 99; money++) {
		n1 = n2 = n3 = n4 = n5 = 0;
		m = money;
		while (m >= m5) { n5++; m -= m5; }	// Try to maximize the notes of money in every step;
		while (m >= m4) { n4++; m -= m4; }
		while (m >= m3) { n3++; m -= m3; }
		while (m >= m2) { n2++; m -= m2; }
		n1 = m;
		total += n1 + n2 + n3 + n4 + n5;
		cout << money << "\t" << n1 + n2 + n3 + n4 + n5 << endl;
	}
	cout << "The average " << total / 99.0 << endl;
    return 0;
}

