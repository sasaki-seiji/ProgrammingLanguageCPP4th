/*
 * scoped_allocator_adaptor.cpp
 *
 *  Created on: 2016/12/11
 *      Author: sasaki
 */


#include "allocator.h"
#include <scoped_allocator>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

constexpr int sz {100000};
Arena my_arena1{new char[sz], sz};

template<typename T, typename A>
ostream& operator<<(ostream& os, const vector<T,A>& v)
{
	for (auto& x : v)
		os << x << ", ";
	return os;
}

int main()
{
	cout << "-- use default allocator --\n";
	using Svec0 = vector<string>;
	Svec0 v0;
	v0.push_back("str#1");
	v0.push_back("str#2");
	cout << "v0: " << v0 << endl;
	v0.assign({});
	cout << "v0: " << v0 << endl;

	cout << "-- vector uses My_alloc, string uses default allocator --\n";
	using Svec1 = vector<string,My_alloc<string>>;
	Svec1 v1 {My_alloc<string>{my_arena1}};
	v1.push_back("str#1");
	v1.push_back("str#2");
	cout << "v1: " << v1 << endl;
	v1.assign({});
	cout << "v1: " << v1 << endl;

	cout << "-- vector and string use single My_alloc --\n";
	using Xstring = basic_string<char,char_traits<char>,My_alloc<char>>;
	using Alloc2 = scoped_allocator_adaptor<My_alloc<Xstring>>;
	using Svec2 = vector<Xstring,Alloc2>;
	scoped_allocator_adaptor<My_alloc<Xstring>> alloc2{my_arena1};
	Svec2 v2 {alloc2};
	v2.push_back("str#1");
	v2.push_back("str#2");
	cout << "v2: " << v2 << endl;
	v2.assign({});
	cout << "v2: " << v2 << endl;

	cout << "-- vector uses a My_alloc, string uses another My_alloc --\n";
	using Xstring = basic_string<char,char_traits<char>,My_alloc<char>>;
	using Alloc3 = scoped_allocator_adaptor<My_alloc<Xstring>, My_alloc<char>>;
	using Svec3 = vector<Xstring,Alloc3>;
	Svec3 v3 {Alloc3{my_arena1,my_arena1}};
	v3.push_back("str#1");
	v3.push_back("str#2");
	cout << "v3: " << v3 << endl;
	v3.assign({});
	cout << "v3: " << v3 << endl;
}


