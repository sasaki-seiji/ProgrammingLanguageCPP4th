/*
 * etypetraits.h
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#ifndef ETYPETRAITS_H_
#define ETYPETRAITS_H_


#include <type_traits>

namespace Estd {

template<bool B, typename T =void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename X, typename Y>
constexpr bool Convertible()
{
	return std::is_convertible<X,Y>::value;
}


}

#endif /* ETYPETRAITS_H_ */
