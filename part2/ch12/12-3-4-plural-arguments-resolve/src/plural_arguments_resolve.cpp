/*
 * plural_arguments_resolve.cpp
 *
 *  Created on: 2016/05/08
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class complex {
	double re, im;
public:
	complex(double r = 0, double i = 0) :re{r}, im{i} { }
	//complex& operator+=(double d) { re += d; return *this; }
	complex& operator+=(complex z) { re += z.real(); im += z.imag(); return *this; }
	double real() const { return re; }
	double imag() const { return im; }
};

complex operator+(complex z1, complex z2)
{
	z1 += z2;
	return z1;
}

ostream& operator<<(ostream& os, complex z)
{
	os << '(' << z.real() << ',' << z.imag() << ')';
	return os;
}

int pow(int, int);
double pow(double, double);
complex pow(double, complex);
complex pow(complex, int);
complex pow(complex, complex);

void k(complex z)
{
	int i = pow(2,2);
	double d = pow(2.0,2.0);
	complex z2 = pow(2,z);
	complex z3 = pow(z,2);
	complex z4 = pow(z,z);
}

void g()
{
	//double d = pow(2.0, 2);
		// call of overloaded 'pow(double, int)' is ambiguous
}

int main()
{
	complex z {1,2};
	k(z);
}

// undefs
int pow(int i1, int i2)
{
	cout << "pow(int: " << i1 << ", int: " << i2 << ")\n";
	return i1+i2;
}

double pow(double d1, double d2)
{
	cout << "pow(double: " << d1 << ", double: " << d2 << ")\n";
	return d1+d2;
}

complex pow(double d1, complex z2)
{
	cout << "pow(double: " << d1 << ", complex: " << z2 << ")\n";
	return d1+z2;
}

complex pow(complex z1, int i2)
{
	cout << "pow(complex: " << z1 << ", int: " << i2 << ")\n";
	return z1+i2;
}

complex pow(complex z1, complex z2)
{
	cout << "pow(complex: " << z1 << ", complex: " << z2 << ")\n";
	return z1+z2;
}

