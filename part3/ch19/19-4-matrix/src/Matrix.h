/*
 * Matrix.h
 *
 *  Created on: 2016/08/18
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <initializer_list>
#include <ostream>
using std::initializer_list;
using std::ostream;

constexpr int rc_max {4};

class Matrix;

class Vector {
	float v[rc_max];
public:
	Vector();
	Vector(initializer_list<float>);
	Vector& operator=(initializer_list<float>);

	friend Vector operator*(const Matrix&, const Vector&);
	friend ostream& operator<<(ostream&, const Vector&);
};

class Matrix {
	Vector v[rc_max];
public:
	Matrix(initializer_list<initializer_list<float>>);

	friend Vector operator*(const Matrix&, const Vector&);
	friend ostream& operator<<(ostream&, const Matrix&);
};

#endif /* MATRIX_H_ */
