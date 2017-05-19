/*
 * has_equal.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_EQUAL_H_
#define HAS_EQUAL_H_

#include "substitution_failure.h"

namespace Estd {
// Has_equal<>

template<typename T>
struct get_equal_result {
private:
	template<typename X>
		static auto check(X x) -> decltype(x==x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_equal : substitution_succeeded<typename get_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_equal()
{
	return has_equal<T>::value;
}

template<typename T>
using Equal_result = typename get_equal_result<T>::type;

}

#endif /* HAS_EQUAL_H_ */
