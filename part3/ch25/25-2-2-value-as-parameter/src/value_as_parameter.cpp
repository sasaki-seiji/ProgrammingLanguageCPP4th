/*
 * value_as_parameter.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

struct Record {
	string name;
	int	phone;
};

template<typename T, int max>
class Buffer {
	T v[max];
public:
	Buffer() { }
};


Buffer<char,128> cbuf;
Buffer<int,5000> ibuf;
Buffer<Record,8> rbuf;

void test_Buffer()
{
	cout << "-- test_Buffer() --\n";

	cout << "sizeof(Buffer<char,128>): " << sizeof(cbuf) << endl;
	cout << "sizeof(Buffer<int,5000>): " << sizeof(ibuf) << endl;
	cout << "sizeof(Buffer<Record,8>): " << sizeof(rbuf) << endl;
}

template<typename T, char* label>
class X {
public:
	static constexpr const char* s_label = label;
};

//X<int,"BWM323Ci"> x1;
	// error: '"BWM323Ci"' is not a valid template argument for type 'char*' because string literals can never be used in this context
char lx2[] = "BWM323Ci";
X<int,lx2> x2;

void test_X()
{
	cout << "-- test_X() --\n";
	cout << "x2.s_label: " << x2.s_label << endl;
}

constexpr int max = 200;

void f(int i)
{
	cout << "-- f(int: " << i << ") --\n";

	//Buffer<int,i> bx;
		// error: 'i' is not a constant expression
	Buffer<int,::max> bm;

	cout << "sizeof(Buffer<int, ::max>): " << sizeof(bm) << endl;
}


template<typename T, int max>
class Buffer2 {
	T v[max];
public:
	//Buffer2(int i) { max = i; }
		// error: lvalue required as left operand of assignment
};
//Buffer2<int,100> temp(1000);

template<typename T, T default_value>
class Vec {
public:
	static constexpr T def = default_value;
};

int foo = 1;

Vec<int,42> c1;
//Vec<string,""> c2;
	// error: 'class std::__cxx11::basic_string<char>' is not a valid type for a template non-type parameter
Vec<int*,&foo> c2;

template<typename T, T default_value = T{}>
class Vec2 {
public:
	static constexpr T def = default_value;
};

Vec2<int, 42> d11;
Vec2<int>	d12;
Vec2<int*,&foo>	d21;
Vec2<int*>	d22;

void test_Vec()
{
	cout << "-- test_Vec() --\n";

	cout << "Vec<int,42> c1; c1.def: " << c1.def << endl;
	cout << "Vec<int*,&foo> c2; c2.def: " << c2.def << endl;

	cout << "Vec2<int,42> d11; d11.def: " << d11.def << endl;
	cout << "Vec2<int>	d12; d12.def: " << d12.def << endl;
	cout << "Vec2<int*,&foo> d21; d21.def: " << d21.def << endl;
	cout << "Vec2<int*>	d22; d22.def: " << d22.def << endl;
}

// add main

int main()
{
	test_Buffer();
	test_X();
	f(100);
	test_Vec();
}
