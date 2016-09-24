/*
 * dependent_name.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename T>
int f(T a)
{
	return g(a);
}

class Quad
{
	long double val;
public:
	Quad(long double v=0) :val{v} { }
	operator long double() { return val; }
};

int g(Quad q)
{
	cout << "g(Quad: " << q << ")\n";
	return q;
}

int z = f(Quad{2});


template<typename T>
int ff(T a)
{
	//return gg(Quad{1});
		// error: there are no arguments to 'gg' that depend on a template parameter, so a declaration of 'gg' must be available [-fpermissive]
	return g(Quad{1});
}

int gg(Quad);

int zz = ff(Quad{2});


// add main

int main()
{
	cout << "z: " << z << '\n';
	cout << "zz: " << zz << '\n';
}
