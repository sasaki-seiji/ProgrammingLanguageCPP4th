/*
 * equality_comparable.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef EQUALITY_COMPARABLE_H_
#define EQUALITY_COMPARABLE_H_

#include "has_equal.h"
#include "has_not_equal.h"
#include "boolean.h"

namespace Estd {
// Equality_comparable<>()

template<typename T>
constexpr bool Equality_comparable()
{
	return Has_equal<T>() && Boolean<Equal_result<T>>()
			&& Has_not_equal<T>() && Boolean<Not_equal_result<T>>();
}

}


#endif /* EQUALITY_COMPARABLE_H_ */
