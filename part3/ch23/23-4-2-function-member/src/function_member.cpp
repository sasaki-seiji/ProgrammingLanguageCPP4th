/*
 * member_function.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
struct X {
	void mf1() { cout << "X<" << typeid(T).name() << ">::mf1()\n"; }
	void mf2();
};

template<typename T>
void X<T>::mf2()
{
	cout << "X<" << typeid(T).name() << ">::mf2()\n";
}


// add main

int main()
{
	X<int> xi;
	xi.mf1();
	xi.mf2();

	X<string> xs;
	xs.mf1();
	xs.mf2();
}
