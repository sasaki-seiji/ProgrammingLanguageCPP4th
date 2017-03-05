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
	cout << "f1(initializer_list<T>{";
	for (auto& x : v)
		cout << x << ",";
	cout << "})\n";
}

struct S {
	int a;
	string s;
};
void f2(S s)
{
	cout << "f2(S{" << s.a << ", \"" << s.s << "\"})\n";
}

template<typename T, int N>
//void f3(T (&r)[N])
void f3(const T (&r)[N])
{
	cout << "f3(const T(&)[N]{";
	for (auto& x : r)
		cout << x << ",";
	cout << "})\n";
}

void f4(int i)
{
	cout << "f4(int{" << i << "})\n";
}

void g()
{
	cout << "-- g() --\n";

	f1({1,2,3,4});
	f2({1,"MKS"});
	f3({1,2,3,4});
		// error: invalid initialization of non-const reference of type 'int (&)[4]' from an rvalue of type 'int [4]'
		// MinGW g++ 5.3.0 : Invalid arguments 'Candidates are: void f3(const #0 (&)[3 #1 0])	'

	f4({1});
}

template<typename T>
void f(initializer_list<T> v)
{
	cout << "f(initializer_list<T>{";
	for (auto& x : v)
		cout << x << ",";
	cout << "})\n";
}

void f(S s)
{
	cout << "f(S{" << s.a << ", \"" << s.s << "\"})\n";
}

template<typename T, int N>
void f(const T (&r)[N])
{
	cout << "f(const T(&)[N]{";
	for (auto& x : r)
		cout << x << ",";
	cout << "})\n";
}

void f(int i)
{
	cout << "f(int{" << i << "})\n";
}

void g2()
{
	cout << "-- g2() --\n";

	f({1,2,3,4});
	f({1,"MKS"});
	f({1});
}


int main()
{
	g();
	g2();
}
