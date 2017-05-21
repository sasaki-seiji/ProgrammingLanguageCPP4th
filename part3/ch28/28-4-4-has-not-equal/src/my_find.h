/*
 * find.h
 *
 *  Created on: 2017/05/17
 *      Author: sasaki
 */

#ifndef MY_FIND_H_
#define MY_FIND_H_

#include "has_not_equal.h"
#include "type_converter.h" // Enable_if
using namespace Estd;
//#include <type_traits>

#if 0
template<bool B, typename T=void>
using Enable_if = typename std::enable_if<B,T>::type;
#endif

#include <iostream>

template<typename Iter, typename Val>
Enable_if<Has_not_equal<Iter>(),Iter> my_find(Iter first, Iter last, Val v)
{
	std::cout << "my_find(): use !=\n";
	while (first!=last && !(*first==v))
		++first;
	return first;
}

template<typename Iter, typename Val>
Enable_if<!Has_not_equal<Iter>(),Iter> my_find(Iter first, Iter last, Val v)
{
	std::cout << "my_find(): not use !=\n";
	while (!(first==last) && !(*first==v))
		++first;
	return first;
}




#endif /* MY_FIND_H_ */
