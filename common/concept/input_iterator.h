/*
 * input_iterator.h
 *
 *  Created on: 2017/05/19
 *      Author: sasaki
 */

#ifndef INPUT_ITERATOR_H_
#define INPUT_ITERATOR_H_

#include "type_relation.h"
#include "has_iterator_category.h"
#include "has_dereference.h"
#include "has_pre_increment.h"

namespace Estd {

template<typename T>
constexpr bool Input_iterator()
{
	return Has_iterator_category<T>()
		&& Convertible<Get_iterator_category<T>, std::input_iterator_tag>()
		&& Has_dereference<T>()
		&& Has_pre_increment<T>();
}

}




#endif /* INPUT_ITERATOR_H_ */
