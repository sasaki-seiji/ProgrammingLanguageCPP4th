/*
 * Matrix.h
 *
 *  Created on: 2016/08/06
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <array>
#include <iostream>
using std::array;
using std::ostream;

class Matrix {
	array<int, 2> dim;
	double* elem;
public:
	Matrix(int r, int c) :dim{r,c}, elem{new double[r*c]} { }
	Matrix(const Matrix&);
	Matrix(Matrix&&);
	Matrix& operator=(const Matrix&);
	Matrix& operator=(Matrix&&);
	~Matrix() { delete[] elem; }

	int size() const { return dim[0]*dim[1]; }
	int rows() const { return dim[0]; }
	int cols() const { return dim[1]; }

	double& at(int i, int j) { return elem[i*dim[1]+j]; }
	double at(int i, int j) const { return elem[i*dim[1]+j]; }

	Matrix& operator+=(const Matrix&);
};

Matrix operator+(const Matrix& a, const Matrix& b);

ostream& operator<<(ostream& os, const Matrix& m);


#endif /* MATRIX_H_ */
