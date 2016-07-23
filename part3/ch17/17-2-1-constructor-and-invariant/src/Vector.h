/*
 * Vector.h
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Bad_size {
	int sz;
public:
	Bad_size(int s): sz{s} {}
	int size() const { return sz; }
};

class Vector {
public:
	Vector(int n);
	int size() const { return sz; }
private:
	double* elem;
	int sz;
};

#endif /* VECTOR_H_ */
