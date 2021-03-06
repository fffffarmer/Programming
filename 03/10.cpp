// 10.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int set(const char *s1, char *s);
void show(const char *s);
void add(const char  *p1, const char  *p2, int index1, int index2, char *s);

int main()
{
	char num1[128], num2[128], sum[128];
	int index1 = set("32131229", num1);
	int index2 = set("2733", num2);
	show(num1);
	show(num2);
	cout << num2[127] << endl;
	add(num1, num2, index1, index2, sum);
	show(sum);

    return 0;
}

int set(const char *s1, char *s)
{
	int i = strlen(s1) - 1;
	int j = 0;
	int index = 0;
	while (i >= 0)
	{
		if ((s1[i] > '9' || s1[i] < '0') && s1[i] != '.')
		{
			cout << "set error\n";  return -1;
		}
		else 
		{ 
			if (s1[i] == '.') index = j;
			s[j] = s1[i];
			--i;
			++j;
		}
	}
	for (; j < 128; ++j) s[j] = '0';
	return index;
}

void show(const char *s)
{
	int i = 127;
	while (s[i] == '0')  --i; // Skip "0"
	while (i >= 0)
	{
		cout << s[i];
		--i;
	}
	cout << endl;
}

void add(const char  *p1, const char  *p2, int index1, int index2, char *s)
{
	int i, j = 0; // j: carry portion;
	int d = index1 > index2 ? (index1 - index2) : (index2 - index1);	// Decimal-point-aligning;
	if (index1 > index2)
	{
		for (i = 0; i < 128; ++i)
		{
			if (i + d >= 128) 
			{
				if (i + d == 128) s[i] = p2[i] + j;
				else s[i] = p2[i];
				continue;
			}
			if (p2[i] == '.')
			{
				s[i] = '.';
				continue;
			}
			s[i] = p1[i + d] - '0' + p2[i] - '0' + j;
			if (s[i] >= 10)  j = 1;
			else j = 0;
			s[i] = s[i] % 10 + '0';
		}
	}
	else
	{
		for (i = 0; i < 128; ++i)
		{
			if (i + d >= 128) 
			{
				if (i + d == 128) s[i] = p1[i] + j;
				else s[i] = p1[i];
				continue;
			}
			if (p1[i] == '.')
			{
				s[i] = '.';
				continue;
			}
			s[i] = p2[i + d] - '0' + p1[i] - '0' + j;
			if (s[i] >= 10)  j = 1; 
			else j = 0;
			s[i] = s[i] % 10 + '0';
		}
	}
}
