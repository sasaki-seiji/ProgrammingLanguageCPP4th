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

// type property predicate

template<bool B, typename X=void>
using Enable_if = typename std::enable_if<B,X>::type;

template<typename X>
constexpr bool Destructible()
{
	return std::is_destructible<X>::value;
}

template<typename X>
constexpr bool Default_constructible()
{
	return std::is_default_constructible<X>::value;
}

template<typename X>
constexpr bool Move_constructible()
{
	return std::is_move_constructible<X>::value;
}

template<typename X>
constexpr bool Move_assignable()
{
	return std::is_move_assignable<X>::value;
}

template<typename X>
constexpr bool Copy_constructible()
{
	return std::is_copy_constructible<X>::value;
}

template<typename X>
constexpr bool Copy_assignable()
{
	return std::is_copy_assignable<X>::value;
}

template<typename X, typename Y>
constexpr bool Assignable()
{
	return std::is_assignable<X,Y>::value;
}

// type relation

template<typename X, typename Y>
constexpr bool Convertible()
{
	return std::is_convertible<X,Y>::value;
}


// iterator traits

template<typename Iter>
using Value_type = typename std::iterator_traits<Iter>::value_type;

template<typename Iter>
using Difference_type = typename std::iterator_traits<Iter>::difference_type;

template<typename Iter>
using Pointer_type = typename std::iterator_traits<Iter>::pointer_type;

template<typename Iter>
using Reference_type = typename std::iterator_traits<Iter>::reference_type;

template<typename Iter>
using Category = typename std::iterator_traits<Iter>::iterator_category;


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

// Has_dereference_operator<>()

template<typename X>
struct get_dereference_operator_result {
private:
	template<typename T>
		static auto check(const T& t) -> decltype(*t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Dereference_operator_result = typename get_dereference_operator_result<X>::type;

template<typename X>
struct has_dereference_operator : substitution_succeeded<typename get_dereference_operator_result<X>::type>
{ };

template<typename X>
constexpr bool Has_dereference_operator()
{
	return has_dereference_operator<X>::value;
}

// Has_pre_increment_operator<>()

template<typename X>
struct get_pre_increment_operator_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(++t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Pre_increment_operator_result = typename get_pre_increment_operator_result<X>::type;

template<typename X>
struct has_pre_increment_operator : substitution_succeeded<typename get_pre_increment_operator_result<X>::type>
{ };

template<typename X>
constexpr bool Has_pre_increment_operator()
{
	return has_pre_increment_operator<X>::value;
}

// Has_value_type<>()

template<typename X>
struct get_value_type_result {
private:
	template<typename T>
		static Value_type<T> check(T t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Value_type_result = typename get_value_type_result<X>::type;

template<typename X>
struct has_value_type : substitution_succeeded<typename get_value_type_result<X>::type>
{ };

template<typename X>
constexpr bool Has_value_type()
{
	return has_value_type<X>::value;
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
	return Destructible<X>()
		&& Default_constructible<X>()
		&& Move_constructible<X>()
		&& Move_assignable<X>()
		&& Copy_constructible<X>()
		&& Copy_assignable<X>();
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

// iterator

// Common_iterator<Iter>()

template<typename Iter>
constexpr bool Common_iterator()
{
	return Has_value_type<Iter>()
		&& Default_constructible<Iter>()
		&& Copy_constructible<Iter>() && Copy_assignable<Iter>()
		&& Has_dereference_operator<Iter>()
		&& Has_pre_increment_operator<Iter>();
}

// Input_iterator<Iter>()

template<typename Iter>
constexpr bool Input_iterator()
{
	return Common_iterator<Iter>()
		&& Has_equal<Iter>() && Has_not_equal<Iter>()
		&& Assignable<Value_type_result<Iter>&,Dereference_operator_result<Iter>>();
}

}
#endif /* CONCEPT_H_ */
