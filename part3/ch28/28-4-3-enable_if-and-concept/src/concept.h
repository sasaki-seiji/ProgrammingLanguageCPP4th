/*
 * concept.h
 *
 *  Created on: 2016/10/11
 *      Author: sasaki
 */

#ifndef CONCEPT_H_
#define CONCEPT_H_

#include <type_traits>

namespace Estd {

template<bool B, typename X=void>
using Enable_if = typename std::enable_if<B,X>::type;

template<typename X>
constexpr bool Is_default_constructible()
{
	return std::is_default_constructible<X>::value;
}

template<typename X>
constexpr bool Is_copy_constructible()
{
	return std::is_copy_constructible<X>::value;
}

struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

template<typename X, typename Y>
struct get_equals_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t==u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X, typename Y>
struct has_equals : substitution_succeeded<typename get_equals_result<X,Y>::type>
{ };

template<typename X, typename Y>
constexpr bool Has_equals()
{
	return has_equals<X,Y>::value;
}

template<typename X, typename Y>
struct get_less_than_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t<u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X, typename Y>
struct has_less_than : substitution_succeeded<typename get_less_than_result<X,Y>::type>
{ };

template<typename X, typename Y>
constexpr bool Has_less_than()
{
	return has_less_than<X,Y>::value;
}



template<typename X, typename Y>
constexpr bool Equality_comparable()
{
	return Has_equals<X,Y>();
}

template<typename X>
constexpr bool Semiregular()
{
	return Is_default_constructible<X>() && Is_copy_constructible<X>();
}

template<typename X>
constexpr bool Regular()
{
	return Semiregular<X>() && Equality_comparable<X,X>();
}

template<typename X, typename Y>
constexpr bool Totally_ordered()
{
	return Equality_comparable<X,Y>() && Has_less_than<X,Y>();
}

template<typename X>
constexpr bool Ordered()
{
	return Regular<X>() && Totally_ordered<X,X>();
}

}
#endif /* CONCEPT_H_ */
