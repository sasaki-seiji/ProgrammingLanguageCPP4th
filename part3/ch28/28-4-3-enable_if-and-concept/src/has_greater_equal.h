/*
 * has_greater_equal.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_GREATER_EQUAL_H_
#define HAS_GREATER_EQUAL_H_

#include "substitution_failure.h"

namespace Estd {
// Has_greater_equal<>()

template<typename T>
struct get_greater_equal_result {
private:
	template<typename X>
		static auto check(X x) -> decltype(x>=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_greater_equal : substitution_succeeded<typename get_greater_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_greater_equal()
{
	return has_greater_equal<T>::value;
}

template<typename T>
using Greater_equal_result = typename get_greater_equal_result<T>::type;

}


#endif /* HAS_GREATER_EQUAL_H_ */
