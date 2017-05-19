/*
 * has_dereference.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef HAS_DEREFERENCE_H_
#define HAS_DEREFERENCE_H_

#include "substitution_failure.h"

namespace Estd {

template<typename T>
struct get_dereference_result {
	template<typename X>
		static auto check(X x) -> decltype(*x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_dereference
		: substitution_succeeded<typename get_dereference_result<T>::type>
{ };

template<typename T>
constexpr bool Has_dereference()
{
	return has_dereference<T>::value;
}

template<typename T>
using Get_dereference_result = typename get_dereference_result<T>::type;

}

#endif /* HAS_DEREFERENCE_H_ */
