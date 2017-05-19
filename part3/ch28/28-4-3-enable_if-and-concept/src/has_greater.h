/*
 * has_greater.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef HAS_GREATER_H_
#define HAS_GREATER_H_

#include "substitution_failure.h"

namespace Estd {
// Has_greater<>()

template<typename T>
struct get_greater_result {
private:
	template<typename X>
		static auto check(X x) -> decltype(x>x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_greater : substitution_succeeded<typename get_greater_result<T>::type>
{ };

template<typename T>
constexpr bool Has_greater()
{
	return has_greater<T>::value;
}

template<typename T>
using Greater_result = typename get_greater_result<T>::type;

}


#endif /* HAS_GREATER_H_ */
