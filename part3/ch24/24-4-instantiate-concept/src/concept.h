/*
 * concept.h
 *
 *  Created on: 2016/10/11
 *      Author: sasaki
 */

#ifndef CONCEPT_H_
#define CONCEPT_H_

#include <type_traits>
#include <iostream>

namespace Estd {

// type traits

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

// Has_xxxx<>

struct substitution_failure { };

template<typename T>
struct substitution_succeeded : std::true_type
{ };

template<>
struct substitution_succeeded<substitution_failure> : std::false_type
{ };

// Has_equal<>

template<typename X, typename Y=X>
struct get_equal_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t==u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Equal_result = typename get_equal_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_equal : substitution_succeeded<typename get_equal_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_equal()
{
	return has_equal<X,Y>::value;
}

// Has_not_equal<>

template<typename X, typename Y=X>
struct get_not_equal_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t!=u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Not_equal_result = typename get_not_equal_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_not_equal : substitution_succeeded<typename get_not_equal_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_not_equal()
{
	return has_not_equal<X,Y>::value;
}

// Has_less<>()

template<typename X, typename Y=X>
struct get_less_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t<u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Less_result = typename get_less_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_less : substitution_succeeded<typename get_less_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_less()
{
	return has_less<X,Y>::value;
}

// Has_less_equal<>()

template<typename X, typename Y=X>
struct get_less_equal_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t<=u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X, typename Y=X>
using Less_equal_result = typename get_less_equal_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_less_equal : substitution_succeeded<typename get_less_equal_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_less_equal()
{
	return has_less_equal<X,Y>::value;
}

// Has_greater<>()

template<typename X, typename Y=X>
struct get_greater_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t>u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Greater_result = typename get_greater_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_greater : substitution_succeeded<typename get_greater_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_greater()
{
	return has_greater<X,Y>::value;
}

// Has_greater_equal<>()

template<typename X, typename Y=X>
struct get_greater_equal_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t>=u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Greater_equal_result = typename get_greater_equal_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_greater_equal : substitution_succeeded<typename get_greater_equal_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_greater_equal()
{
	return has_greater_equal<X,Y>::value;
}

// Has_output_operator<>(): to be refactored

template<typename X>
struct get_output_operator_result {
private:
	template<typename T>
		static auto check(T t) -> decltype(std::cout<<t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Output_operator_result = typename get_output_operator_result<X>::type;

template<typename X>
struct has_output_operator : substitution_succeeded<typename get_output_operator_result<X>::type>
{ };

template<typename X>
constexpr bool Has_output_operator()
{
	return has_output_operator<X>::value;
}


// Has_input_operator<>() : to be refactored

template<typename X>
struct get_input_operator_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(std::cin>>t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Input_operator_result = typename get_input_operator_result<X>::type;

template<typename X>
struct has_input_operator : substitution_succeeded<typename get_input_operator_result<X>::type>
{ };

template<typename X>
constexpr bool Has_input_operator()
{
	return has_input_operator<X>::value;
}


// Boolean<T>()

template<typename X>
constexpr bool Boolean()
{
	return std::is_convertible<X,bool>();
}

// Equality_comparable<>()

template<typename X, typename Y=X>
constexpr bool Equality_comparable()
{
	return Has_equal<X,Y>() && Boolean<Equal_result<X,Y>>()
			&& Has_not_equal<X,Y>() && Boolean<Not_equal_result<X,Y>>()
			&& Has_equal<Y,X>() && Boolean<Equal_result<Y,X>>()
			&& Has_not_equal<Y,X>() && Boolean<Not_equal_result<Y,X>>();
}

// Semiregular<>()

template<typename X>
constexpr bool Semiregular()
{
	return Is_default_constructible<X>() && Is_copy_constructible<X>();
}

// Regular<>()

template<typename X>
constexpr bool Regular()
{
	return Semiregular<X>() && Equality_comparable<X>();
}

// Totally_ordered<>()

template<typename X, typename Y=X>
constexpr bool Totally_ordered()
{
	return Equality_comparable<X,Y>()
			&& Has_less<X,Y>() && Boolean<Less_result<X,Y>>()
			&& Has_less_equal<X,Y>() && Boolean<Less_equal_result<X,Y>>()
			&& Has_greater<X,Y>() && Boolean<Greater_result<X,Y>>()
			&& Has_greater_equal<X,Y>() && Boolean<Greater_equal_result<X,Y>>()
			&& Equality_comparable<Y,X>()
			&& Has_less<Y,X>() && Boolean<Less_result<Y,X>>()
			&& Has_less_equal<Y,X>() && Boolean<Less_equal_result<Y,X>>()
			&& Has_greater<Y,X>() && Boolean<Greater_result<Y,X>>()
			&& Has_greater_equal<Y,X>() && Boolean<Greater_equal_result<Y,X>>();
}

// Ordered<>()

template<typename X>
constexpr bool Ordered()
{
	return Regular<X>() && Totally_ordered<X>();
}

// Streamable<>()

template<typename X>
constexpr bool Streamable()
{
	return Has_output_operator<X>() && Has_input_operator<X>();
}

}
#endif /* CONCEPT_H_ */
