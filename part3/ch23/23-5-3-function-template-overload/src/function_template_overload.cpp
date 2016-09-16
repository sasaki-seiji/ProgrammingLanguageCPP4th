/*
 * function_template_overload.cpp
 *
 *  Created on: 2016/09/16
 *      Author: sasaki
 */


//#include <complex>
#include <iostream>
#include <typeinfo>
using std::cout;
using std::ostream;

template<typename T>
struct complex {
	T re, im;
	complex(T r, T i) : re{r}, im{i} { }
};
template<typename T>
ostream& operator<<(ostream& os, complex<T>z)
{
	os << '(' << z.re << ", " << z.im << ')';
	return os;
}

// resolve overload

template<typename T>
T sqrt(T);

template<typename T>
complex<T> sqrt(complex<T>);

double sqrt(double);


void f(complex<double> z)
{
	sqrt(2);
	sqrt(2.0);
	sqrt(z);
}


// max template

template<typename T>
T max(T,T);

const int s = 7;

void k()
{
	max(1,2);
	max('a','b');
	max(2.7,4.9);
	max(s,7);

	//max('a',1);
		// error: no matching function for call to 'max(char, int)'
	//max(2.7,4);
		// error: no matching function for call to 'max(double, int)'
}

// add undef

template<typename T>
T sqrt(T x)
{
	cout << "sqrt(T: " << x << ")\n";
	return x;
}

template<typename T>
complex<T> sqrt(complex<T> x)
{
	cout << "sqrt(complex<T>: " << x << ")\n";
	return x;
}

double sqrt(double x)
{
	cout << "sqrt(double: " << x << ")\n";
	return x;
}

template<typename T>
T max(T a,T b)
{
	cout << "max<" << typeid(T).name() << ">(" << a << "," << b << ")\n";
	return a < b ? b : a;
}


// add main
int main()
{
	complex<double> z{1,-2};
	f(z);

	k();
}
