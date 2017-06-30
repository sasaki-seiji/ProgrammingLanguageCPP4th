/*
 * Matrix_concept.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_CONCEPT_H_
#define MATRIX_CONCEPT_H_

#include "type_property_predicate.h"
#include "type_converter.h"
#include "substitution_failure.h"
using namespace Estd;

#include "fwd_decl.h"

#include <cstddef>
#include <initializer_list>
#include <iostream>
using namespace std;


// Matrix_type<M>()

namespace Matrix_impl {

	template<typename M>
	struct get_matrix_type_result {

		template<typename T, size_t N, typename = Enable_if<(N>=1)>>
			static bool check(const Matrix<T,N>& m);

		template<typename T, size_t N, typename = Enable_if<(N>=1)>>
			static bool check(const Matrix_ref<T,N>& m);

		static substitution_failure check(...);

		using type = decltype(check(std::declval<M>()));
	};

	template<typename T>
	struct has_matrix_type
		: substitution_succeeded<typename get_matrix_type_result<T>::type>
	{ };

	template<typename M>
	constexpr bool Has_matrix_type()
	{
		return has_matrix_type<M>::value;
	}

	template<typename M>
	using Matrix_type_result = typename get_matrix_type_result<M>::type;

} // end of Matrix_impl

template<typename M>
constexpr bool Matrix_type()
{
	return Matrix_impl::Has_matrix_type<M>();
}

template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m);

// Matrix_initializer<T>

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


// Requesting_element<T>, Requesting_slice<T>

namespace Matrix_impl {

	template<typename... Args>
	constexpr bool Requesting_element();

	template<typename... Args>
	constexpr bool Requesting_slice();

} // end of Matrix_impl


template<typename T>
ostream& operator<<(ostream& os, initializer_list<T> il)
{
	os << "{ ";
	for (auto x : il)
		os << x << ',';
	return os << "}";
}


#endif /* MATRIX_CONCEPT_H_ */
