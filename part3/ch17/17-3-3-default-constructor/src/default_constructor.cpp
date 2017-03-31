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

Vector::Vector()
{
	cout << "Vector::Vector()\n";
}

Vector v1;
Vector v2 {};

class String {
public:
	String(const char* p = "");
};

String::String(const char* p)
{
	cout << "String::String(\"" << p << "\")\n";
}

String s1;
String s2 {};

void f()
{
	cout << "-- f() --\n";

	int a0;
	int a1();

	int a {};
	double d {};
	char* p {};

	int* p1 = new int;
	int* p2 = new int{};

	cout << "a0 = " << a0 << '\n';
		// 'a0' is used uninitialized in this function [-Wuninitialized]
	cout << "a = " << a << '\n';
	cout << "d = " << d << '\n';
	cout << "static_cast<void*>(p) = " << static_cast<void*>(p) << '\n';
	cout << "*p1 = " << *p1 << '\n';
	cout << "*p2 = " << *p2 << '\n';
}

template<typename T>
struct Handle {
	T* p;
	Handle(T* pp = new T{}) : p{pp}
	{ cout << "Handle::Handle(): *p: " << *p << '\n'; }
};

Handle<int> px;

int glob {9};

struct X {
	const int a1 {7};
	//const int a2;
		// error: uninitialized const member in 'struct X'
	const int& r {9};
	int& r1 {glob};
	//int& r2;
		// error: uninitialized reference member in 'struct X'
};

X x;


struct S1 { S1(); };
struct S2 { S2(string); };

S1::S1()
{
	cout << "S1::S1()\n";
}

S2::S2(string s)
{
	cout << "S2::S2(\"" << s << "\")\n";
}


void g()
{
	cout << "-- g() --\n";

	cout << "- S1 a1[10] -\n";
	S1 a1[10];
	//S2 a2[10];
		// error: no matching function for call to 'S2::S2()'
	//S2 a3[] { "alpha", "beta" };
		// error: conversion from 'const char [6]' to non-scalar type 'S2' requested
	cout << "- S2 a3[] { string(\"alpha\"), string(\"beta\") } -\n";
	S2 a3[] { string("alpha"), string("beta") };

	cout << "- vector<S1> v1(10) -\n";
	vector<S1> v1(10);
	//vector<S2> v2(10);
		// no matching function for call to 'S2::S2()'

	//vector<S2> v3 { "alpha", "beta" };
		// error: no matching function for call to 'S2::S2(const char&)'
	cout << "- vector<S2> v32 { string(\"alpha\"), string(\"beta\") } -\n";
	vector<S2> v32 { string("alpha"), string("beta") };


	//vector<S2> v4(10, "");
		// error: no matching function for call to 'std::vector<S2>::vector(int, const char [1])'
	cout << "- vector<S2> v42(10, string(\"\")) -\n";
	vector<S2> v42(10, string(""));

	cout << "- vector<S2> v5 -\n";
	vector<S2> v5;
}

struct S3 { S3(const char*); };

S3::S3(const char* p)
{
	cout << "S3::S3(\"" << p << "\")\n";
}

void h()
{
	cout << "-- h() --\n";

	cout << "- S3 a3[] { \"alpha\", \"beta\" } -\n";
	S3 a3[] { "alpha", "beta" };

	cout << "- vector<S3> v3 { \"alpha\", \"beta\" } -\n";
	vector<S3> v3 { "alpha", "beta" };

	cout << "- vector<S3> v4(10, \"\") -\n";
	vector<S3> v4(10, "");

	cout << "- vector<S3> v5 -\n";
	vector<S3> v5;
}

// add main

int main()
{
	f();

	cout << "*px.p: " << *px.p << '\n';

	cout << "-- glocal struct X --\n";

	cout << "const int x.a1 {7} = " << x.a1 << '\n';
	cout << "const int & x.r {9} = " << x.r << '\n';
	cout << "int & x.r1 {glob} = " << x.r1 << '\n';

	cout << "-- local struct X --\n";
	X y;
	cout << "const int y.a1 {7} = " << y.a1 << '\n';
	cout << "const int& y.r {9} = " << y.r << '\n';
	cout << "int& y.r1 {glob} = " << y.r1 << '\n';

	g();

	h();
}
