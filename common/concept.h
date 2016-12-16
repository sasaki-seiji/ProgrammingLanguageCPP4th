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

// 2016.11.11 add:
template<typename X>
using Value_type = typename X::value_type;

// 2016.11.27 add: 32.2.1. sequence
template<typename X>
using Iterator = typename X::iterator;

// primary type predicate

// 2016.12.14
template<typename X>
constexpr bool Is_floating_point()
{
	return std::is_floating_point<X>::value;
}

// 2016.12.14
template<typename X>
constexpr bool Is_array()
{
	return std::is_array<X>::value;
}

template<typename X>
constexpr bool Is_class()
{
	return std::is_class<X>::value;
}

// type property predicate

// 2016.12.14, 2016.12.15
template<typename X>
constexpr bool Is_trivially_copyable()
{
	return std::is_trivially_copyable<X>::value;
}

// 2016.12.14
template<typename X>
constexpr bool Is_trivially_destructible()
{
	return std::is_trivially_destructible<X>::value;
}

template<typename X>
constexpr bool Is_destructible()
{
	return std::is_destructible<X>::value;
}

template<typename X>
constexpr bool Is_default_constructible()
{
	return std::is_default_constructible<X>::value;
}

template<typename X>
constexpr bool Is_move_constructible()
{
	return std::is_move_constructible<X>::value;
}

template<typename X>
constexpr bool Is_move_assignable()
{
	return std::is_move_assignable<X>::value;
}

template<typename X>
constexpr bool Is_copy_constructible()
{
	return std::is_copy_constructible<X>::value;
}

template<typename X>
constexpr bool Is_copy_assignable()
{
	return std::is_copy_assignable<X>::value;
}

template<typename X, typename Y>
constexpr bool Is_assignable()
{
	return std::is_assignable<X,Y>::value;
}

// type property confirm

// 2016.12.14, 2016.12.16
template<typename X, size_t N=0>
constexpr size_t Extent()
{
	return std::extent<X,N>::value;
}

// type relation

template<typename X, typename Y>
constexpr bool Is_convertible()
{
	return std::is_convertible<X,Y>::value;
}

// 2016.11.05 add
template<typename X, typename Y>
constexpr bool Is_same()
{
	return std::is_same<X,Y>::value;
}

// 2016.12.14
template<typename X, typename Y>
constexpr bool Is_base_of()
{
	return std::is_base_of<X,Y>::value;
}

// type generator

// 2016.12.16
template<typename X>
using Add_const = typename std::add_const<X>::type;

// 2016.12.16
template<typename X>
using Remove_reference = typename std::remove_reference<X>::type;

template<typename X>
using Add_lvalue_reference = typename std::add_lvalue_reference<X>::type;

// 2016.12.16
template<typename X>
using Remove_extent = typename std::remove_extent<X>::type;

// 2016.12.16
template<typename X>
using Remove_all_extents = typename std::remove_all_extents<X>::type;

// 2016.12.14
template<typename X>
using Remove_pointer = typename std::remove_pointer<X>::type;

// 2016.12.16
template<typename X>
using Add_pointer = typename std::add_pointer<X>::type;

template<bool B, typename X=void>
using Enable_if = typename std::enable_if<B,X>::type;

template<typename... ARGS>
using Common_type = typename std::common_type<ARGS...>::type;

// 2016.12.16
template<typename FX>
using Result_of = typename std::result_of<FX>::type;


// iterator traits

template<typename Iter>
using Iterator_value_type = typename std::iterator_traits<Iter>::value_type;

template<typename Iter>
using Iterator_difference_type = typename std::iterator_traits<Iter>::difference_type;

template<typename Iter>
using Iterator_pointer_type = typename std::iterator_traits<Iter>::pointer_type;

template<typename Iter>
using Iterator_reference_type = typename std::iterator_traits<Iter>::reference_type;

template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;


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
		static auto check(T t,U u) -> decltype(t==u);
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
		static auto check(T t, U u) -> decltype(t!=u);
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
		static auto check(T t, U u) -> decltype(t<u);
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
		static auto check(T t, U u) -> decltype(t<=u);
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
		static auto check(T t, U u) -> decltype(t>u);
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
		static auto check(T t, U u) -> decltype(t>=u);
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

// Has_plus<>

template<typename X, typename Y=X>
struct get_plus_result {
private:
	template<typename T, typename U>
		static auto check(T t, U u) -> decltype(t+u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Plus_result = typename get_plus_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_plus : substitution_succeeded<typename get_plus_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_plus()
{
	return has_plus<X,Y>::value;
}

// Has_minus<>

template<typename X, typename Y=X>
struct get_minus_result {
private:
	template<typename T, typename U>
		static auto check(T t, U u) -> decltype(t-u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Minus_result = typename get_minus_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_minus : substitution_succeeded<typename get_minus_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_minus()
{
	return has_minus<X,Y>::value;
}


// Has_output<>(): to be refactored

template<typename X>
struct get_output_result {
private:
	template<typename T>
		static auto check(const T& t) -> decltype(std::cout<<t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Output_result = typename get_output_result<X>::type;

template<typename X>
struct has_output : substitution_succeeded<typename get_output_result<X>::type>
{ };

template<typename X>
constexpr bool Has_output()
{
	return has_output<X>::value;
}


// Has_input<>() : to be refactored

template<typename X>
struct get_input_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(std::cin>>t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Input_result = typename get_input_result<X>::type;

template<typename X>
struct has_input : substitution_succeeded<typename get_input_result<X>::type>
{ };

template<typename X>
constexpr bool Has_input()
{
	return has_input<X>::value;
}

// Has_dereference<>()

template<typename X>
struct get_dereference_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(*t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Dereference_result = typename get_dereference_result<X>::type;

template<typename X>
struct has_dereference : substitution_succeeded<typename get_dereference_result<X>::type>
{ };

template<typename X>
constexpr bool Has_dereference()
{
	return has_dereference<X>::value;
}

// Has_Address<>()

template<typename X>
struct get_address_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(&t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Address_result = typename get_address_result<X>::type;

template<typename X>
struct has_address : substitution_succeeded<typename get_address_result<X>::type>
{ };

template<typename X>
constexpr bool Has_address()
{
	return has_address<X>::value;
}

// Has_index<>

template<typename X, typename Y=X>
struct get_index_result {
private:
	template<typename T, typename U>
		static auto check(T& t,const U& u) -> decltype(t[u]);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Index_result = typename get_index_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_index : substitution_succeeded<typename get_index_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_index()
{
	return has_index<X,Y>::value;
}

// Has_call<>

template<typename X, typename Y=X>
struct get_call_result {
private:
	template<typename T, typename U>
		static auto check(const T& t,const U& u) -> decltype(t(u));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Call_result = typename get_call_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_call : substitution_succeeded<typename get_call_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_call()
{
	return has_call<X,Y>::value;
}

// Has_arrow<>()

template<typename X>
struct get_arrow_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(t.operator->());
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Arrow_result = typename get_arrow_result<X>::type;

template<typename X>
struct has_arrow : substitution_succeeded<typename get_arrow_result<X>::type>
{ };

template<typename X>
constexpr bool Has_arrow()
{
	return has_arrow<X>::value;
}

// Has_pre_increment<>()

template<typename X>
struct get_pre_increment_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(++t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Pre_increment_result = typename get_pre_increment_result<X>::type;

template<typename X>
struct has_pre_increment : substitution_succeeded<typename get_pre_increment_result<X>::type>
{ };

template<typename X>
constexpr bool Has_pre_increment()
{
	return has_pre_increment<X>::value;
}

// Has_pre_decrement<>()

template<typename X>
struct get_pre_decrement_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(++t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Pre_decrement_result = typename get_pre_decrement_result<X>::type;

template<typename X>
struct has_pre_decrement : substitution_succeeded<typename get_pre_decrement_result<X>::type>
{ };

template<typename X>
constexpr bool Has_pre_decrement()
{
	return has_pre_decrement<X>::value;
}

// Has_plus_assign<>

template<typename X, typename Y=X>
struct get_plus_assign_result {
private:
	template<typename T, typename U>
		static auto check(T& t,const U& u) -> decltype(t+=u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Plus_assign_result = typename get_plus_assign_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_plus_assign : substitution_succeeded<typename get_plus_assign_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_plus_assign()
{
	return has_plus_assign<X,Y>::value;
}

// Has_minus_assign<>

template<typename X, typename Y=X>
struct get_minus_assign_result {
private:
	template<typename T, typename U>
		static auto check(T& t,const U& u) -> decltype(t-=u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>(),std::declval<Y>()));
};

template<typename X,typename Y=X>
using Minus_assign_result = typename get_minus_assign_result<X,Y>::type;

template<typename X, typename Y=X>
struct has_minus_assign : substitution_succeeded<typename get_minus_assign_result<X,Y>::type>
{ };

template<typename X, typename Y=X>
constexpr bool Has_minus_assign()
{
	return has_minus_assign<X,Y>::value;
}

// Has_common_type<>()

template<typename X, typename Y>
struct get_common_type_result {
private:
	template<typename T, typename U>
		static Common_type<T,U> check(const T& t,const U& u);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>(),std::declval<Y>()));
};

template<typename X,typename Y>
using Common_type_result = typename get_common_type_result<X,Y>::type;

template<typename X,typename Y>
struct has_common_type : substitution_succeeded<typename get_common_type_result<X,Y>::type>
{ };

template<typename X, typename Y>
constexpr bool Has_common_type()
{
	return has_common_type<X,Y>::value;
}


// Has_begin_member<>()

template<typename X>
struct get_begin_member_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(t.begin());
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Begin_member_result = typename get_begin_member_result<X>::type;

template<typename X>
struct has_begin_member : substitution_succeeded<typename get_begin_member_result<X>::type>
{ };

template<typename X>
constexpr bool Has_begin_member()
{
	return has_begin_member<X>::value;
}

// Has_end_member<>()

template<typename X>
struct get_end_member_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(t.end());
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using End_member_result = typename get_end_member_result<X>::type;

template<typename X>
struct has_end_member : substitution_succeeded<typename get_end_member_result<X>::type>
{ };

template<typename X>
constexpr bool Has_end_member()
{
	return has_end_member<X>::value;
}

// Has_begin_function<>()

template<typename X>
struct get_begin_function_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(begin(t));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using Begin_function_result = typename get_begin_function_result<X>::type;

template<typename X>
struct has_begin_function : substitution_succeeded<typename get_begin_function_result<X>::type>
{ };

template<typename X>
constexpr bool Has_begin_function()
{
	return has_begin_function<X>::value;
}

// Has_end_function<>()

template<typename X>
struct get_end_function_result {
private:
	template<typename T>
		static auto check(T& t) -> decltype(end(t));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X&>()));
};

template<typename X>
using End_function_result = typename get_end_function_result<X>::type;

template<typename X>
struct has_end_function : substitution_succeeded<typename get_end_function_result<X>::type>
{ };

template<typename X>
constexpr bool Has_end_function()
{
	return has_end_function<X>::value;
}

// Has_value_type<>()

template<typename X>
struct get_iterator_value_type_result {
private:
	template<typename T>
		static Iterator_value_type<T> check(T t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Iterator_value_type_result = typename get_iterator_value_type_result<X>::type;

template<typename X>
struct has_iterator_value_type : substitution_succeeded<typename get_iterator_value_type_result<X>::type>
{ };

template<typename X>
constexpr bool Has_iterator_value_type()
{
	return has_iterator_value_type<X>::value;
}

// Has_iterator_category<>()

template<typename X>
struct get_iterator_category_result {
private:
	template<typename T>
		static Iterator_category<T> check(T t);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<X>()));
};

template<typename X>
using Iterator_category_result = typename get_iterator_category_result<X>::type;

template<typename X>
struct has_iterator_category : substitution_succeeded<typename get_iterator_category_result<X>::type>
{ };

template<typename X>
constexpr bool Has_iterator_category()
{
	return has_iterator_category<X>::value;
}


// Boolean<T>()

template<typename X>
constexpr bool Boolean()
{
	return std::is_convertible<X,bool>();
}

// Common<>()

template<typename X, typename Y>
constexpr bool Common()
{
	return Has_common_type<X,Y>()
		&& Is_convertible<X,Common_type_result<X,Y>>()
		&& Is_convertible<Y,Common_type_result<X,Y>>();
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
	return Is_destructible<X>()
		&& Is_default_constructible<X>()
		&& Is_move_constructible<X>()
		&& Is_move_assignable<X>()
		&& Is_copy_constructible<X>()
		&& Is_copy_assignable<X>();
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
	return Common<X,Y>()
			&& Equality_comparable<X>()
			&& Equality_comparable<Y>()
			&& Equality_comparable<Common_type_result<X,Y>>()
			&& Has_less<X,Y>() && Boolean<Less_result<X,Y>>()
			&& Has_less<Y,X>() && Boolean<Less_result<Y,X>>()
			&& Has_greater<X,Y>() && Boolean<Greater_result<X,Y>>()
			&& Has_greater<Y,X>() && Boolean<Greater_result<Y,X>>()
			&& Has_less_equal<X,Y>() && Boolean<Less_equal_result<X,Y>>()
			&& Has_less_equal<Y,X>() && Boolean<Less_equal_result<Y,X>>()
			&& Has_greater_equal<X,Y>() && Boolean<Greater_equal_result<X,Y>>()
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
	return Has_output<X>() && Has_input<X>();
}

// Predicate<>()

template<typename F, typename X>
constexpr bool Predicate()
{
	return Has_call<F,X>();
}

// Movable<>()

template<typename X>
constexpr bool Movable()
{
	return Is_destructible<X>()
		&& Is_move_constructible<X>()
		&& Is_move_assignable<X>()
		&& Has_address<X>();
}

// Copyable<>()

template<typename X>
constexpr bool Copyable()
{
	return Movable<X>()
		&& Is_copy_constructible<X>()
		&& Is_copy_assignable<X>();
}

// iterator

// Common_iterator<Iter>()

template<typename Iter>
constexpr bool Common_iterator()
{
	return Has_iterator_value_type<Iter>()
		&& Has_iterator_category<Iter>()
		&& Is_copy_constructible<Iter>() && Is_copy_assignable<Iter>()
		&& Has_dereference<Iter>()
		&& Has_pre_increment<Iter>();
}

// Input_iterator<Iter>()

template<typename Iter>
constexpr bool Input_iterator()
{
	return Common_iterator<Iter>()
		&& Is_convertible<Iterator_category_result<Iter>, std::input_iterator_tag>()
		&& Has_equal<Iter>() && Has_not_equal<Iter>()
		&& Is_convertible<Dereference_result<Iter>,Iterator_value_type_result<Iter>>();
}

// Output_iterator<Iter>()

// Value_type_result<> returns void for output_iterator !!!
template<typename Iter, typename Val>
constexpr bool Output_iterator()
{
	return Common_iterator<Iter>()
		&& Is_convertible<Iterator_category_result<Iter>, std::output_iterator_tag>()
		&& Is_assignable<Dereference_result<Iter>,Val>();
}

// Forward_iterator<Iter>()

template<typename Iter>
constexpr bool Forward_const_iterator()
{
	return Input_iterator<Iter>()
		&& (!Is_class<Iterator_value_type_result<Iter>>() || Has_arrow<Iter>())
		&& Is_convertible<Iterator_category_result<Iter>, std::forward_iterator_tag>();
}

template<typename Iter>
constexpr bool Forward_iterator()
{
	return Forward_const_iterator<Iter>()
		&& Is_assignable<Dereference_result<Iter>,Iterator_value_type_result<Iter>>();
}

// Bidirectional_iterator<Iter>()

template<typename Iter>
constexpr bool Bidirectional_const_iterator()
{
	return Forward_const_iterator<Iter>()
		&& Is_convertible<Iterator_category_result<Iter>, std::bidirectional_iterator_tag>()
		&& Has_pre_decrement<Iter>();
}

template<typename Iter>
constexpr bool Bidirectional_iterator()
{
	return Bidirectional_const_iterator<Iter>()
		&& Is_assignable<Dereference_result<Iter>,Iterator_value_type_result<Iter>>();
}

// Random_access_iterator<Iter>()

template<typename Iter>
constexpr bool Random_access_const_iterator()
{
	return Bidirectional_const_iterator<Iter>()
		&& Is_convertible<Iterator_category_result<Iter>, std::bidirectional_iterator_tag>()
		&& Has_index<Iter,int>()
		&& Has_plus_assign<Iter,int>() && Has_minus_assign<Iter,int>()
		&& Has_plus<Iter,int>() && Has_minus<Iter,int>()
		&& Has_less<Iter>() && Has_less_equal<Iter>()
		&& Has_greater<Iter>() && Has_greater_equal<Iter>();
}

template<typename Iter>
constexpr bool Random_access_iterator()
{
	return Random_access_const_iterator<Iter>()
		&& Is_assignable<Dereference_result<Iter>,Iterator_value_type_result<Iter>>()
		&& Is_assignable<Index_result<Iter,int>,Iterator_value_type_result<Iter>>();
}


// Range<>()

template<typename X>
constexpr bool Range()
{
	return (Has_begin_member<X>() && Input_iterator<Begin_member_result<X>>()
			&& Has_end_member<X>() && Input_iterator<End_member_result<X>>())
		|| (Has_begin_function<X>() && Input_iterator<Begin_function_result<X>>()
			&& Has_end_function<X>() && Input_iterator<End_function_result<X>>());
}

// Sortable<Iter>()
//	2016.11.27 add: 32.2.1. sequence

template<typename Iter>
constexpr bool Sortable()
{
	return Random_access_iterator<Iter>();
}

}
#endif /* CONCEPT_H_ */
