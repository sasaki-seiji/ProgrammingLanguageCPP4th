/*
 * Matrix_numeric.h
 *
 *  Created on: 2017/07/14
 *      Author: sasaki
 */

#ifndef MATRIX_NUMERIC_DECL_H_
#define MATRIX_NUMERIC_DECL_H_


#include "fwd_decl.h"
#include "Matrix_concept.h"

// matrix op= scalar

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator+=(M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator-=(M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator*=(M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator/=(M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
M<T,N>& operator%=(M<T,N>& m, const T& val);

// matrix op scalar

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator+(const M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator-(const M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator*(const M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator/(const M<T,N>& m, const T& val);

template<template<typename,size_t> class M, typename T, size_t N,
	typename =Enable_if<Dimensional_Matrix_type<M,T,N>()>>
Matrix<T,N> operator%(const M<T,N>& m, const T& val);

// matrix op= matrix

template<template<typename,size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
M1<T1,N>& operator+=(M1<T1,N>& m1, const M2<T2,N>& m2);

template<template<typename,size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
M1<T1,N>& operator-=(M1<T1,N>& m1, const M2<T2,N>& m2);


// matrix + matrix, matrix - matrix

template<template<typename, size_t> class M1, typename T, size_t N,
	template<typename, size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,N>()>>
Matrix<T,N> operator+(const M1<T,N>& a, const M2<T,N>& b);

template<template<typename, size_t> class M1, typename T, size_t N,
	template<typename, size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,N>()>>
Matrix<T,N> operator-(const M1<T,N>& a, const M2<T,N>& b);

#endif /* MATRIX_NUMERIC_DECL_H_ */
