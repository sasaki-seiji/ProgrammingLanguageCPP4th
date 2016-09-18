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

	T& operator[](int i) { return v[i]; }
};


Buffer<char,128> cbuf;
Buffer<int,5000> ibuf;
Buffer<Record,8> rbuf;

void test_Buffer()
{
	cbuf[0] = 'A';
	cout << "cbuf[0]: " << cbuf[0] << '\n';
	ibuf[1000] = 100;
	cout << "ibuf[1000]: " << ibuf[1000] << '\n';
	rbuf[5].name = "sasaki";
	rbuf[5].phone = 1234567;
	cout << "rbuf[5].name: " << rbuf[5].name << '\n';
	cout << "rbuf[5].phone: " << rbuf[5].phone << '\n';
}

template<typename T, char* label>
class X {
public:
	const char* get_label() const { return label; }
	T get_default() const { return T{}; }
};

//X<int,"BWM323Ci"> x1;
	// error: '"BWM323Ci"' is not a valid template argument for type 'char*' because string literals can never be used in this context
char lx2[] = "BWM323Ci";
X<int,lx2> x2;


//constexpr int max = 200;
constexpr int sz = 200;

void f(int i)
{
	//Buffer<int,i> bx;
		// error: 'i' is not a constant expression
	//Buffer<int,max> bm;
	Buffer<int,sz> bm;

	bm[sz-1] = 123;
	cout << "bm[sz-1]: " << bm[sz-1] << '\n';
}


template<typename T, int max>
class Buffer2 {
	T v[max];
public:
	//Buffer2(int i) { max = i; }
		// error: lvalue required as left operand of assignment
};


template<typename T, T default_value>
class Vec {
public:
	T get_default() const { return default_value; }
};

int foo = 1;

Vec<int,42> c1;
//Vec<string,""> c2;
	// error: 'class std::__cxx11::basic_string<char>' is not a valid type for a template non-type parameter
Vec<int*,&foo> c2;

template<typename T, T default_value = T{}>
class Vec2 {
public:
	T get_default() const { return default_value; }
};

Vec2<int, 42> c3;
Vec2<int>	c33;
Vec2<int*,&foo>	c4;
Vec2<int*>	c44;


// add main

int main()
{
	test_Buffer();

	cout << x2.get_label() << '\n';
	cout << x2.get_default() << '\n';

	f(100);

	//Buffer2<int,10> b2(20);
		// error: lvalue required as left operand of assignment

	cout << c1.get_default() << '\n';
	cout << c2.get_default() << '\n';

	cout << c3.get_default() << '\n';
	cout << c33.get_default() << '\n';
	cout <<	c4.get_default() << '\n';
	cout << c44.get_default() << '\n';
}
