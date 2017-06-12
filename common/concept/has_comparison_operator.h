/*
 * has_comparison_operator.h
 *
 *  Created on: 2017/06/12
 *      Author: sasaki
 */

#ifndef HAS_COMPARISON_OPERATOR_H_
#define HAS_COMPARISON_OPERATOR_H_


#include "substitution_failure.h"

namespace Estd {

// Has_less<>()

template<typename T>
struct get_less_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x<x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_less : substitution_succeeded<typename get_less_result<T>::type>
{ };

template<typename T>
constexpr bool Has_less()
{
	return has_less<T>::value;
}

template<typename T>
using Less_result = typename get_less_result<T>::type;


// Has_less_equal<>()

template<typename T>
struct get_less_equal_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x<=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_less_equal : substitution_succeeded<typename get_less_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_less_equal()
{
	return has_less_equal<T>::value;
}

template<typename T>
using Less_equal_result = typename get_less_equal_result<T>::type;


// Has_greater<>()

template<typename T>
struct get_greater_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x>x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_greater : substitution_succeeded<typename get_greater_result<T>::type>
{ };

template<typename T>
constexpr bool Has_greater()
{
	return has_greater<T>::value;
}

template<typename T>
using Greater_result = typename get_greater_result<T>::type;


// Has_greater_equal<>()

template<typename T>
struct get_greater_equal_result {
private:
	template<typename X>
		static auto check(const X& x) -> decltype(x>=x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_greater_equal : substitution_succeeded<typename get_greater_equal_result<T>::type>
{ };

template<typename T>
constexpr bool Has_greater_equal()
{
	return has_greater_equal<T>::value;
}

template<typename T>
using Greater_equal_result = typename get_greater_equal_result<T>::type;


} // end of Estd





#endif /* HAS_COMPARISON_OPERATOR_H_ */
