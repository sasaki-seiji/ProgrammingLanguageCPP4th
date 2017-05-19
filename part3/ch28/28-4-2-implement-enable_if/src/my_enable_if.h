/*
 * my_enable_if.h
 *
 *  Created on: 2017/05/20
 *      Author: sasaki
 */

#ifndef MY_ENABLE_IF_H_
#define MY_ENABLE_IF_H_

template<bool B, typename T = void>
struct my_enable_if {
	typedef T type;
};

template<typename T>
struct my_enable_if<false,T> { };

template<bool B, typename T =void>
using My_enable_if = typename my_enable_if<B,T>::type;



#endif /* MY_ENABLE_IF_H_ */
