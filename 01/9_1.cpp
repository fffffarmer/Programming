// 1) 4.24242
// 2) 3.2323

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int m1 = 1, m2 = 5, m3 = 10, m4 = 20, m5 = 50;	// n1, n2, n3, n4, n5: the denomination of the money. Change them for another case;
	int money, n1, n2, n3, n4, n5, min, totalnum = 0;	// n1, n2, n3, n4, n5: the number of the notes;
	for (money = 1; money <= 99; money++) {
		min = 99;	// Initialize the minimum of the number of the notes;
		for (n5 = 0; n5 <= money / m5; n5++) {
			for (n4 = 0; n4 <= (money - m5 * n5) / m4; n4++) {
				for (n3 = 0; n3 <= (money - m5 * n5 - m4 * n4) / m3; n3++) {
					for (n2 = 0; n2 <= (money - m5 * n5 - m4 * n4 - m3 * n3) / m2; n2++) {
						n1 = money - m5 * n5 - m4 * n4 - m3 * n3 - m2 * n2;
					if (n1 + n2 + n3 + n4 + n5 < min) min = n1 + n2 + n3 + n4 + n5;	// Update the minimum;
					}
				}
			}
		}
		cout << money << " " << min << endl;
		totalnum += min;
	}
	cout << "The average " << totalnum / 99.0 << endl;	// Get the average number of notes;

    return 0;
}

