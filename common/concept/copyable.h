/*
 * copyable.h
 *
 *  Created on: 2017/06/21
 *      Author: sasaki
 */

#ifndef COPYABLE_H_
#define COPYABLE_H_


#include "type_property_predicate.h"
#include "movable.h"

namespace Estd {

template<typename T>
constexpr bool Copyable()
{
	return Movable<T>()
			&& Copy_constructible<T>()
			&& Copy_assignable<T>();
}

} // end of Estd

#endif /* COPYABLE_H_ */
