/*
 * Matrix_concept.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_CONCEPT_H_
#define MATRIX_CONCEPT_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>
using namespace std;

template<typename M>
constexpr bool Matrix_type()
{
	return false;
}

namespace Matrix_impl {

	template<typename T, size_t N>
	struct Matrix_init {
		using type = initializer_list<typename Matrix_init<T,N-1>::type>;
	};

	template<typename T>
	struct Matrix_init<T,1> {
		using type = initializer_list<T>;
	};

	template<typename T>
	struct Matrix_init<T,0>;

} // end of Matrix_impl

template<typename T, size_t N>
using Matrix_initializer = typename Matrix_impl::Matrix_init<T,N>::type;

template<typename T>
ostream& operator<<(ostream& os, initializer_list<T> il)
{
	os << "{ ";
	for (auto x : il)
		os << x << ',';
	return os << "}";
}

#endif /* MATRIX_CONCEPT_H_ */
