/*
 * common.h
 *
 *  Created on: 2017/06/20
 *      Author: sasaki
 */

#ifndef COMMON_H_
#define COMMON_H_


#include "substitution_failure.h"

namespace Estd {

// ?: : Common

template<typename T, typename U>
struct get_common_result {
private:
	template<typename X, typename Y>
		static auto check(X x, Y y) -> decltype(true?x:y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_common : substitution_succeeded<typename get_common_result<T,U>::type>
{ };

template<typename T, typename U>
constexpr bool Common()
{
	return has_common<T,U>::value;
}

template<typename T, typename U=T>
using Common_type = typename get_common_result<T,U>::type;

} // end of Estd




#endif /* COMMON_H_ */
