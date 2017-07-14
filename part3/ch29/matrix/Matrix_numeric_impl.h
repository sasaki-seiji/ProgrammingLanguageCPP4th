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


#endif /* MATRIX_NUMERIC_IMPL_H_ */
