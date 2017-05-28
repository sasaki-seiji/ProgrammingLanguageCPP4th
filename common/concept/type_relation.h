/*
 * type_relation.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef TYPE_RELATION_H_
#define TYPE_RELATION_H_

#include <type_traits>

namespace Estd {
// type relation

template<typename X, typename Y>
constexpr bool Is_same()
{
	return std::is_same<X,Y>::value;
}

template<typename X, typename Y>
constexpr bool Convertible()
{
	return std::is_convertible<X,Y>::value;
}

}

#endif /* TYPE_RELATION_H_ */
