/*
 * num_get.cpp
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */


#include "Double.h"
#include "My_punct.h"
using namespace std;

void f()
{
	cout << "style A: ";
	int i1;
	Double d1;
	cin >> i1 >> d1;
	cout << "i1: " << i1 << ", d1: " << d1 << endl;

	locale loc(locale::classic(), new My_punct);
	cin.imbue(loc);
	cout << "style B: ";
	int i2;
	Double d2;
	cin >> i2 >> d2;
	cout << "i2: " << i2 << ", d2: " << d2 << endl;
}

int main()
{
	f();
}

