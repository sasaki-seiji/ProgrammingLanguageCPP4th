/*
 * function_template_argument_derivation.cpp
 *
 *  Created on: 2016/09/14
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T, typename U>
void f(const T*, U(*)(U));

int g(int);

void h(const char*p)
{
	f(p,g);
	//f(p,h);
		// error: no matching function for call to 'f(const char*&, void (&)(const char*))'
}

// add undef

template<typename T, typename U>
void f(const T*, U(*)(U))
{
	const char* t_name = typeid(T).name();
	const char* u_name = typeid(U).name();

	cout << "f(const " << t_name << "*, " << u_name << "(*)(" << u_name << "))\n";
}

int g(int) { return 1; }

// add main

int main()
{
	h("string");
}

