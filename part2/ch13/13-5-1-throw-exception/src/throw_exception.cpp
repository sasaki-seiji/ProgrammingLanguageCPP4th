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
	cout << "-- f(" << n << ") --\n";

	switch (n) {
	case 0:	throw My_error{};
	//case 1: throw No_copy{};
		// error: use of deleted function 'No_copy::No_copy(const No_copy&)'
	//case 2: throw My_error;
		// error: expected primary-expression before ';' token
	}
}

void g();
void h();

void f()
{
	cout << "-- f() --\n";

	string name {"Byron"};
	try {
		string s = "in";
		g();
	}
	catch (My_error) {
		cout << "in f(): caught My_error\n";
	}
}

void g()
{
	cout << "-- g() --\n";

	string s = "excess";
	{
		string s = "or";
		h();
	}
}

void h()
{
	cout << "-- h() -- \n";

	string s = "not";
	throw My_error{};
	string s2 = "at all";
}

struct Some_error { };

bool something_wrong = false;

void fct()
{
	cout << "-- fct() --\n";

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
	cout << "-- f2(" << n << ") --\n";

	try {
		g(n);
	}
	catch (std::exception& e) {
		cout << "in f2() caught: " << e.what() << '\n';
	}
}

int main()
{
	try {
		f(0);
	}
	catch (My_error& e) {
		cout << "in main(): caught My_error\n";
	}

	f();

	try {
		fct();
		something_wrong = true;
		fct();
	}
	catch (Some_error& e) {
		cout << "in main(): caught Some_error\n";
	}

	f2(1);
	f2(0);
}
