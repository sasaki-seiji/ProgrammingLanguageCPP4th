/*
 * initialize_array.cpp
 *
 *  Created on: 2016/04/13
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int v1[] = { 1, 2, 3, 4 };
char v2[] = { 'a', 'b', 'c', 0 };

//char v3[2] = { 'a', 'b', 0 };
	// too many initializers for 'char [2]'

char v4[3] = { 'a', 'b', 0 };

int v5[8] = { 1, 2, 3, 4 };

//int v6[8] = v5;
	// array must be initialized with a brace-enclosed initializer

int main()
{
	int v6[8];
	//v6 = v5;
		// invalid array assignment

	cout << "sizeof(v1)/sizeof(v1[0]) = " << sizeof(v1)/sizeof(v1[0]) << '\n';
	cout << "sizeof(v2)/sizeof(v2[0]) = " << sizeof(v2)/sizeof(v2[0]) << '\n';
	cout << "sizeof(v4)/sizeof(v4[0]) = " << sizeof(v4)/sizeof(v4[0]) << '\n';
	cout << "sizeof(v5)/sizeof(v5[0]) = " << sizeof(v5)/sizeof(v5[0]) << '\n';
}

