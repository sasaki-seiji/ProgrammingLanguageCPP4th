/*
 * argument_dependent_lookup.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

#include <string>
#include <iostream>

namespace Chrono {
	class Date { };
	bool operator==(const Date&, const std::string&);
	std::string format(const Date&);
}

void f(Chrono::Date d, int i)
{
	std::cout << "-- f(Chrono::Date,int) --\n";

	std::string s = format(d);
	//std::string t = format(i);
		// error: 'format' was not declared in this scope
}

void f(Chrono::Date d, std::string s)
{
	std::cout << "-- f(Chrono::Date,string) --\n";

	if (d == s) {

	}
	else if (d == "August 4, 1914") {

	}
}

namespace N {
	struct S { int i; };
	void f(S);
	void g(S);
	void h(int);
}

struct Base {
	void f(N::S);
};

struct D : Base {
	void mf(N::S);
	void g(N::S x)
	{
		std::cout << "-- D::Base::g(N::S) --\n";

		f(x);
		mf(x);
		//h(1);
			// error: 'h' was not declared in this scope
	}
};

namespace N {
	template<typename T>
		void f(T, int);
	class X { };
}

namespace N2 {
	N::X x;

	void f(N::X, unsigned);
	void g()
	{
		std::cout << "-- N2::g() --\n";

		f(x, 1);
	}
}

int main()
{
	f(Chrono::Date{}, 10);
	f(Chrono::Date{}, "string");

	D d;
	N::S s{123};
	d.g(s);

	N2::g();
}

// undefs
std::string Chrono::format(const Date& d)
{
	std::cout << "Chrono::format(const Date&)\n";
	return "";
}
bool Chrono::operator==(const Date& d, const std::string& s)
{
	std::cout << "Chrono::operator==(const Date&, \"" << s << "\")\n";
	return false;
}

void Base::f(N::S)
{
	std::cout << "Base::f(N::S)\n";
}

void D::mf(N::S)
{
	std::cout << "D::mf(N::S)\n";
}

template<typename T>
void N::f(T, int)
{
	std::cout << "template<typename T> void N::f(T, int)\n";
}
