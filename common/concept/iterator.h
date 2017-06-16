/*
 * iterator.h
 *
 *  Created on: 2017/06/17
 *      Author: sasaki
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_


#include "type_relation.h"
#include "type_converter.h"
#include "has_iterator_traits.h"
#include "has_dereference.h"
#include "has_increment.h"
#include "has_equality_operator.h"

namespace Estd {

template<typename T, typename Alt>
using Avoid_void = Conditional<Same<T,void>(),Alt,T>;

struct Dummy { };


template<typename Iter>
constexpr bool Input_iterator()
{
	return Has_iterator_category<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::input_iterator_tag>()
		&& Has_dereference<Iter>()
		&& Has_iterator_value_type<Iter>()
		&& Has_dereference_read<Iter,Avoid_void<Iterator_value_type_result<Iter>,Dummy>>()
		&& Has_pre_increment<Iter>() && Has_post_increment<Iter>()
		&& Has_equal<Iter>() && Has_not_equal<Iter>();
}

template<typename Iter, typename Val>
constexpr bool Output_iterator()
{
	return Has_iterator_category<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::output_iterator_tag>()
		&& Has_dereference<Iter>()
		&& Has_iterator_value_type<Iter>()
		&& Has_dereference_write<Iter,Val>()
		&& Has_pre_increment<Iter>() && Has_post_increment<Iter>();
}

}





#endif /* ITERATOR_H_ */
