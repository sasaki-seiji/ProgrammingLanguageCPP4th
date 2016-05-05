/*
 * inline_funiction.cpp
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

inline int fac(int n)
{
	return (n<2) ? 1 : n*fac(n-1);
}

int main()
{
	cout << "fac(6) -> " << fac(6) << '\n';
}

