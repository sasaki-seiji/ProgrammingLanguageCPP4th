/*
 * has_increment.h
 *
 *  Created on: 2017/06/16
 *      Author: sasaki
 */

#ifndef HAS_INCREMENT_H_
#define HAS_INCREMENT_H_


#include "substitution_failure.h"

namespace Estd {

// ++x : pre_incremnt

template<typename T>
struct get_pre_increment_result {
	template<typename X>
		static auto check(X x) -> decltype(++x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_pre_increment
		: substitution_succeeded<typename get_pre_increment_result<T>::type>
{ };

template<typename T>
constexpr bool Has_pre_increment()
{
	return has_pre_increment<T>::value;
}

template<typename T>
using Pre_increment_result = typename get_pre_increment_result<T>::type;


// x++ : post_incremnt

template<typename T>
struct get_post_increment_result {
	template<typename X>
		static auto check(X x) -> decltype(x++);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_post_increment
		: substitution_succeeded<typename get_post_increment_result<T>::type>
{ };

template<typename T>
constexpr bool Has_post_increment()
{
	return has_post_increment<T>::value;
}

template<typename T>
using Post_increment_result = typename get_post_increment_result<T>::type;


} // end of Estd


#endif /* HAS_INCREMENT_H_ */
