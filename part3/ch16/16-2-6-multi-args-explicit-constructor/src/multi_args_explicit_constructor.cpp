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

// copy initialization
//X x1 = { };
	// error: converting to 'X' from initializer list would use explicit constructor 'X::X()'
//X x2 = {1,2};
	// error: converting to 'X' from initializer list would use explicit constructor 'X::X(int, int)'

X x3 { };	// direct initialization
X x4 {1,2};	// direct initialization

int f(X);

//int i1 = f({});
	// error: converting to 'X' from initializer list would use explicit constructor 'X::X()'
//int i2 = f({3,4});
	// error: converting to 'X' from initializer list would use explicit constructor 'X::X(int, int)'

int i3 = f(X{});
int i4 = f(X{3,4});


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

int main()
{
}
