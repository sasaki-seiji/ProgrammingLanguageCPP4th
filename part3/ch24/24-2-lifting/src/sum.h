/*
 * sum.h
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */

#ifndef SUM_H_
#define SUM_H_

#include <iostream>

template<typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
	std::cout << "-- sum<Iter,Val>(Iter,Iter) --\n";

	Val s = 0;
	while (first!=last) {
		s = s + *first;
		++first;
	}
	return s;
}




#endif /* SUM_H_ */
