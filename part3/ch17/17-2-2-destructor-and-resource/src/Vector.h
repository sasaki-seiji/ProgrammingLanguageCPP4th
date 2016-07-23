/*
 * Vector.h
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

class Vector {
public:
	Vector(int s) : elem{new double[s]}, sz{s}
	{
		std::cout << "Vector(" << sz << ")\n";
	}
	~Vector()
	{
		std::cout << "~Vector():sz=" << sz << '\n';
		delete[] elem;
	}
	int size() const { return sz; }
private:
	double* elem;
	int sz;
};

#endif /* VECTOR_H_ */
