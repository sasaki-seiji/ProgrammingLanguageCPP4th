/*
 * semiregular.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef SEMIREGULAR_H_
#define SEMIREGULAR_H_

#include "type_property_predicate.h"

namespace Estd {
// Semiregular<>()

template<typename T>
constexpr bool Semiregular()
{
	return Destructible<T>()
			&& Default_constructible<T>()
			&& Move_constructible<T>()
			&& Move_assignable<T>()
			&& Copy_constructible<T>()
			&& Copy_assignable<T>();
}

}



#endif /* SEMIREGULAR_H_ */
