/*
 * output_iterator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef OUTPUT_ITERATOR_H_
#define OUTPUT_ITERATOR_H_


#include "type_relation.h"
#include "type_converter.h"
#include "type_property_predicate.h"
#include "has_iterator_traits.h"
#include "has_dereference.h"
#include "has_increment.h"

namespace Estd {


template<typename Iter, typename Val>
constexpr bool Output_iterator()
{
	return Has_iterator_category<Iter>()
//		&& Convertible<Iterator_category_result<Iter>, std::output_iterator_tag>()
		&& Has_dereference<Iter>()
		&& Has_iterator_value_type<Iter>()
		&& Assignable<Dereference_result<Iter>,Val>()
		&& Has_pre_increment<Iter>() && Has_post_increment<Iter>();
}


} // end of Estd

#endif /* OUTPUT_ITERATOR_H_ */
