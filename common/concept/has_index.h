/*
 * has_index.h
 *
 *  Created on: 2017/06/18
 *      Author: sasaki
 */

#ifndef HAS_INDEX_H_
#define HAS_INDEX_H_

#include "substitution_failure.h"

namespace Estd {

// x[y] : has_index

template<typename T, typename U>
struct get_index_result {
private:
	template<typename X, typename Y>
		static auto check(const X& x, const Y& y) -> decltype(x[y]);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>(),std::declval<U>()));
};

template<typename T, typename U>
struct has_index : substitution_succeeded<typename get_index_result<T,U>::type>
{ };

template<typename T, typename U>
constexpr bool Has_index()
{
	return has_index<T,U>::value;
}

template<typename T, typename U>
using Index_result = typename get_index_result<T,U>::type;


} // end of Estd






#endif /* HAS_INDEX_H_ */
