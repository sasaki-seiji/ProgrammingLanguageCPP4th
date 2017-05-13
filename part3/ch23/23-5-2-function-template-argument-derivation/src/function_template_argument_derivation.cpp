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

	cout << "f(const <" << t_name << ">*, <" << u_name << ">(*)(<" << u_name << ">))\n";
}

int g(int) { return 1; }

template<typename T>
void f2(T i, T* p);

void g2(int i)
{
	f2(i,&i);
	//f2(i,"Remember!");
		// error: no matching function for call to ‘f2(int&, const char [10])’
}

// undefs

template<typename T>
void f2(T i, T* p)
{
	const char* t_name = typeid(T).name();
	cout << "f2(<" << t_name << ">: " << i << ", <" << t_name << ">*: " << p << ")\n";
}


// add main

int main()
{
	h("string");
	g2(10);
}

