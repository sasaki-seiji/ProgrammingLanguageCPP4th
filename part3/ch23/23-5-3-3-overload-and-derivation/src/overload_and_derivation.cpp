/*
 * overload_and_derivation.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
class B { int x{100}; };

template<typename T>
class D : public B<T> { int y{200}; };

template<typename T> void f(B<T>*);

void g(B<int>* pb, D<int>* pd)
{
	f(pb);
	f(pd);
}

// add undef

template<typename T> void f(B<T>* p)
{
	cout << "f(B<" << typeid(T).name() << ">*: " << p << ")\n";
}

// add main

int main()
{
	B<int> bi;
	D<int> di;
	g(&bi,&di);
}
