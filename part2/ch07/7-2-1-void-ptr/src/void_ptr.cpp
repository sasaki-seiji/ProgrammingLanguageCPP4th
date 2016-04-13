/*
 * void_ptr.cpp
 *
 *  Created on: 2016/04/13
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(int* pi)
{
	void* pv = pi;
	//*pv;
		// 'void*' is not a pointer-to-object type
	++pv;
		// ISO C++ forbids incrementing a pointer of type 'void*' [-Wpointer-arith]

	int* pi2 = static_cast<int*>(pv);

	//double* pd1 = pv;
		// 	invalid conversion from 'void*' to 'double*' [-fpermissive]

	//double* pd2 = pi;
		// cannot convert 'int*' to 'double*' in initialization

	double* pd3 = static_cast<double*>(pv);

	cout << "*pi2 = " << *pi2 << '\n';
	cout << "*pd2 = " << *pd3 << '\n';
}

int main()
{
	int i = 10;
	f(&i);
}
