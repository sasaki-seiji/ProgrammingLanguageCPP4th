/*
 * has_input_iterator_tag.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef HAS_ITERATOR_CATEGORY_H_
#define HAS_ITERATOR_CATEGORY_H_

#include <iterator>

#include "substitution_failure.h"

namespace Estd {

template<typename T>
struct get_iterator_category {
	template<typename X>
		static typename std::iterator_traits<X>::iterator_category check(X x);
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_iterator_category
		: substitution_succeeded<typename get_iterator_category<T>::type>
{ };

template<typename T>
constexpr bool Has_iterator_category()
{
	return has_iterator_category<T>::value;
}

template<typename T>
using Get_iterator_category = typename get_iterator_category<T>::type;

}

#endif /* HAS_ITERATOR_CATEGORY_H_ */
