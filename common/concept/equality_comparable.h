/*
 * equality_comparable.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef EQUALITY_COMPARABLE_H_
#define EQUALITY_COMPARABLE_H_

#include "has_equality_operator.h"
#include "boolean.h"

namespace Estd {
// Equality_comparable<>()

template<typename T, typename U=T>
constexpr bool Equality_comparable()
{
	return Has_equal<T,U>() && Boolean<Equal_result<T,U>>()
			&& Has_not_equal<U,T>() && Boolean<Not_equal_result<U,T>>();
}

}


#endif /* EQUALITY_COMPARABLE_H_ */
