/*
 * static_member.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


struct Point {
	int x,y;
	constexpr Point(int xx, int yy) : x{xx}, y{yy} { }
};

template<typename T>
struct X {
	static constexpr Point p {100,200};
	static const int m1 = 7;
	//static int m2 = 8;
		// error: ISO C++ forbids in-class initialization of non-const static member 'X<T>::m2'
	static int m3;
	static void f1() { cout << "X<" << typeid(T).name() << ">::f1()\n"; }
	static void f2();
};

//template<typename T> int X<T>::m1 = 88;
	// error: duplicate initialization of 'X<T>::m1'
template<typename T> int X<T>::m3 = 99;

template<typename T> void X<T>::f2()
{
	cout << "X<" << typeid(T).name() << ">::f2()\n";
}


template<typename T>
struct Y {
	static int a;
	static int b;
};

int* p = &Y<int>::a;

// add undef

template<typename T>
int Y<T>::a = 123;

// add main

int main()
{
	cout << "X<int>::p.x: " << X<int>::p.x << '\n';
	cout << "X<int>::p.y: " << X<int>::p.y << '\n';

	cout << "X<string>::m1: " << X<string>::m1 << '\n';

	cout << "X<int>::m3: " << X<int>::m3 << '\n';
	cout << "X<string>::m3: " << X<string>::m3 << '\n';

	X<int>::m3 = 100;
	cout << "- after X<int>::m3 = 100;\n";
	cout << "X<int>::m3: " << X<int>::m3 << '\n';
	cout << "X<string>::m3: " << X<string>::m3 << '\n';

	X<int>::f1();
	X<string>::f1();

	X<int>::f2();
	X<string>::f2();

	cout << "p: " << p << ", *p: " << *p << endl;
}

