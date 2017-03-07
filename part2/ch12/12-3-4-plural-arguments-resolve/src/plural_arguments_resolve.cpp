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
	cout << "-- k(complex:" << z << ") --\n";

	int i = pow(2,2);
	cout << "pow(2,2) -> " << i << endl;

	double d = pow(2.0,2.0);
	cout << "pow(2.0,2.0) -> " << d << endl;

	complex z2 = pow(2,z);
	cout << "pow(2,z) -> " << z2 << endl;

	complex z3 = pow(z,2);
	cout << "pow(z,2) -> " << z3 << endl;

	complex z4 = pow(z,z);
	cout << "pow(z,z) -> " << z4 << endl;
}

void g()
{
	//double d = pow(2.0, 2);
		// error: call of overloaded 'pow(double, int)' is ambiguous
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

