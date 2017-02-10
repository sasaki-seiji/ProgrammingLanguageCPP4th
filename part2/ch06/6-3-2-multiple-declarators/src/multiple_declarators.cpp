/*
 * multiple_declarators.cpp
 *
 *  Created on: 2017/02/10
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

//int x, y;

int* p, y;
int x, *q;
int v[10], *pv;

int main()
{
	cout << "typeid(p) = " << typeid(p).name() << endl;
	cout << "typeid(y) = " << typeid(y).name() << endl;
	cout << "typeid(x) = " << typeid(x).name() << endl;
	cout << "typeid(q) = " << typeid(q).name() << endl;
	cout << "typeid(v) = " << typeid(v).name() << endl;
	cout << "typeid(pv) = " << typeid(pv).name() << endl;
}

