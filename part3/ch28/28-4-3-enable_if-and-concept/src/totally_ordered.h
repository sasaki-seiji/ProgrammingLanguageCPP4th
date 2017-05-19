/*
 * totally_ordered.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef TOTALLY_ORDERED_H_
#define TOTALLY_ORDERED_H_

#include "equality_comparable.h"
#include "has_less.h"
#include "has_less_equal.h"
#include "has_greater.h"
#include "has_greater_equal.h"
#include "boolean.h"

namespace Estd {
// Totally_ordered<>()

template<typename T>
constexpr bool Totally_ordered()
{
	return Equality_comparable<T>()
			&& Has_less<T>() && Boolean<Less_result<T>>()
			&& Has_less_equal<T>() && Boolean<Less_equal_result<T>>()
			&& Has_greater<T>() && Boolean<Greater_result<T>>()
			&& Has_greater_equal<T>() && Boolean<Greater_equal_result<T>>();
}

}


#endif /* TOTALLY_ORDERED_H_ */
