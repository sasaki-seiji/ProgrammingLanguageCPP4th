/*
 * ordered.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef ORDERED_H_
#define ORDERED_H_

#include "regular.h"
#include "totally_ordered.h"

namespace Estd {
template<typename T>
constexpr bool Ordered()
{
	return Regular<T>() && Totally_ordered<T>();
}

}

#endif /* ORDERED_H_ */
