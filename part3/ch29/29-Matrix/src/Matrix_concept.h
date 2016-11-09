/*
 * Matrix_concept.h
 *
 *  Created on: 2016/11/05
 *      Author: sasaki
 */

#ifndef MATRIX_CONCEPT_H_
#define MATRIX_CONCEPT_H_

#include "concept.h"

// Has_order<>

template<typename X>
struct get_order_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(t.order);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Order_result = typename get_order_result<X>::type;

template<typename X>
struct has_order : substitution_succeeded<typename get_order_result<X>::type>
{ };

template<typename X>
constexpr bool Has_order()
{
	return has_order<X>::value;
}


template<typename M>
constexpr bool Matrix_type()
{
	return Has_order<M>();
}


#endif /* MATRIX_CONCEPT_H_ */
