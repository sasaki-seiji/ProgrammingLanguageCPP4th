/*
 * pointer_and_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void fp(char* p)
{
	cout << "\n-- fp(" << p << ") --\n";

	while (*p)
		cout << *p++;
}

void fr(char& r)
{
	cout << "\n-- fr(" << r << ") --\n";

	while (r)
		cout << r++;
}

void fr2(char& r)
{
	cout << "\n-- fr2(" << r << ") --\n";
	char* p = &r;
	while (*p)
		cout << *p++;
}

template<typename T>
class Proxy {
	T& m;
public:
	Proxy(T& mm) :m {mm} { }
	void print() { cout << m << endl; }
};

template<typename T>
class Handle {
	T* m;
public:
	Handle(T* mm) :m{mm} { }
	void rebind(T* mm) { m = mm; }
	void print() { cout << *m << endl; }
};

struct Matrix { };

Matrix operator+(const Matrix& a, const Matrix& b) { return a; }
//Matrix operator-(const Matrix*, const Matrix*);
	// error: 'Matrix operator-(const Matrix*, const Matrix*)' must have an argument of class or enumerated type

Matrix y, z;
Matrix x = y+z;
//Matrix x2 = &y-&z;
	// error: conversion from 'long long int' to non-scalar type 'Matrix' requested

string s1 = "College Station";
string s2 = "Manhattan";

//string& a1[] = {s1, s2};
	// error: declaration of 'a1' as array of references
string* a2[] = {&s1, &s2};

//vector<string&> v1 = {s1, s2};
	// error: could not convert ‘{s1, s2}’ from ‘<brace-enclosed initializer list>’ to ‘std::vector<std::__cxx11::basic_string<char>&>’
vector<string*> v2 = {&s1, &s2};

char* ident(char* p) { return p; }
char& r { *ident(nullptr) };

int main()
{
	char s[] = { 'a', 'b', 'c', 'd', '\0' };

	fp(&s[0]);
	fr(s[0]);

	s[0] = 'a'; // fr(s[0]) changes s[0] !!!
	fr2(s[0]);

	cout << "\n-- proxy and handle --\n";

	int	x = 10, y = 20;
	Proxy<int> proxy {x};
	proxy.print();

	Handle<int> handle {&x};
	handle.print();
	handle.rebind(&y);
	handle.print();

	cout << "r = " << r << '\n';
	// MinGW windows: crash!!!
	// Ubuntu: terminated with exit value: -1
}

