/*
 * Matrix_numeric_impl.h
 *
 *  Created on: 2017/07/14
 *      Author: sasaki
 */

#ifndef MATRIX_NUMERIC_IMPL_H_
#define MATRIX_NUMERIC_IMPL_H_


#include "Matrix_numeric_decl.h"

// matrix op= scalar

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator+=(M<T,N>& m, const T& val)
{
	return m.apply([&](T& a) { a += val; });
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator-=(M<T,N>& m, const T& val)
{
	return m.apply([&](T& a) { a -= val; });
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator*=(M<T,N>& m, const T& val)
{
	return m.apply([&](T& a) { a *= val; });
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator/=(M<T,N>& m, const T& val)
{
	return m.apply([&](T& a) { a /= val; });
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator%=(M<T,N>& m, const T& val)
{
	return m.apply([&](T& a) { a %= val; });
}

// matrix op scalar

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator+(const M<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res += val;
	return res;
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator-(const M<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res -= val;
	return res;
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator*(const M<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res *= val;
	return res;
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator/(const M<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res /= val;
	return res;
}

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator%(const M<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res %= val;
	return res;
}

// matrix op= matrix

template<template<typename,size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
M1<T1,N>& operator+=(M1<T1,N>& m1, const M2<T2,N>& m2)
{
	return m1.apply(m2, [](T1& a, const T2& b){ a += b; });
}

template<template<typename,size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
M1<T1,N>& operator-=(M1<T1,N>& m1, const M2<T2,N>& m2)
{
	return m1.apply(m2, [](T1& a, const T2& b){ a -= b; });
}

// matrix + matrix

template<template<typename, size_t> class M1, typename T, size_t N,
	template<typename, size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,N>()>>
Matrix<T,N> operator+(const M1<T,N>& a, const M2<T,N>& b)
{
	Matrix<T,N> res = a;
	res += b;
	return res;
}

template<template<typename, size_t> class M1, typename T, size_t N,
	template<typename, size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,N>()>>
Matrix<T,N> operator-(const M1<T,N>& a, const M2<T,N>& b)
{
	Matrix<T,N> res = a;
	res -= b;
	return res;
}

// matrix<T1,N> + matrix<T2,N>, matrix<T1,N> - matrix<T2,N>

template<template<typename, size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename RT = Common_type<T1,T2>,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
Matrix<RT,N> operator+(const M1<T1,N>& a, const M2<T2,N>& b)
{
	Matrix<RT,N> res = a;
	res += b;
	return res;
}


template<template<typename, size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename RT = Common_type<T1,T2>,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
Matrix<RT,N> operator-(const M1<T1,N>& a, const M2<T2,N>& b)
{
	Matrix<RT,N> res = a;
	res -= b;
	return res;
}


// matrix<1> * matrix<1>

template<template<typename,size_t> class M1, typename T,
	template<typename,size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,1>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,1>()>>
Matrix<T,2> operator*(const M1<T,1>& u, const M2<T,1>& v)
{
	const size_t n = u.extent(0);
	const size_t m = v.extent(0);
	Matrix<T,2> res(n,m);
	for (size_t i = 0; i!=n; ++i)
		for (size_t j = 0; j!=m; ++j)
			res(i,j) = u[i]*v[j];
	return res;
}


// matrix<2> * matrix<1>

template<template<typename,size_t> class M1, typename T,
	template<typename,size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,2>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,1>()>>
Matrix<T,1> operator*(const M1<T,2>& m, const M2<T,1>& v)
{
	assert(m.extent(1) == v.extent(0));
	const size_t nr = m.extent(0);
	const size_t nc = m.extent(1);
	Matrix<T,1> res(nr);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=nc; ++j)
			res(i) += m(i,j)*v(j);
	return res;
}






#endif /* MATRIX_NUMERIC_IMPL_H_ */
