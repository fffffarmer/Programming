// 2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


int main()
{
	double pa = 0.5, pb = 0.8;
	int wa, wb;
	int game = 1000, turn;
	int i;
	double rate;
	bool over;
	const int winpoint = 21;	// Set the points to win;
	int aw = 0, al = 0, bw = 0, bl = 0;	// aw: a first, a wins; al: a first, a loses; bw: b first, b loses; bl: b first, b loses;

	srand(time(NULL));
	

	for (i = 1; i <= game; i++) {
		wa = wb = 0;
		if (game % 2 == 0) turn = 0;	// a first;
		else turn = 2;	// b first;
		over = ((wa == winpoint || wb == winpoint) && abs(wa - wb) >= 2) || ((wa > winpoint || wb > winpoint) && abs(wa - wb) == 2);
		while (!over) {
			rate = rand() / double(RAND_MAX + 1);
			if (wa >= winpoint - 1 && wb >= winpoint - 1) {
				if ((turn / 2) % 2 == 0) {	// a's turn;
					if (rate < pa) wa++;
					else wb++;
				}
				else {	//b's turn;
					if (rate < pb) wb++;
					else wa++;
				}
				turn += 1;
				over = ((wa == winpoint || wb == winpoint) && abs(wa - wb) > 2) || ((wa > winpoint || wb > winpoint) && abs(wa - wb) == 2);
				continue;
			}
			else {
				if ((turn / 2) % 2 == 0) {	// a's turn;
					if (rate < pa) wa++;
					else wb++;
				}
				else {	//b's turn;
					if (rate < pb) wb++;
					else wa++;
				}
				turn += 2;
			}
			over = ((wa == winpoint || wb == winpoint) && abs(wa - wb) > 2) || ((wa > winpoint || wb > winpoint) && abs(wa - wb) == 2);	// Refresh the situation;
		}
		if (wa > wb) cout << 0 << endl;
		else cout << 1 << endl;
		if (i % 2 == 1) {
			if (wa > wb) aw++;
			else al++;
		}
		else {
			if (wa < wb) bw++;
			else bl++;
		}
	}
	cout << aw << endl << al << endl << bw << endl << bl << endl;
    return 0;
}

