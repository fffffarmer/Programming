//n = 1   0.367879
//n = 2   0.264241
//n = 3   0.207277
//n = 4   0.170893
//n = 5   0.145533
//n = 6   0.126802
//n = 7   0.112384
//n = 8   0.100932
//n = 9   0.0916123
//n = 10  0.0838771
//n = 11  0.0773522
//n = 12  0.0717733
//n = 13  0.0669477
//n = 14  0.0627322
//n = 15  0.0590175
//n = 16  0.0557193
//n = 17  0.0527711
//n = 18  0.0501199
//n = 19  0.0477228
//n = 20  0.0455449

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int start = 50, k, end;	// Choose to start the simulation with n = 50;
	double i = 1 / 51;	// Use the approximate value for easier calculation;
	for (end = 1; end <= 20; end++) {	// Calculate all the values with n <= 20;
		for (k = start; k >= end; k--) {	// Use the recursion expression with n downward for smaller error;
			i = (1 - i) / (k + 1);	//
		}
		cout << "n = " << end << "\t" << i << endl;
	}

    return 0;
}

