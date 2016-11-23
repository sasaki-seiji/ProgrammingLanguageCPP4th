/*
 * classical_gaussian_elimination.cpp
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */

#include "classical_gaussian_elimination.h"

Vec classical_gaussian_elimination(Mat2d A, Vec b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}

void classical_elimination(Mat2d& A, Vec& b)
{
	const size_t n = A.rows();

	for (size_t j = 0; j!=n-1; ++j) {
		const double pivot = A(j, j);
		if (pivot == 0) throw Elim_failure(j);
		for (size_t i = j+1; i!=n; ++i) {
			const double mult = A(i,j) / pivot;
			A[i](slice(j)) = scale_and_add(A[j](slice(j)), -mult, A[i](slice(j)));
			b(i) -= mult*b(j);
		}
	}
}

Vec back_substitution(const Mat2d& A, const Vec& b)
{
	const size_t n = A.rows();
	Vec x(n);

	//for (size_t i = n-1; i>= 0; --i) { // ?
	for (int i = n-1; i>= 0; --i) { // ?
		double s = b(i) - dot_product(A[i](slice(i+1)),x(slice(i+1)));
		if (double m = A(i,i))
			x(i) = s/m;
		else
			throw Back_subst_failure(i);
	}
	return x;
}

Vec scale_and_add(const Matrix_ref<double,1>& v1, double s, const Matrix_ref<double,1>& v2)
{
	const size_t n = v1.rows();
	Vec ans(n);

	for (size_t i = 0; i!=n; ++i)
		ans(i) = v1(i)*s + v2(i);

	return ans;
}

