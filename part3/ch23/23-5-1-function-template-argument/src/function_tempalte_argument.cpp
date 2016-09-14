/*
 * function_tempalte_argument.cpp
 *
 *  Created on: 2016/09/14
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <utility>
#include <typeinfo>
#include <vector>
using namespace std;

// Buffer template struct

template<typename T, int max>
struct Buffer {
	T buf[max];
	int pos{0};

	void add(const T& v);
	void print(ostream&);
};

template<typename T, int max>
T& lookup(Buffer<T,max>& b, const T& v);

string& f(Buffer<string, 128>& buf, const string& v)
{
	return lookup(buf, v);
}

// add undefs

struct Buffer_overflow { };
struct Not_found { };

template<typename T, int max>
void Buffer<T,max>::add(const T& v)
{
	if (pos < max)
		buf[pos++] = v;
	else
		throw Buffer_overflow{};
}

template<typename T, int max>
void Buffer<T,max>::print(ostream& os)
{
	for (int i=0; i<pos; ++i)
		os << buf[i] << ' ';
	os << '\n';
}

template<typename T, int max>
T& lookup(Buffer<T,max>& b, const T& v)
{
	for (int i=0; i<b.pos; ++i)
		if (b.buf[i]==v)
			return b.buf[i];
	throw Not_found{};
}

// make_pair template function

template<typename T1, typename T2>
pair<T1,T2> my_make_pair(T1 a, T2 b)
{
	return {a,b};
}

auto x = my_make_pair(1,2);
auto y = my_make_pair(string("New York"), 7.7);


// create template function

template<typename T>
T* create();

void f()
{
	vector<int> v;
	int* p = create<int>();
	//int* q = create();
		// error: no matching function for call to 'create()'

	cout << "*p: " << *p << '\n';
}

// add undef

template<typename T>
T* create()
{
	return new T{};
}

// add main

int main()
{
	Buffer<string, 128> buf;
	buf.add("this");
	buf.add("is");
	buf.add("a");
	buf.add("dog");

	buf.print(cout);
	f(buf, "this") = "that";
	buf.print(cout);

	cout << "x: " << typeid(x).name() << '\n';
	cout << "y: " << typeid(y).name() << '\n';

	f();
}
