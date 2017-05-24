/*
 * select.h
 *
 *  Created on: 2017/05/24
 *      Author: sasaki
 */

#ifndef SELECT_H_
#define SELECT_H_

// 28.3.1.3

namespace Estd {

template<unsigned N, typename... Cases>
struct select;

template<unsigned N, typename T, typename... Cases>
struct select<N,T,Cases...> : select<N-1,Cases...> {
};

template<typename T, typename... Cases>
struct select<0,T,Cases...> {
	using type = T;
};

template<unsigned N, typename... Cases>
using Select = typename select<N,Cases...>::type;

}



#endif /* SELECT_H_ */
