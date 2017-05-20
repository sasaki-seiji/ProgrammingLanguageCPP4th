/*
 * has_not_equal.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_NOT_EQUAL_H_
#define HAS_NOT_EQUAL_H_

#include "substitution_failure.h"

namespace Estd {
// Has_not_equal<>

template<typename T>
struct get_not_equal_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x!=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_not_equal : substitution_succeeded<typename get_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_not_equal()
{
	return has_not_equal<T>::value;
}

template<typename T>
using Not_equal_result = typename get_not_equal_result<T>::type;

}


#endif /* HAS_NOT_EQUAL_H_ */
