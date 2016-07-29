/*
 * delegating_constuctor.cpp
 *
 *  Created on: 2016/07/29
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::stringstream;
using std::runtime_error;
using std::ostream;
using std::cout;


class Bad_X {
public:
	Bad_X(int x) { }
};

const int max = 100;

template<typename Target =string, typename Source =string>
Target to(Source arg)
{
	stringstream interpreter;
	Target result;
	if (!(interpreter << arg)
		|| !(interpreter >> result)
		|| !(interpreter >> std::ws).eof())
		throw runtime_error("to<>() failed");

	return result;
}

class X {
	int a;
	void validate(int x) { if (0 < x && x <= max) a = x; else throw Bad_X(x); }
public:
	X(int x) { validate(x); }
	X() { validate(42); }
	X(string s) { int x = to<int>(s); validate(x); }
	int get_a() const { return a; }
};

ostream& operator<<(ostream& os, X x)
{
	os << x.get_a();
	return os;
}

class X2 {
	int a;
public:
	X2(int x) { if (0 < x && x <= max) a = x; else throw Bad_X(x); }
	X2() : X2{42} { }
	X2(string s) : X2{to<int>(s)} { }
	int get_a() const { return a; }
};

ostream& operator<<(ostream& os, X2 x)
{
	os << x.get_a();
	return os;
}

class X3 {
	int a;
public:
	X3(int x) { if (0 < x && x <= max) a = x; else throw Bad_X(x); }
	//X3() : X3{42}, a{56} { }
		// error: mem-initializer for 'X3::a' follows constructor delegation
};

class X4 {
	int a;
public:
	X4(int x) { if (0 < x && x <= max) a = x; else throw Bad_X(x); }
	X4() { X4{42}; }
		// Member 'a' was not initialized in this constructor
};


// add main

int main()
{
	X x1(10);
	X x2;
	X x3("21");

	cout << "x1: " << x1 << '\n';
	cout << "x2: " << x2 << '\n';
	cout << "x3: " << x3 << '\n';

	X2 x21(10);
	X2 x22;
	X2 x23("21");

	cout << "x21: " << x21 << '\n';
	cout << "x22: " << x22 << '\n';
	cout << "x23: " << x23 << '\n';

}
