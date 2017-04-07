/*
 * resource_invarient.cpp
 *
 *  Created on: 2016/08/01
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename T> class Handle {
	T*p;
public:
	Handle(T* pp) : p{pp} { cout << "Handle(T*)\n"; }
	T& operator*() { return *p; }
	~Handle() { cout << "~Handle()\n"; delete p; }
};

void f1()
{
	cout << "-- f1() --\n";

	Handle<int> h {new int{99}};
	cout << "*h: " << *h << '\n';
}

void f2()
{
	//Handle<int> h;
	// error: no matching function for call to 'Handle<int>::Handle()'
}

void f3()
{
	cout << "-- f3() --\n";

	Handle<int> h1{new int{7}};
	//Handle<int> h2{h1}; // no-warning

	cout << "*h1: " << *h1 << '\n';
	//cout << "*h2: " << *h2 << '\n';
}

template<typename T>
class Handle2 {
	T*p;
public:
	Handle2(T* pp) : p{pp} { cout << "Handle2(T*)\n"; }
	Handle2(const Handle2& a) :p{new T{*a.p}}{ cout << "Handle2(const Handle2&)\n"; }
	T& operator*() { return *p; }
	~Handle2() { cout << "~Handle2()\n"; delete p; }

};

void f4()
{
	cout << "-- f4() --\n";

	Handle2<int> h1{new int{7}};
	Handle2<int> h2{h1};

	cout << "*h1: " << *h1 << '\n';
	cout << "*h2: " << *h2 << '\n';
}


// add main

int main()
{
	f1();
	f3();
	f4();
}
