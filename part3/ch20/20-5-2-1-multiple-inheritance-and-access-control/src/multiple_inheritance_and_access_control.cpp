/*
 * multiple_inheritance_and_access_control.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct B {
	int m;
	static int sm;
};
int B::sm = 12;

class D1 : public virtual B { };
class D2 : public virtual B { };
class D12 : public D1, private D2 { };

class X1 : public B { };
class X2 : public B { };
class XX : public X1, public X2 { };

// add main

int main()
{
	D12* pd = new D12;
	B* pb = pd;
	int i1 = pd->m;

	cout << "pd: " << pd << '\n';
	cout << "pb: " << pb << '\n';
	cout << "pd->m: " << i1 << '\n';
	i1 = pd->m = 10;
	cout << "pd->m: " << i1 << '\n';

	XX* pxx = new XX;
	//int j1 = pxx->m;
		// error: request for member 'm' is ambiguous
	int j2 = pxx->sm;

	cout << "pxx->sm: " << j2 << '\n';
}

