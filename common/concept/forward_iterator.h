/*
 * forward_iterator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef FORWARD_ITERATOR_H_
#define FORWARD_ITERATOR_H_

#include "input_iterator.h"
#include "primary_type_predicate.h"

namespace Estd {


template<typename Iter>
constexpr bool Const_forward_iterator()
{
	return Input_iterator<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::forward_iterator_tag>()
		&& (!Is_class<Dereference_result<Iter>>() || Has_arrow<Iter>());
}

template<typename Iter>
constexpr bool Forward_iterator()
{
	return Const_forward_iterator<Iter>()
		&& Has_dereference_write<Iter,
			Avoid_void<Iterator_value_type_result<Iter>,Dummy>>();
}

}





#endif /* FORWARD_ITERATOR_H_ */
