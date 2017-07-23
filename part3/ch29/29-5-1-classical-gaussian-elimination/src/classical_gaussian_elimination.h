/*
 * classical_gaussian_elimination.h
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */

#ifndef CLASSICAL_GAUSSIAN_ELIMINATION_H_
#define CLASSICAL_GAUSSIAN_ELIMINATION_H_

#include "Matrix.h"
//#include "Matrix_multiply.h"
#include <exception>
#include <string>
using namespace std;

using Mat2d = Matrix<double,2>;
using Vec = Matrix<double,1>;

struct Elim_failure : public exception {
	int row;
	Elim_failure(int r) : row(r) { }
	const char* what() const noexcept
		{ return "elimination failure"; }
};

struct Back_subst_failure : public exception {
	int row;
	Back_subst_failure(int r) : row(r) { }
	const char* what() const noexcept
		{ return "back substitution failure"; }
};

Vec classical_gaussian_elimination(Mat2d A, Vec b);
void classical_elimination(Mat2d& A, Vec& b);
Vec back_substitution(const Mat2d& A, const Vec& b);
Vec scale_and_add(const Matrix_ref<double,1>&, double, const Matrix_ref<double,1>&);


#endif /* CLASSICAL_GAUSSIAN_ELIMINATION_H_ */
