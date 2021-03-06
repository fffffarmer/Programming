// 13.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int nset[20] = { 0 };	// The empty set to store the new set;
int union_set[20] = { 0 };	// The empty set to store the union;
int inter_set[20] = { 0 };	// The empty set to store the intersection;
bool FindElement(int set[], int element);	
void NewSet(int set[], int nset[]);	
void AddElement(int set[], int element);
void Intersection(int seta[], int setb[], int intersec[]);
void Union(int seta[], int setb[], int uni[]);

int main()
{
	int a[20] = { 1,3,5,2,7,5,4,4,3 };
	int b[20] = { 13,513,21,1,34,25,6,1,2,4 };
	NewSet(a, nset);	
	cout << "The new set includes:" << endl;
	for (int k = 0; nset[k] != 0; k++) cout << nset[k] << '\t';
	cout << endl;
	AddElement(nset, 4);
	cout << "Let's see whether the number is added:" << endl;
	for (int p = 0; nset[p] != 0; p++) cout << nset[p] << '\t';
	cout << endl;
	Intersection(a, b, inter_set);
	cout << "The intersection of a and b includes:" << endl;
	for (int q = 0; inter_set[q] != 0; q++) cout << inter_set[q] << '\t';
	cout << endl;	
	Union(a, b, union_set);
	cout << "The union of a and b includes:" << endl;
	for (int m = 0; union_set[m] != 0; m++) cout << union_set[m] << '\t';
    return 0;
}

bool FindElement(int set[], int element) {
	int key = 0;
	for (int i = 0; set[i] != 0; i++) {
		if (set[i] == element) {
			key = 1;
			break;
		}
	}
	if (key == 1) return true;
	else return false;
}

void NewSet(int set[], int nset[]) {
	int index = 0;
	for (int i = 0; set[i] != 0; i++) {
		if (!FindElement(nset, set[i])) {
			nset[index] = set[i];
			index += 1;
		}
	}
}

void AddElement(int set[], int element) {
	if (FindElement(set, element)) return;
	else {
		int i;
		for (i = 0; set[i] != 0; i++);
		set[i] = element;
	}
}

void Union(int seta[], int setb[], int element[]) {
	int index = 0;
	for (int i = 0; seta[i] != 0; i++) {
		if (!FindElement(element, seta[i])) {
			element[index] = seta[i];
			index += 1;
		}
	}
	for (int j = 0; setb[j] != 0; j++) {
		if (!FindElement(element, setb[j])) {
			element[index] = setb[j];
			index += 1;
		}
	}
}

void Intersection(int seta[], int setb[], int element[]) {
	int un[20] = { 0 };
	int index = 0;
	for (int i = 0; seta[i] != 0; i++) {
		if (!FindElement(un, seta[i])) {
			un[index] = seta[i];
			index += 1;
		}
	}
	for (int j = 0; setb[j] != 0; j++) {
		if (!FindElement(un, setb[j])) {
			un[index] = setb[j];
			index += 1;
		}
	}

	index = 0;
	for (int i = 0; un[i] != 0; i++) {
		if (FindElement(seta, un[i]) && FindElement(setb, un[i])) {
			element[index] = un[i];
			index += 1;
		}
	}
}