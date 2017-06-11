/*
 * accumulate.h
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */

#ifndef ACCUMULATE_H_
#define ACCUMULATE_H_

#include <iostream>

template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val s)
{
	std::cout << "-- accumulate<Iter,Val>(Iter,Iter,Val) --\n";

	while (first!=last) {
		s = s + *first;
		++first;
	}
	return s;
}

template<typename Iter, typename Val, typename Oper>
Val accumulate(Iter first, Iter last, Val s, Oper op)
{
	std::cout << "-- accumulate<Iter,Val,Oper>(Iter,Iter,Val,Oper) --\n";

	while (first!=last) {
		s = op(s,*first);
		++first;
	}
	return s;
}



#endif /* ACCUMULATE_H_ */
