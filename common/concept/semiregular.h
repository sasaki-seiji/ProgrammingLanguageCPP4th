/*
 * semiregular.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef SEMIREGULAR_H_
#define SEMIREGULAR_H_

#include "copyable.h"

namespace Estd {
// Semiregular<>()

template<typename T>
constexpr bool Semiregular()
{
	return Copyable<T>()
			&& Default_constructible<T>();
}

}



#endif /* SEMIREGULAR_H_ */
