/*
 * movable.h
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */

#ifndef MOVABLE_H_
#define MOVABLE_H_


#include "type_property_predicate.h"
#include "has_reference.h"

namespace Estd {

template<typename T>
constexpr bool Movable()
{
	return Move_constructible<T>()
			&& Move_assignable<T>()
			&& Destructible<T>()
			&& Has_reference<T>();
}

}

#endif /* MOVABLE_H_ */
