#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{	
	const double pi = 3.14159;
	double r;
	cout << "Please input the radius of the sphere." << endl;
	cin >> r;
	cout << "The surface area of the sphere is " << 4 * pi * r *r << "." << endl;
	cout << "The volumn of the sphere is " << 4.0 / 3 * pi * r *r * r << "." << endl;
    return 0;
}

