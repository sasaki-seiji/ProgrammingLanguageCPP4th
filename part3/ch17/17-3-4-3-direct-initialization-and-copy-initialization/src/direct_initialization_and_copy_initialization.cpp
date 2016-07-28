/*
 * direct_initialization_and_copy_initialization.cpp
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

vector<vector<double>> vs = {
	{10,11,12,13},
	{10},
	//10,
		// error: could not convert '{{10, 11, 12, 13}, {10}, 10, std::vector<double>(std::initializer_list<double>{((const double*)(& ._41)), 4u}, std::allocator<double>()), std::vector<double>(std::initializer_list<double>{((const double*)(& ._42)), 1u}, std::allocator<double>()), std::vector<double>(10ull, std::allocator<double>())}' from '<brace-enclosed initializer list>' to 'std::vector<std::vector<double> >'

	vector<double>{10,11,12,13},
	vector<double>{10},
	vector<double>(10)
};

vector<double> v1(7);
//vector<double> v2 = 9;
	// error: conversion from 'int' to non-scalar type 'std::vector<double>' requested

void f(const vector<double>&);

void g()
{
	//v1 = 9;
		// error: no match for 'operator=' (operand types are 'std::vector<double>' and 'int')
	//f(9);
		// error: invalid initialization of reference of type 'const std::vector<double>&' from expression of type 'int'
}

vector<double> v12 {7};
vector<double> v22 = {9};

void g2()
{
	v12 = {9};
	f({9});
}


vector<string> v13 {"Anya"};
vector<string> v23 = {"Courtney"};

void f(const vector<string>&);

void g3()
{
	v13 = {"Gavin"};
	f({"Norah"});
}

// add utilities

void print(const vector<vector<double>>& vv)
{
	for (auto& x : vv) {
		for (auto &y : x)
			cout << y << ' ';
		cout << '\n';
	}
}

template<typename T>
void print(const vector<T>& v)
{
	for (auto x : v)
		cout << x << ' ';
	cout << '\n';
}

// add undef func

void f(const vector<double>& v)
{
	cout << "f(const vector<double>&:\n";
	print(v);
	cout << ")\n";
}


void f(const vector<string>& v)
{
	cout << "f(const vector<string>&:\n";
	print(v);
	cout << ")\n";
}


// add main

int main()
{
	cout << "- print(vs)\n";
	print(vs);

	cout << "- print(v1)\n";
	print(v1);

	cout << "- print(v12)\n";
	print(v12);

	cout << "-print(v22)\n";
	print(v22);

	cout << "- calling g2()\n";
	g2();

	cout << "- after g2() called, print(v12)\n";
	print(v12);

	cout << "- print(v13)\n";
	print(v13);

	cout << "- print(v23)\n";
	print(v23);

	cout << "- calling g3()\n";
	g3();

	cout << "- after g3(), print(v13)\n";
	print(v13);
}
