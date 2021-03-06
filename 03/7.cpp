// 7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void max1max2(int a[], int n, int *max1_ptr, int *max2_ptr);


int main()
{
	int l[10] = { 1,3,3,2,7,4,9,5,6,66 };
	int n = 10;
	int max1;
	int max2;
	max1max2(l, n, &max1, &max2);
	cout << max1 << '\t' << max2 << endl;
    return 0;
}

void max1max2(int a[], int n, int *max1_ptr, int *max2_ptr)
{
	int   max2a, max1a, max2b, max1b;
	switch (n)
	{
	case 1: *max1_ptr = *max2_ptr = a[0]; return;
	case 2:  if (a[0] < a[1])
	{
		*max1_ptr = a[0]; 
		*max2_ptr = a[1];
	}
			 else { *max1_ptr = a[1];  *max2_ptr = a[0]; }
			 return;
	default: max1max2(a, n / 2, &max2a, &max1a);	// Find the largerst and second largest number for both two parts;
		max1max2(a + n / 2, n - n / 2, &max2b, &max1b);	
		if (max1a < max1b)
		{
			*max2_ptr = max1b;	
			if (max1a < max2b) *max1_ptr = max2b;
			else *max1_ptr = max1a;
		}
		else
		{
			*max2_ptr = max1a;
			if (max1b < max2a) *max1_ptr = max2a;
			else *max1_ptr = max1b;
		}
		return;
	}
}
