/*
 * has_call.h
 *
 *  Created on: 2017/06/24
 *      Author: sasaki
 */

#ifndef HAS_CALL_H_
#define HAS_CALL_H_


#include "substitution_failure.h"

namespace Estd {

// F(X) : has_call

template<typename T, typename U>
struct get_call_result {
private:
	template<typename X, typename Y>
		static auto check(X x, const Y& y) -> decltype(x(y));
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_call
	: substitution_succeeded<typename get_call_result<T,U>::type>
{ };

template<typename T, typename U=T>
constexpr bool Has_call()
{
	return has_call<T,U>::value;
}

template<typename T, typename U=T>
using Call_result = typename get_call_result<T,U>::type;


} // end of Estd





#endif /* HAS_CALL_H_ */
