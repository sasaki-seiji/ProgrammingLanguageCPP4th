/*
 * has_arithmetic_operator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef HAS_ARITHMETIC_OPERATOR_H_
#define HAS_ARITHMETIC_OPERATOR_H_


#include "substitution_failure.h"

namespace Estd {

// + : has_addition

template<typename T, typename U>
struct get_addition_result {
private:
	template<typename X, typename Y>
		static auto check(const X& x, const Y& y) -> decltype(x+y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_addition : substitution_succeeded<typename get_addition_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_addition()
{
	return has_addition<T,U>::value;
}

template<typename T, typename U=T>
using Addition_result = typename get_addition_result<T,U>::type;


// - : has_subtraction

template<typename T, typename U>
struct get_subtraction_result {
private:
	template<typename X, typename Y>
		static auto check(const X& x, const Y& y) -> decltype(x-y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_subtraction : substitution_succeeded<typename get_subtraction_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_subtraction()
{
	return has_subtraction<T,U>::value;
}

template<typename T, typename U=T>
using Subtraction_result = typename get_subtraction_result<T,U>::type;

} // end of Estd




#endif /* HAS_ARITHMETIC_OPERATOR_H_ */
