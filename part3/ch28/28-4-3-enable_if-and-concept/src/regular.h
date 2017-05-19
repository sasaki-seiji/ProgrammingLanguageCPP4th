/*
 * reqular.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef REGULAR_H_
#define REGULAR_H_

#include "semiregular.h"
#include "equality_comparable.h"

namespace Estd {
// Regular<>()

template<typename X>
constexpr bool Regular()
{
	return Semiregular<X>() && Equality_comparable<X>();
}

}


#endif /* REGULAR_H_ */
