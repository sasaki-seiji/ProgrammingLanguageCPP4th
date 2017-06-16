/*
 * has_dereference.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef HAS_DEREFERENCE_H_
#define HAS_DEREFERENCE_H_

#include "substitution_failure.h"

namespace Estd {

// *x : dereference

template<typename T>
struct get_dereference_result {
	template<typename X>
		static auto check(const X& x) -> decltype(*x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_dereference
		: substitution_succeeded<typename get_dereference_result<T>::type>
{ };

template<typename T>
constexpr bool Has_dereference()
{
	return has_dereference<T>::value;
}

template<typename T>
using Dereference_result = typename get_dereference_result<T>::type;

// y = *x : dereference_read

template<typename T, typename U>
struct get_dereference_read_result {
	template<typename X, typename Y>
		static auto check(const X& x, Y y) -> decltype(y = *x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>(), std::declval<U>()));
};

template<typename T, typename U>
struct has_dereference_read
		: substitution_succeeded<typename get_dereference_read_result<T,U>::type>
{ };

template<typename T, typename U>
constexpr bool Has_dereference_read()
{
	return has_dereference_read<T,U>::value;
}

template<typename T, typename U>
using Get_dereference_read_result = typename get_dereference_read_result<T,U>::type;


}

#endif /* HAS_DEREFERENCE_H_ */
