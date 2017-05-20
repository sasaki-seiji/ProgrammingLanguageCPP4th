/*
 * boolean.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef BOOLEAN_H_
#define BOOLEAN_H_

#include "type_relation.h"

namespace Estd {

template<typename T>
constexpr bool Boolean()
{
	return Convertible<T,bool>();
}

}


#endif /* BOOLEAN_H_ */
