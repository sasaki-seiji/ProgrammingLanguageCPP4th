/*
 * date_user.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct X {
	explicit X();
	explicit X(int, int);
};

//X x1 = { };
	// converting to 'X' from initializer list would use explicit constructor 'X::X()'
//X x2 = {1,2};
	// converting to 'X' from initializer list would use explicit constructor 'X::X(int, int)'

X x3 { };
X x4 {1,2};

int f(X);

//int i1 = f({});
	// converting to 'X' from initializer list would use explicit constructor 'X::X()'
//int i2 = f({1,2});
	// converting to 'X' from initializer list would use explicit constructor 'X::X(int, int)'

int i3 = f(X{});
int i4 = f(X{1,2});


// define undef func
X::X()
{
	cout  << "X::X() called\n";
}

X::X(int i, int j)
{
	cout << "X::X(" << i << ", " << j << ") called\n";
}

int f(X x)
{
	cout << "f(X) called\n";
	return 1;
}
