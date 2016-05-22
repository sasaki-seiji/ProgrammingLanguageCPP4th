/*
 * throw_exception.cpp
 *
 *  Created on: 2016/05/17
 *      Author: sasaki
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class No_copy {
public:
	No_copy(const No_copy&) = delete;
};

class My_error {

};

void f(int n)
{
	switch (n) {
	case 0:	throw My_error{};
	//case 1: throw No_copy{};
		// use of deleted function 'No_copy::No_copy(const No_copy&)'
	//case 2: throw My_error;
		// expected primary-expression before ';' token
	}
}

void g();
void h();

void f()
{
	string name {"Byron"};
	try {
		string s = "in";
		g();
	}
	catch (My_error) {
		cerr << "caught My_error\n";
	}
}

void g()
{
	string s = "excess";
	{
		string s = "or";
		h();
	}
}

void h()
{
	string s = "not";
	throw My_error{};
	string s2 = "at all";
}

struct Some_error { };

bool something_wrong = false;

void fct()
{
	if (something_wrong)
		throw Some_error{};
	cout << "fct() succeeds\n";
}

struct My_error2 : std::runtime_error {
	My_error2() : runtime_error("My_error2") { }
	//const char* what() const noexcept { return "My_error2"; }
};

void g(int n)
{
	if (n)
		throw std::runtime_error{"I give up!"};
	else
		throw My_error2{};
}

void f2(int n)
{
	try {
		g(n);
	}
	catch (std::exception& e) {
		cerr << e.what() << '\n';
	}
}

int main()
{
	try {
		f(0);
	}
	catch (My_error& e) {
		cerr << "caught My_error\n";
	}

	f();

	try {
		fct();
		something_wrong = true;
		fct();
	}
	catch (Some_error& e) {
		cerr << "caught Some_error\n";
	}

	try {
		f2(1);
	}
	catch (My_error2& e) {
		cerr << e.what() << '\n';
	}

	try {
		f2(0);
	}
	catch (My_error2& e) {
		cerr << e.what() << '\n';
	}
}
