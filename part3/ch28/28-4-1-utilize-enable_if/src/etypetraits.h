/*
 * etypetraits.h
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#ifndef ETYPETRAITS_H_
#define ETYPETRAITS_H_


#include <type_traits>
#include <iterator>

namespace Estd {

template<bool B, typename T =void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename X, typename Y>
constexpr bool Is_convertible()
{
	return std::is_convertible<X,Y>::value;
}


struct substitution_failure { };

template<typename Cat>
constexpr bool is_input_iterator_cat()
{
	return Is_convertible<Cat, std::input_iterator_tag>();
};

template<>
constexpr bool is_input_iterator_cat<substitution_failure>()
{
	return false;
};

template<typename T>
struct get_iterator_category {
	template<typename X>
		static typename std::iterator_traits<X>::iterator_category check(X x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
constexpr bool Input_iterator()
{
	return is_input_iterator_cat<typename get_iterator_category<T>::type>();
}

}


#endif /* ETYPETRAITS_H_ */
