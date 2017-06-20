/*
 * totally_ordered.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef TOTALLY_ORDERED_H_
#define TOTALLY_ORDERED_H_

#include "equality_comparable.h"
#include "has_comparison_operator.h"
#include "boolean.h"
#include "common.h"

namespace Estd {

// Totally_ordered<>()

template<typename T, typename U=T>
constexpr bool Totally_ordered()
{
	return Common<T,U>()
			&& Equality_comparable<T>()
			&& Equality_comparable<U>()
			&& Equality_comparable<Common_type<T,U>>()
			&& Has_less<T,U>() && Boolean<Less_result<T,U>>()
			&& Has_less<U,T>() && Boolean<Less_result<U,T>>()
			&& Has_less_equal<T,U>() && Boolean<Less_equal_result<T,U>>()
			&& Has_less_equal<U,T>() && Boolean<Less_equal_result<U,T>>()
			&& Has_greater<T,U>() && Boolean<Greater_result<T,U>>()
			&& Has_greater<U,T>() && Boolean<Greater_result<U,T>>()
			&& Has_greater_equal<T,U>() && Boolean<Greater_equal_result<T,U>>()
			&& Has_greater_equal<U,T>() && Boolean<Greater_equal_result<U,T>>();
}

}


#endif /* TOTALLY_ORDERED_H_ */
