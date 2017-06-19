/*
 * random_access_iterator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef RANDOM_ACCESS_ITERATOR_H_
#define RANDOM_ACCESS_ITERATOR_H_


#include "bidirectional_iterator.h"
#include "has_assign_operator.h"
#include "has_index.h"
#include "has_arithmetic_operator.h"
#include "totally_ordered.h"
#include "type_property_predicate.h"

namespace Estd {


template<typename Iter>
constexpr bool Const_random_access_iterator()
{
	return Const_bidirectional_iterator<Iter>()
		&& Convertible<Iterator_category_result<Iter>, std::random_access_iterator_tag>()
		&& Has_addassign<Iter,int>() && Has_subassign<Iter,int>()
		&& Has_index<Iter,int>()
		&& Has_addition<Iter,int>() && Has_subtraction<Iter,int>()
		&& Has_subtraction<Iter>()
		&& Totally_ordered<Iter>();
}

template<typename Iter>
constexpr bool Random_access_iterator()
{
	return Const_random_access_iterator<Iter>()
	&& Assignable<Dereference_result<Iter>, Iterator_value_type_result<Iter>>()
	&& Assignable<Index_result<Iter,int>, Iterator_value_type_result<Iter>>();
}

} // end of Estd


#endif /* RANDOM_ACCESS_ITERATOR_H_ */
