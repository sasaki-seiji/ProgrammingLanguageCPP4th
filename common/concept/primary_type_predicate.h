/*
 * primary_type_predicate.h
 *
 *  Created on: 2017/05/21
 *      Author: sasaki
 */

#ifndef PRIMARY_TYPE_PREDICATE_H_
#define PRIMARY_TYPE_PREDICATE_H_

#include <type_traits>

namespace Estd {

template<typename T>
constexpr bool Is_class()
{
	return std::is_class<T>::value;
}

}


#endif /* PRIMARY_TYPE_PREDICATE_H_ */
