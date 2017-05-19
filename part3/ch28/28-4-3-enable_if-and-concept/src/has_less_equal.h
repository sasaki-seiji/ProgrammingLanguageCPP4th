/*
 * has_less_equal.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_LESS_EQUAL_H_
#define HAS_LESS_EQUAL_H_

#include <utility>
#include "substitution_failure.h"

namespace Estd {
// Has_less_equal<>()

template<typename T>
struct get_less_equal_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x<=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_less_equal : substitution_succeeded<typename get_less_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_less_equal()
{
	return has_less_equal<T>::value;
}

template<typename T>
using Less_equal_result = typename get_less_equal_result<T>::type;

}


#endif /* HAS_LESS_EQUAL_H_ */
