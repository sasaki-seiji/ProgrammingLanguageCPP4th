/*
 * default_constructor.cpp
 *
 *  Created on: 2016/07/26
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
	Vector();
};

Vector v1;
Vector v2 {};

class String {
public:
	String(const char* p = "");
};

String s1;
String s2 {};

void f()
{
	int a0;
	int a1();

	int a {};
	double d {};
	char* p {};

	int* p1 = new int;
	int* p2 = new int{};

	cout << "a0: " << a0 << '\n';
		// 'a0' is used uninitialized in this function [-Wuninitialized]
	cout << "a: " << a << '\n';
	cout << "d: " << d << '\n';
	cout << "static_cast<void*>(p): " << static_cast<void*>(p) << '\n';
	cout << "*p1: " << *p1 << '\n';
	cout << "*p2: " << *p2 << '\n';
}

template<typename T>
struct Handle {
	T* p;
	Handle(T* pp = new T{}) : p{pp}
	{ cout << "Handle::Handle(): *p: " << *p << '\n'; }
};

Handle<int> px;

struct S1 { S1(); };
struct S2 {
	S2(string);
};

void g()
{
	cout << "- S1 a1[10]\n";
	S1 a1[10];
	//S2 a2[10];
		// error: no matching function for call to 'S2::S2()'
	//S2 a3[] { "alpha", "beta" };
		// error: conversion from 'const char [6]' to non-scalar type 'S2' requested
	cout << "- S2 a3[] { string(\"alpha\"), string(\"beta\") }\n";
	S2 a3[] { string("alpha"), string("beta") };

	cout << "vector<S1> v12(10)\n";
	vector<S1> v12(10);
	//vector<S2> v2(10);
		// no matching function for call to 'S2::S2()'

	//vector<S2> v3 { "alpha", "beta" };
		// no matching function for call to 'S2::S2(const char&)'
	cout << "vector<S2> v3 { string(\"alpha\"), string(\"beta\") }\n";
	vector<S2> v3 { string("alpha"), string("beta") };


	//vector<S2> v22(10, "");
		// error: no matching function for call to 'std::vector<S2>::vector(int, const char [1])'
	cout << "vector<S2> v22(10, string(\"\"))\n";
	vector<S2> v22(10, string(""));
	vector<S2> v4;
}

// add undef func

Vector::Vector()
{
	cout << "Vector::Vector()\n";
}

String::String(const char* p)
{
	cout << "String::String(\"" << p << "\")\n";
}

S1::S1()
{
	cout << "S1::S1()\n";
}

S2::S2(string s)
{
	cout << "S2::S2(" << s << ")\n";
}

// add main

int main()
{
	f();
	cout << "*px.p: " << *px.p << '\n';
	g();
}
