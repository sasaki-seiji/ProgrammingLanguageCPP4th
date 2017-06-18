/*
 * bidirectional_iterator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef BIDIRECTIONAL_ITERATOR_H_
#define BIDIRECTIONAL_ITERATOR_H_

#include "forward_iterator.h"
#include "has_decrement.h"

namespace Estd {


template<typename Iter>
constexpr bool Const_bidirectional_iterator()
{
	return Const_forward_iterator<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::bidirectional_iterator_tag>()
		&& Has_pre_decrement<Iter>() && Has_post_decrement<Iter>();
}

template<typename Iter>
constexpr bool Bidirectional_iterator()
{
	return Const_bidirectional_iterator<Iter>()
	&& Has_dereference_write<Iter,
		Avoid_void<Iterator_value_type_result<Iter>,Dummy>>();
}

} // end of Estd



#endif /* BIDIRECTIONAL_ITERATOR_H_ */
