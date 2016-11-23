/*
 * Matrix_multiply.h
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */

#ifndef MATRIX_MULTIPLY_H_
#define MATRIX_MULTIPLY_H_

#include "Matrix.h"

// Matrix<1> * Matrix<1> -> Matrix<2>
template<typename T>
Matrix<T,2> operator*(const Matrix<T,1>& u, const Matrix<T,1>& v)
{
	const size_t n = u.extent(0);
	const size_t m = v.extent(0);
	Matrix<T,2> res(n,m);
	for (size_t i = 0; i!=n; ++i)
		for (size_t j = 0; j!=m; ++j)
			res(i,j) = u[i]*v[j];
	return res;
}

// Matrix<2> * Matrix<1> -> Matrix<1>
template<typename T>
Matrix<T,1> operator*(const Matrix<T,2>& m, const Matrix<T,1>& v)
{
	assert(m.extent(1)==v.extent(0));
	const size_t nr = m.extent(0);
	const size_t nc = m.extent(1);
	Matrix<T,1> res(nr);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=nc; ++j)
			res(i) += m(i,j)*v(j);
	return res;
}

#if 0
template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2)
{
	const size_t nr = m1.extent(0);
	const size_t nc = m1.extent(1);
	assert(nc==m2.extent(0));
	const size_t p = m2.extent(1);
	Matrix<T,2> res(nr,p);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=p; ++j)
			for (size_t k = 0; k!=nc; ++k)
				res(i,j) += m1(i,k)*m2(k,j);
	return res;
}
#endif


// dot_product: inner_product of 2 Matrix_ref<1>
#if 0	// 2016.11.23 : adapt mixed type product
template<typename T>
T dot_product(const Matrix_ref<T,1>& a, const Matrix_ref<T,1>& b)
{
	return std::inner_product(a.begin(),a.end(),b.begin(),0.0);
}
#else
template<typename T1, typename T2, typename RT=Common_type<T1,T2>>
RT dot_product(const Matrix_ref<T1,1>& a, const Matrix_ref<T2,1>& b)
{
	return std::inner_product(a.begin(),a.end(),b.begin(),0.0);
}
#endif

// Matrix<2> * Matrix<2> -> Matrix<2>
template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2)
{
	const size_t nr = m1.extent(0);
	const size_t nc = m1.extent(1);
	assert(nc==m2.extent(0));
	const size_t p = m2.extent(1);
	Matrix<T,2> res(nr,p);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=p; ++j)
			res(i,j) = dot_product(m1[i],m2.col(j));
	return res;
}




#endif /* MATRIX_MULTIPLY_H_ */
