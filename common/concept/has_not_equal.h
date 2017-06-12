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

template<typename T, typename U>
struct get_not_equal_result {
private:
	template<typename X, typename Y>
		static auto check(const X& x, const Y& y) -> decltype(x!=y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_not_equal : substitution_succeeded<typename get_not_equal_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_not_equal()
{
	return has_not_equal<T,U>::value;
}

template<typename T, typename U=T>
using Not_equal_result = typename get_not_equal_result<T,U>::type;

}


#endif /* HAS_NOT_EQUAL_H_ */
