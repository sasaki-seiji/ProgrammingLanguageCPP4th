/*
 * Add.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef ADD_H_
#define ADD_H_

#include <complex>
using std::complex;

class Add {
	complex<double> val;
public:
	Add(complex<double> c) :val{c} { }
	Add(double r, double i) :val{{r,i}} { }

	void operator()(complex<double>& c) const { c += val; }
};

#endif /* ADD_H_ */
