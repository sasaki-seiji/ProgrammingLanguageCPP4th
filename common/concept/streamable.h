/*
 * streamable.h
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */

#ifndef STREAMABLE_H_
#define STREAMABLE_H_

#include "has_stream_operator.h"

namespace Estd {

template<typename T>
constexpr bool Input_streamable()
{
	return Has_streamin<T>();
}

template<typename T>
constexpr bool Output_streamable()
{
	return Has_streamout<T>();
}

template<typename T>
constexpr bool Streamable()
{
	return Input_streamable<T>() && Output_streamable<T>();
}

}


#endif /* STREAMABLE_H_ */
