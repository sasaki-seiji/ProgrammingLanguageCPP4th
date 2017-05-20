/*
 * type_property_predicate.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef TYPE_PROPERTY_PREDICATE_H_
#define TYPE_PROPERTY_PREDICATE_H_

#include <type_traits>

namespace Estd {
// type property predicate

template<typename X>
constexpr bool Default_constructible()
{
	return std::is_default_constructible<X>::value;
}

template<typename X>
constexpr bool Copy_constructible()
{
	return std::is_copy_constructible<X>::value;
}

template<typename X>
constexpr bool Move_constructible()
{
	return std::is_move_constructible<X>::value;
}

template<typename X>
constexpr bool Copy_assignable()
{
	return std::is_copy_assignable<X>::value;
}

template<typename X>
constexpr bool Move_assignable()
{
	return std::is_move_assignable<X>::value;
}

template<typename X>
constexpr bool Destructible()
{
	return std::is_destructible<X>::value;
}

}


#endif /* TYPE_PROPERTY_PREDICATE_H_ */
