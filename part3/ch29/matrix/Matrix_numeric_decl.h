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

// matrix<T1,N> + matrix<T2,N>, matrix<T1,N> - matrix<T2,N>

template<template<typename, size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename RT = Common_type<T1,T2>,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
Matrix<RT,N> operator+(const M1<T1,N>& a, const M2<T2,N>& b);

template<template<typename, size_t> class M1, typename T1, size_t N,
	template<typename,size_t> class M2, typename T2,
	typename RT = Common_type<T1,T2>,
	typename =Enable_if<Dimensional_Matrix_type<M1,T1,N>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T2,N>()>>
Matrix<RT,N> operator-(const M1<T1,N>& a, const M2<T2,N>& b);


// matrix<1> * matrix<1>

template<template<typename,size_t> class M1, typename T,
	template<typename,size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,1>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,1>()>>
Matrix<T,2> operator*(const M1<T,1>& u, const M2<T,1>& v);

// matrix<2> * matrix<1>

template<template<typename,size_t> class M1, typename T,
	template<typename,size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,2>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,1>()>>
Matrix<T,1> operator*(const M1<T,2>& m, const M2<T,1>& v);


// matrix<2> * matrix<2>

template<template<typename,size_t> class M1, typename T,
	template<typename,size_t> class M2,
	typename =Enable_if<Dimensional_Matrix_type<M1,T,2>()>,
	typename =Enable_if<Dimensional_Matrix_type<M2,T,1>()>>
Matrix<T,2> operator*(const M1<T,2>& m1, const M2<T,2>& m2);

#endif /* MATRIX_NUMERIC_DECL_H_ */
