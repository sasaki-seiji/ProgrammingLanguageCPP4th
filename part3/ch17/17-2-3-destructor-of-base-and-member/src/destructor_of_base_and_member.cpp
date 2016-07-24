/*
 * destructor_of_base_and_member.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

struct S1 {
	string s;
};

S1 x;

struct X { X(int); };

struct S2 {
	X x;
};

//S2 x1;
	// error: use of deleted function 'S2::S2()'
S2 x2 {1};

// define undef-func
X::X(int i)
{
	cout << "X(" << i << ")\n";
}

// add main
int main()
{
	cout << "x.s=" << x.s << '\n';
}
