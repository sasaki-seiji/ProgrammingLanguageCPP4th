/*
 * has_stream_operator.h
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */

#ifndef HAS_STREAM_OPERATOR_H_
#define HAS_STREAM_OPERATOR_H_


#include "substitution_failure.h"
#include <iostream>

namespace Estd {

// streamin: >>

template<typename T>
struct get_streamin_result {
	template<typename X>
		static auto check(X x) -> decltype(std::cin >> x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_streamin
	: substitution_succeeded<typename get_streamin_result<T>::type>
{ };

template<typename T>
constexpr bool Has_streamin()
{
	return has_streamin<T>::value;
}

template<typename T>
using Get_streamin_result = typename get_streamin_result<T>::type;

// streamout: <<

template<typename T>
struct get_streamout_result {
	template<typename X>
		static auto check(const X& x) -> decltype(std::cout << x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_streamout
	: substitution_succeeded<typename get_streamout_result<T>::type>
{ };

template<typename T>
constexpr bool Has_streamout()
{
	return has_streamout<T>::value;
}

template<typename T>
using Get_streamout_result = typename get_streamout_result<T>::type;

} // end of Estd


#endif /* HAS_STREAM_OPERATOR_H_ */
