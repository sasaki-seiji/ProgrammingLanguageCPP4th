/*
 * has_pre_increment.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef HAS_PRE_INCREMENT_H_
#define HAS_PRE_INCREMENT_H_


#include "substitution_failure.h"

namespace Estd {

template<typename T>
struct get_pre_increment_result {
	template<typename X>
		static auto check(X x) -> decltype(++x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_pre_increment
		: substitution_succeeded<typename get_pre_increment_result<T>::type>
{ };

template<typename T>
constexpr bool Has_pre_increment()
{
	return has_pre_increment<T>::value;
}

template<typename T>
using Get_pre_increment_result = typename get_pre_increment_result<T>::type;

}




#endif /* HAS_PRE_INCREMENT_H_ */
