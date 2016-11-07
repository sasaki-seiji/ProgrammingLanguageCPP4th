/*
 * Matrix_decl.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_DECL_H_
#define MATRIX_DECL_H_


template<typename T, size_t N> class Matrix ;

template<typename T, size_t N> class Matrix_ref;

struct slice ;
template<size_t N> struct Matrix_slice ;

constexpr bool All() { return true; }

template<typename... Args>
constexpr bool All(bool b, Args... args)
{
	return b && All(args...);
}

constexpr bool Some() { return false; }

template<typename... Args>
constexpr bool Some(bool b, Args... args)
{
	return b || Some(args...);
}


#endif /* MATRIX_DECL_H_ */
