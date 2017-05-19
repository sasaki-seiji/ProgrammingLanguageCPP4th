/*
 * has_less.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_LESS_H_
#define HAS_LESS_H_

#include "substitution_failure.h"

namespace Estd {
// Has_less<>()

template<typename T>
struct get_less_result {
private:
	template<typename X>
		static auto check(X x) -> decltype(x<x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_less : substitution_succeeded<typename get_less_result<T>::type>
{ };

template<typename T>
constexpr bool Has_less()
{
	return has_less<T>::value;
}

template<typename T>
using Less_result = typename get_less_result<T>::type;

}

#endif /* HAS_LESS_H_ */
