/*
 * type_as_parameter.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
#include <complex>
#include <vector>
using namespace std;

template<typename T>
void f(T);

template<typename T>
class X {
public:
	X();
};

void test()
{
	f(1);
	f<double>(1);
	X<double> x1;
	X<complex<double>> x2;
}

vector<double> x1;
vector<complex<double>> x2;


class Y {
	class M { };
public:
	void mf();
};

void g()
{
	struct S { };
	vector<S> vs;
	//vector<Y::M> vm;
		// error: 'class Y::M' is private
}

void Y::mf()
{
	//vector<S> vs;
		// error: 'S' was not declared in this scope
	vector<M> vm;
}

// add undef

template<typename T>
void f(T t)
{
	cout << "f<" << typeid(T).name() << ">(" << t << ")\n";
}

template<typename T>
X<T>::X()
{
	cout << "X<" << typeid(T).name() << ">::X()\n";
}

// add main

int main()
{
	test();
	g();
	Y y;
	y.mf();
}
