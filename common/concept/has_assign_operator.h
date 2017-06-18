/*
 * has_assign_operator.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef HAS_ASSIGN_OPERATOR_H_
#define HAS_ASSIGN_OPERATOR_H_


#include "substitution_failure.h"

namespace Estd {

// += : has_addassign

template<typename T, typename U>
struct get_addassign_result {
private:
	template<typename X, typename Y>
		static auto check(X x, const Y& y) -> decltype(x+=y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_addassign : substitution_succeeded<typename get_addassign_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_addassign()
{
	return has_addassign<T,U>::value;
}

template<typename T, typename U=T>
using Addassign_result = typename get_addassign_result<T,U>::type;


// -= : has_subassign

template<typename T, typename U>
struct get_subassign_result {
private:
	template<typename X, typename Y>
		static auto check(X x, const Y& y) -> decltype(x-=y);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_subassign : substitution_succeeded<typename get_subassign_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_subassign()
{
	return has_subassign<T,U>::value;
}

template<typename T, typename U=T>
using Not_subassign_result = typename get_subassign_result<T,U>::type;

} // end of Estd




#endif /* HAS_ASSIGN_OPERATOR_H_ */
