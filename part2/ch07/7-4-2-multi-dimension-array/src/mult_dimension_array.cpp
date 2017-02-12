/*
 * mult_dimension_array.cpp
 *
 *  Created on: 2016/04/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

int ma[3][5];

void init_ma()
{
	for (int i = 0; i!=3; ++i)
		for (int j = 0; j!=5; ++j)
			ma[i][j] = 10*i+j;
}

void print_ma()
{
	for (int i = 0; i!=3; ++i) {
		for (int j = 0; j!=5; ++j)
			cout << ma[i][j] << '\t';
		cout << '\n';
	}
}

//int bad[3,5];
	// error: expected ']' before ',' token
	// error: expected unqualified-id before numeric constant
int good[3][5];
//int ouch = good[1,4];
	// error: invalid conversion from 'int*' to 'int' [-fpermissive]
int nice = good[1][4];

int main()
{
	init_ma();
	print_ma();
}

