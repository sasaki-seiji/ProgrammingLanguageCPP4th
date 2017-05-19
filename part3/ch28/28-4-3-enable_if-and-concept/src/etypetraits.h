/*
 * etypetraits.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef ETYPETRAITS_H_
#define ETYPETRAITS_H_

#include <type_traits>

namespace Estd {
// type traits

template<bool B, typename X=void>
using Enable_if = typename std::enable_if<B,X>::type;

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

// type relation

template<typename X, typename Y>
constexpr bool Convertible()
{
	return std::is_convertible<X,Y>::value;
}
}



#endif /* ETYPETRAITS_H_ */
