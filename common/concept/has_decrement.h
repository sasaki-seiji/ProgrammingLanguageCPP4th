/*
 * has_decrement.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef HAS_DECREMENT_H_
#define HAS_DECREMENT_H_


#include "substitution_failure.h"

namespace Estd {

// --x : pre_decrement

template<typename T>
struct get_pre_decrement_result {
	template<typename X>
		static auto check(X x) -> decltype(--x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_pre_decrement
		: substitution_succeeded<typename get_pre_decrement_result<T>::type>
{ };

template<typename T>
constexpr bool Has_pre_decrement()
{
	return has_pre_decrement<T>::value;
}

template<typename T>
using Pre_decrement_result = typename get_pre_decrement_result<T>::type;


// x-- : post_decrement

template<typename T>
struct get_post_decrement_result {
	template<typename X>
		static auto check(X x) -> decltype(x--);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_post_decrement
		: substitution_succeeded<typename get_post_decrement_result<T>::type>
{ };

template<typename T>
constexpr bool Has_post_decrement()
{
	return has_post_decrement<T>::value;
}

template<typename T>
using Post_decrement_result = typename get_post_decrement_result<T>::type;


} // end of Estd




#endif /* HAS_DECREMENT_H_ */
