/*
 * has_iterator_traits.h
 *
 *  Created on: 2017/06/16
 *      Author: sasaki
 */

#ifndef HAS_ITERATOR_TRAITS_H_
#define HAS_ITERATOR_TRAITS_H_


#include <iterator>

#include "substitution_failure.h"

namespace Estd {

// iterator_category

template<typename T>
struct get_iterator_category_result {
	template<typename X>
		static typename std::iterator_traits<X>::iterator_category check(X x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_iterator_category
		: substitution_succeeded<typename get_iterator_category_result<T>::type>
{ };

template<typename T>
constexpr bool Has_iterator_category()
{
	return has_iterator_category<T>::value;
}

template<typename T>
using Iterator_category_result = typename get_iterator_category_result<T>::type;


// iterator_value_type

template<typename T>
struct get_iterator_value_type_result {
	template<typename X>
		static typename std::iterator_traits<X>::value_type check(X x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_iterator_value_type
		: substitution_succeeded<typename get_iterator_value_type_result<T>::type>
{ };

template<typename T>
constexpr bool Has_iterator_value_type()
{
	return has_iterator_value_type<T>::value;
}

template<typename T>
using Iterator_value_type_result = typename get_iterator_value_type_result<T>::type;


} // end of Estd




#endif /* HAS_ITERATOR_TRAITS_H_ */
