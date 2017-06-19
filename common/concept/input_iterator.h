/*
 * input_iterator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef INPUT_ITERATOR_H_
#define INPUT_ITERATOR_H_


#include "type_relation.h"
#include "type_converter.h"
#include "has_iterator_traits.h"
#include "has_dereference.h"
#include "has_increment.h"
#include "has_equality_operator.h"

namespace Estd {

#if 0
template<typename T, typename Alt>
using Avoid_void = Conditional<Same<T,void>(),Alt,T>;

struct Dummy { };
#endif

template<typename Iter>
constexpr bool Input_iterator()
{
	return Has_iterator_category<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::input_iterator_tag>()
		&& Has_dereference<Iter>()
		&& Has_iterator_value_type<Iter>()
		&& Convertible<Dereference_result<Iter>,Iterator_value_type_result<Iter>>()
		&& Has_pre_increment<Iter>() && Has_post_increment<Iter>()
		&& Has_equal<Iter>() && Has_not_equal<Iter>();
}


}





#endif /* INPUT_ITERATOR_H_ */
