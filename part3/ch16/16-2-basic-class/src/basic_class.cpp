/*
 * basic_class.cpp
 *
 *  Created on: 2016/07/15
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class X {
private:
	int m;
public:
	X(int i = 0) : m{i} { }

	int mf(int i)
	{
		int old = m;
		m = i;
		return old;
	}
};

X var {7};

int user(X var, X* ptr)
{
	int x = var.mf(7);
	int y = ptr->mf(9);
	//int z = var.m;
		// error: 'int X::m' is private

	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';

	return 0;
}

// add main
int main()
{
	X local {10};

	user(local, &var);
}


