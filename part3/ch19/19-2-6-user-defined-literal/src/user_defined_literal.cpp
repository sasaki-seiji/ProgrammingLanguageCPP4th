/*
 * user_defined_literal.cpp
 *
 *  Created on: 2016/08/16
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

constexpr complex<double> operator"" i(long double d)
{
	return {0,d};
}

std::string operator"" s(const char* p, size_t n)
{
	cout << "operator\"\"s(const char*, " << n << ")\n";
	return std::string{p,n};
}

template<typename T> void f(const T& v)
{
	cout << "f(" << typeid(v).name() << ": " << v << ")\n";
}

void g()
{
	cout << "-- g() --\n";

	f("Hello");
	f("Hello"s);
	f("Hello\n"s);

//	auto z = 2 + 1i;
		// error: unable to find numeric literal operator 'operator""i'
//	auto z = 2 + 1.0i;
		// no match for 'operator+' (operand types are 'int' and 'std::complex<double>')
	auto z = 2.0 + 1.0i;
	cout << "z: " << z << '\n';
}

struct Bignum {
	Bignum(const char* p) { cout << "Bignum::Bignum(" << p << ")\n"; }
};

Bignum operator"" x(const char* p)
{
	return Bignum(p);
}

void f(Bignum bn)
{
	cout << "f(Bignum)\n";
}

string operator "" SS(const char* p);

//string s12 = "one two"SS;
	//error: unable to find string literal operator 'operator""SS' with 'const char [8]', 'long long unsigned int' arguments
string s13 = 13SS;



string operator "" SS(const char* p)
{
	return string{p};
}


// add main

int main()
{
	g();
	f(12345678901234567890123456789012345678901234567890x);

	string s12 = "one two"s;
	string s22 = "two\ntwo"s;
	string sxx = R"(two\ntwo)"s;

	cout << "s12=" << s12 << endl;
	cout << "s22=" << s22 << endl;
	cout << "sxx=" << sxx << endl;
	cout << "s13=" << s13 << endl;
}
