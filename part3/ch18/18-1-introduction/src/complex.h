/*
 * complex.h
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <ostream>

class complex {
	double re, im;
public:
	complex(double r, double i) :re{r}, im{i} { }
	complex operator+(complex);
	complex operator*(complex);

	friend std::ostream& operator<<(std::ostream&, complex);
};

#endif /* COMPLEX_H_ */
