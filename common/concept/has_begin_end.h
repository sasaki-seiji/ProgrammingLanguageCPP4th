/*
 * has_begin_end.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef HAS_BEGIN_END_H_
#define HAS_BEGIN_END_H_

#include "substitution_failure.h"

namespace Estd {

// x.begin() : member_begin

template<typename T>
struct get_member_begin_result {
	template<typename X>
		static auto check(X x) -> decltype(x.begin());
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_member_begin
		: substitution_succeeded<typename get_member_begin_result<T>::type>
{ };

template<typename T>
constexpr bool Has_member_begin()
{
	return has_member_begin<T>::value;
}

template<typename T>
using Member_begin_result = typename get_member_begin_result<T>::type;


// x.end() : member_end

template<typename T>
struct get_member_end_result {
	template<typename X>
		static auto check(X x) -> decltype(x.end());
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_member_end
		: substitution_succeeded<typename get_member_end_result<T>::type>
{ };

template<typename T>
constexpr bool Has_member_end()
{
	return has_member_end<T>::value;
}

template<typename T>
using Member_end_result = typename get_member_end_result<T>::type;


// begin(x) : global_begin

template<typename T>
struct get_global_begin_result {
	template<typename X>
		static auto check(X x) -> decltype(begin(x));
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_global_begin
		: substitution_succeeded<typename get_global_begin_result<T>::type>
{ };

template<typename T>
constexpr bool Has_global_begin()
{
	return has_global_begin<T>::value;
}

template<typename T>
using Global_begin_result = typename get_global_begin_result<T>::type;


// end(x) : global_end

template<typename T>
struct get_global_end_result {
	template<typename X>
		static auto check(X x) -> decltype(end(x));
	static substitution_failure check(...);

	using type = decltype(check(std::declval<T>()));
};

template<typename T>
struct has_global_end
		: substitution_succeeded<typename get_global_end_result<T>::type>
{ };

template<typename T>
constexpr bool Has_global_end()
{
	return has_global_end<T>::value;
}

template<typename T>
using Global_end_result = typename get_global_end_result<T>::type;


} // end of Estd


#endif /* HAS_BEGIN_END_H_ */
