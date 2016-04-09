/*
 * array.cpp
 *
 *  Created on: 2016/03/19
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void copy_fct()
{
	// 2016.03.19 add
	cout << "copy_fct():" << endl;

	int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int v2[10];

	for( auto i = 0; i != 10; ++i ) {
		v2[i] = v1[i];
	}
}

void print()
{
	// 2016.03.19 add
	cout << "print():" << endl;
	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for( auto x : v )
		cout << x << '\n';

	for( auto x : {10, 21, 43, 43, 54, 65} )
		cout << x << '\n';
}

void increment()
{
	// 2016.03.19 add
	cout << "incremnt()" << endl;

	int v[] = {0,1,2,3,4,5,6,7,8,9};

	for( auto& x : v )
		++x;

	// 2016.03.19 add
	for( auto x : v )
		cout << x << endl;
}

int count_x(char* p, char x)
{
	if( p == nullptr ) return 0;
	int count = 0 ;
	for( ; *p != 0; ++p ) {
		if( *p == x ) {
			++count ;
		}
	}
	return count ;
}

int main()
{
	copy_fct();
	print();
	increment();
	int count = count_x("abcabc", 'c');
	cout << "count_x(\"abcabc\", 'c') returns " << count << endl;
	count = count_x(nullptr, 'c');
	cout << "count_x(nullptr, 'c') returns " << count << endl;
}
