/*
 * my_find.h
 *
 *  Created on: 2017/05/17
 *      Author: sasaki
 */

#ifndef MY_FIND_H_
#define MY_FIND_H_

#include <iostream>

template<typename Iter, typename Val>
Iter my_find(Iter first, Iter last, Val v)
{
	std::cout << "find(Iter,Iter)\n";

	while (first!=last && !(*first==v))
		++first;
	return first;
}





#endif /* MY_FIND_H_ */
