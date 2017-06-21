/*
 * has_reference.h
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */

#ifndef HAS_REFERENCE_H_
#define HAS_REFERENCE_H_


#include "substitution_failure.h"

namespace Estd {

// &x : reference

template<typename T>
struct get_reference_result {
	template<typename X>
		static auto check(const X& x) -> decltype(&x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_reference
	: substitution_succeeded<typename get_reference_result<T>::type>
{ };

template<typename T>
constexpr bool Has_reference()
{
	return has_reference<T>::value;
}

template<typename T>
using Reference_result = typename get_reference_result<T>::type;


} // end of Estd



#endif /* HAS_REFERENCE_H_ */
