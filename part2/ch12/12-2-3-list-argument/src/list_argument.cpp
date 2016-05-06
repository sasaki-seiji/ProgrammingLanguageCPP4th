/*
 * list_argument.cpp
 *
 *  Created on: 2016/05/07
 *      Author: sasaki
 */

#include <initializer_list>
#include <iostream>
using namespace std;

template<typename T>
void f1(initializer_list<T> v)
{
	cout << "f1(";
	for (auto& x : v)
		cout << x << ",";
	cout << ")\n";
}

struct S {
	int a;
	string s;
};
void f2(S s)
{
	cout << "f2(" << s.a << ", " << s.s << ")\n";
}

template<typename T, int N>
//void f3(T (&r)[N]);
void f3(const T (&r)[N]) { cout << "f3()\n"; }

void f4(int i)
{
	cout << "f4(" << i << ")\n";
}

void g()
{
	f1({1,2,3,4});
	f2({1,"MKS"});
	//f3({1,2,3,4});
		// invalid initialization of non-const reference of type 'int (&)[4]' from an rvalue of type 'int [4]'
		// Invalid arguments 'Candidates are: void f3(const #0 (&)[3 #1 0])	'

	f4({1});
}

template<typename T>
void f(initializer_list<T>) { cout << "f(initializer_list<T>)\n"; }

void f(S) { cout << "f(S)\n"; }

template<typename T, int N>
void f(const T (&r)[N]) { cout << "f(const T(&r)[N]\n"; }

void f(int) { cout << "f(int)\n"; }

void g2()
{
	f({1,2,3,4});
	f({1,"MKS"});
	f({1});
}


int main()
{
	g();
	g2();
}
