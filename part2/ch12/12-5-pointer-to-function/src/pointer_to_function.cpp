/*
 * pointer_to_function.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void error(string s) { cout << "error(" << s << ")\n"; }

void (*efct)(string);

void f()
{
	efct = &error;
	efct("error");
}

void (*f1)(string) = &error;
void (*f2)(string) = error;

void g()
{
	f1("Vasa");
	(*f1)("Mary Rose");
}

void (*pf)(string);
void h1(string);
int h2(string);
void h3(int*);

void h()
{
	pf = &h1;
	//pf = &h2;
		// invalid conversion from 'int (*)(std::__cxx11::string) {aka int (*)(std::__cxx11::basic_string<char>)}' to 'void (*)(std::__cxx11::string) {aka void (*)(std::__cxx11::basic_string<char>)}' [-fpermissive]
	//pf = &h3;
		// invalid conversion from 'void (*)(int*)' to 'void (*)(std::__cxx11::string) {aka void (*)(std::__cxx11::basic_string<char>)}' [-fpermissive]

	pf("Hera");
	//pf(1);
		// could not convert '1' from 'int' to 'std::__cxx11::string {aka std::__cxx11::basic_string<char>}'

	//int i = pf("Zeus");
		// void value not ignored as it ought to be
}

using P1 = int(*)(int*);
using P2 = void(*)(void);

void f(P1 pf)
{
	P2 pf2 = reinterpret_cast<P2>(pf);
	pf2();
	P1 pf1 = reinterpret_cast<P1>(pf2);
	int x = 7;
	int y = pf1(&x);

	cout << "y: " << y << '\n';
}

int func(int* p)
{
	cout << "func(int*: " << p << ")\n";
	return *p;
}


int main()
{
	f();
	g();
	h();

	f(func);
}

// undefs
void h1(string s)
{
	cout << "h1(" << s << ")\n";
}
