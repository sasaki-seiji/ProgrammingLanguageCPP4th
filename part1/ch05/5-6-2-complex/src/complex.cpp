/*
 * complex.cpp
 *
 *  Created on: 2016/04/07
 *      Author: sasaki
 */

#include <complex>
#include <iostream>
using namespace std;

void f(complex<float> fl, complex<double> db)
{
	//complex<long double> ld {fl+sqrt(db)};
	// no matching function for call to 'std::complex<long double>::complex(<brace-enclosed initializer list>)'
	complex<long double> ld {static_cast<complex<double>>(fl)+sqrt(db)};

	//db += fl*3;
	// no match for 'operator*' (operand types are 'std::complex<float>' and 'int')
	db += fl*static_cast<complex<float>>(3);

	//fl = pow(1/fl, 2);
	// no match for 'operator/' (operand types are 'int' and 'std::complex<float>')
	fl = pow(static_cast<complex<float>>(1)/fl, 2);

	cout << "fl = " << fl << ", db = " << db << "ld = " << ld << '\n';
}

int main()
{
	complex<float> fl{1.0F, 1.0F};
	complex<double> db{1.0, 2.0};
	f(fl, db);
}
